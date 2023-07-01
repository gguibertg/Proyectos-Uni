/*
 * esclava.cpp
 *
 * Autor: Gabriel Fernando Guiberteau Garcia
 * Grupo 8 --> Jueves 08:30 - 10:00 h
 * 
 */

#include "esclava.h" 

using namespace std;

void bucleEsperaEsclava(interface_t *iface, unsigned char tipo[2], unsigned char MAC_Aux[6]){

    bool enc = false;
    apacket_t trama;

    cout << "Esperando que se una la estación maestra" << endl;

    while(!enc){

         trama = ReceiveFrame(iface);
         if(trama.packet != NULL){

             if(trama.packet[12] == tipo[0] && trama.packet[13] == 1){

                 cout << "Estación encontrada. ";
                 enc = true;

             }

         }

     }
     
     for(int i = 0; i < 6; i++){

         MAC_Aux[i] = trama.packet[i + 6];

     }
     
}

void contestarMaestra(interface_t *iface, unsigned char tipo[2], unsigned char MAC_Aux[6]){

     tipo[1] = 2;

     unsigned char *trama = BuildHeader(iface->MACaddr, MAC_Aux, tipo);
     SendFrame(iface, trama, 0);

     free(trama); // Porque BuildHeader utiliza malloc

     tipo[1] = 0;

}

void seleccionOpcionesEsclava(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]){

     bool salir = false;
     unsigned char tecla;

     while (!salir){

         printf("\n");
         cout << "Selección de modo:" << endl;
         cout << "  [F1] - Envío de caracteres interactivo" << endl;
         cout << "  [F3] Protocolo paro y espera" << endl;
         cout << "  [ESC] - Salir" << endl;
         printf("\n");
         
         while (tecla != 27){

             recibirCaracter(iface, tipo);

             if(kbhit()){

                 tecla = getch();

             }

         }  

         if(tecla == 27){

             if(kbhit()){

                 tecla = getch();
                 if(tecla == 'O'){

                     tecla = getch();
                     switch (tecla){

                         case 'P':

                             envioInteractivo(iface, MAC_Dst, tipo);
                             break;

                         case 'R':

                             paroEsperaEsclava(iface, MAC_Dst, tipo);
                             break;

                         default:

                             cout << "Error, por favor introduzca una opción válida" << endl;
                             break;

                     }

                 }

             }else{

                 salir = true;

             }

         }

     }

}

void paroEsperaEsclava(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]){

     bool enc = false;
     apacket_t trama;
     
     printf("\n");
     cout << " Protocolo paro y espera" << endl;
     cout << "Estás en modo esclavo" << endl;
     printf("\n");

     while (!enc){

         trama = ReceiveFrame(iface);
         if(trama.packet != NULL){

             if(trama.packet[12] == tipo[0] && trama.packet[13] == 0){

                 if(trama.packet[15] == 5){

                     cout << "  R  " << trama.packet[14] << "  ENQ  " << trama.packet[16] << endl;
                     enc = true;

                 }

             }

         }
       
     }

     if(trama.packet[14] == 'R'){

         seleccionEsclava(iface, MAC_Dst, tipo);

     } 

     if(trama.packet[14] == 'T'){

         sondeoEsclava(iface, MAC_Dst, tipo);

     }

}

void seleccionEsclava(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]){

     ofstream fSal;
     apacket_t frame;
     bool enc = false;
     int n, BCE;

     ACK(iface, MAC_Dst, tipo, 'R', '0');
     printf("\n");

     fSal.open("RProtoc.txt");
     if(fSal.is_open()){

         while (!enc){
            
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

                             ACK(iface, MAC_Dst, tipo, 'R', '0');

                             enc = true;

                         }

                     }

                 }

             }

         }

         fSal.close();
         
         printf("\n");
         cout << "Fin de Selección por parte del Esclavo" << endl;
         printf("\n");

     }else{

         cout << "Error de creacion del fichero RProtoc.txt" << endl;

     }


}

void sondeoEsclava(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]){

     apacket_t frame;
     bool enc = false;

     ACK(iface, MAC_Dst, tipo, 'T', '0');
     printf("\n");

     // Transferencia

     ifstream fEnt;
     char nTrama = '1';
     char *Datos = (char *) malloc(255 * sizeof(char));
     int Long = 0;
     int BCE;
     
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
                 
                 STX(iface, MAC_Dst, tipo, 'T', nTrama, Datos, Long, BCE);

                 recibirTrama(iface, tipo);

             }

         }

         printf("\n");

         free(Datos);
         
         fEnt.close();

     }else{
          
         cout << "Error de apertura del fichero EProtoc.txt" << endl;

     }

     //Liberacion

     bool salir = false;
     nTrama = '1'; 

     while (!salir){

         if(nTrama == '1'){

             nTrama = '0';

         }else{

             nTrama = '1';

         }

         EOT(iface, MAC_Dst, tipo, 'T', nTrama);

         enc = false;

         while(!enc){

             frame = ReceiveFrame(iface);
             if(frame.packet != NULL){

                 if(frame.packet[12] == tipo[0] && frame.packet[13] == 0){

                     if(frame.packet[15] == 6){

                         cout << "  R  " << frame.packet[14] << "  ACK  " << frame.packet[16] << endl;
                         printf("\n");
                         enc = true;
                         salir = true;

                     }

                     if(frame.packet[15] == 21){

                         cout << "  R  " << frame.packet[14] << "  NACK  " << frame.packet[16] << endl;
                         printf("\n");
                         enc = true;

                     }

                 }

             }
         
         }  

     } 

     printf("\n");
     cout << "Fin de Sondeo por parte del Esclavo" << endl;

}