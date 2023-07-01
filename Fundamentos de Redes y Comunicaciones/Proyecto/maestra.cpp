/*
 * maestra.cpp
 *
 * Autor: Gabriel Fernando Guiberteau Garcia
 * Grupo 8 --> Jueves 08:30 - 10:00 h
 * 
 */

#include "maestra.h"        

using namespace std;

void descubrirEsclava(interface_t *iface, unsigned char tipo[2]){

     tipo[1] = 1; 
     unsigned char MAC_dst[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

     unsigned char *trama = BuildHeader(iface->MACaddr, MAC_dst, tipo);
     SendFrame(iface, trama, 0);

     free(trama); // Porque BuildHeader utiliza malloc

     tipo[1] = 0;
     
}

void bucleEsperaMaestra(interface_t *iface, unsigned char tipo[2], unsigned char MAC_Aux[6]){

     bool enc = false;
     apacket_t trama;

     cout << "Esperando que se una la estación esclava" << endl;

     while (!enc){
        
         trama = ReceiveFrame(iface);
         if(trama.packet != NULL){

             if(trama.packet[12] == tipo[0] && trama.packet[13] == 2){

                 cout << "Estación encontrada. ";
                 enc = true;

             }

         }

     }
     
     for (int i = 0; i < 6; i++){
         
         MAC_Aux[i] = trama.packet[i + 6];

     }
     
}

void seleccionOpcionesMaestra(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]){

     bool salir = false;
     unsigned char tecla;

     __fpurge(stdin); // Para limpiar buffer

     while (!salir){

         cout << "Selección de opción: " << endl;
         cout << "  [F1] Envío de caracteres interactivo" << endl;
         cout << "  [F2] Envío de fichero" << endl;
         cout << "  [F3] Protocolo paro y espera" << endl;
         cout << "  [ESC] Salir" << endl;
         printf("\n");
             
         tecla = getch();
         if(tecla == 27){

             if(kbhit()){

                 tecla = getch();
                 if(tecla = 'O'){

                     tecla = getch(); 
                     switch (tecla){

                         case 'P':

                             envioInteractivo(iface, MAC_Dst, tipo);
                             break;

                         case 'Q':

                             enviarFichero(iface, MAC_Dst, tipo);
                             break;

                         case 'R':

                             paroEsperaMaestra(iface, MAC_Dst, tipo);
                             break;

                         default:

                             cout << "Error, por favor introduzca una opción válida" << endl;
                             printf("\n");
                             break;

                     }

                 }

             }else{ 
                    
                 salir = true;
                     
             }

         }

     }
    
}

void enviarFichero(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]){

     ifstream fEnt;
     char cadena[255];
     unsigned char cad[255];

     fEnt.open("Fenvio.txt");
     if(fEnt.is_open()){

         while (!fEnt.eof()){

             fEnt.read(cadena,254);
             cadena[fEnt.gcount()] = '\0';
             if(fEnt.gcount() > 0){

                 strcpy((char*)cad, cadena);

                 unsigned char *trama = BuildFrame(iface->MACaddr, MAC_Dst, tipo, cad);
                 SendFrame(iface, trama, fEnt.gcount());

                 free(trama);

             }

         }

         fEnt.close();
         cout << "Fichero enviado" << endl;
         printf("\n");
         
     }else{
         cout << "Error de apertura del fichero Fenvio.txt" << endl;
     }

}

void paroEsperaMaestra(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]){

     unsigned char tecla;
     bool salir = false;

     while(!salir){

         cout << "Protocolo paro y espera." << endl;
         cout << "Seleccione el tipo de operación:" << endl;
         cout << "  [1] Operación de selección" << endl;
         cout << "  [2] Operación de sondeo" << endl;
         cout << "  [ESC] Salir" << endl;
         printf("\n");

         tecla = getch();

         if(tecla == 27){

             if(kbhit()){

                 cout << "Error, por favor introduzca una opción válida" << endl;
                 printf("\n");

             }else{

                 salir = true;

             }

         }else{

             switch (tecla){

                 case '1':

                     seleccionMaestra(iface, MAC_Dst, tipo);
                     break;

                 case '2':
                 
                     sondeoMaestra(iface, MAC_Dst, tipo);
                     break;
             
             default:

                 cout << "Error, por favor introduzca una opción válida" << endl;
                 break;

             }

         } 

     }

}

void seleccionMaestra(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]){

     //Establecimiento

     ENQ(iface, MAC_Dst, tipo, 'R');

     recibirTrama(iface, tipo);
     printf("\n");

     // Transferencia

     ifstream fEnt;
     char *Datos = (char *) malloc(255 * sizeof(char));
     int Long = 0;
     int BCE;
     char nTrama = '1';
     
     fEnt.open("EProtoc.txt");
     if(fEnt.is_open()){

         while(!fEnt.eof()){

             fEnt.read(Datos, 254);
             Long = fEnt.gcount();
             if( Long > 0){

                 Datos[Long] = '\0';
                 BCE = 0;

                 for(int i = 0; i < Long; i ++){

                     BCE = BCE xor Datos[i];

                 }

                 if(nTrama == '1'){

                     nTrama = '0';

                 }else{

                     nTrama = '1';

                 }

                 STX(iface, MAC_Dst, tipo, 'R', nTrama, Datos, Long, BCE);

                 recibirTrama(iface, tipo);
                 
             }

         }

         printf("\n");

         free(Datos);
         
         fEnt.close();

     }else{
          
         cout << "Error de apertura del fichero Eprotoc.txt" << endl;
         
     }

     // Liberación

     EOT(iface, MAC_Dst, tipo, 'R', '0');

     recibirTrama(iface, tipo);

     printf("\n");
     cout << "Fin de Selección por parte del Maestro" << endl;
     printf("\n");

}

void sondeoMaestra(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]){

     //Establecimiento

     ENQ(iface, MAC_Dst, tipo, 'T');

     recibirTrama(iface, tipo);
     printf("\n");

     ofstream fSal;
     bool enc = false;
     apacket_t frame;
     int n, BCE, cierre;

     fSal.open("RProtoc.txt");
     if(fSal.is_open()){

          while(!enc){

             frame = ReceiveFrame(iface);
             if(frame.packet != NULL){

                 if(frame.packet[12] == tipo[0] && frame.packet[13] == 0){

                     if(frame.packet[15] == 2){

                         n = frame.packet[17];
                         BCE = 0;

                         for(int i = 18; i < n + 18; i++){

                             fSal << frame.packet[i];
                             BCE = BCE xor frame.packet[i]; 

                         }

                         cout << "  R  " << frame.packet[14] << "  STX  " << frame.packet[16] << " ";
                         printf("%d  %d\n", frame.packet[18 + n], BCE);

                         if(frame.packet[18 + n] == BCE){

                             ACK(iface, MAC_Dst, tipo, 'R', frame.packet[16]);

                         }else{

                             NACK(iface, MAC_Dst, tipo, 'R', frame.packet[16]);

                         }

                     }else{

                         if(frame.packet[15] == 4){

                             printf("\n");
                             cout << "  R  " << frame.packet[14] << "  EOT  " << frame.packet[16] << endl;
                             printf("\n");
                       
                             cout << "¿Acepta el cierre de la comunicación?:" << endl;
                             cout << "  [1] Sí" << endl;
                             cout << "  [2] No" << endl;
                             cin >> cierre;

                         if(cierre == 1){
                            
                             ACK(iface, MAC_Dst, tipo, 'T', frame.packet[16]);
                             enc = true;
                         }

                         if(cierre == 2){

                             NACK(iface, MAC_Dst, tipo, 'T', frame.packet[16]);
                             
                         }

                     }

                 }

             }

         }

     }

     fSal.close();

     printf("\n");
     cout << "Fin de Sondeo por parte del Maestro" << endl;
     printf("\n");

     }else{

         cout << "Error de creacion del fichero RProtoc.txt" << endl;

     }

}