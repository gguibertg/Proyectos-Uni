/*
 * interfaz.cpp
 *
 * Autor: Gabriel Fernando Guiberteau Garcia
 * Grupo 8 --> Jueves 08:30 - 10:00 h
 * 
 */

#include "interfaz.h"

using namespace std;

void listarInterfaces(pcap_if_t *avail_ifaces){

         cout << "Interfaces disponibles:" << endl;

         for(int i = 0; avail_ifaces->next != NULL; i++){

                 cout << "[" << i << "] " << avail_ifaces->name << endl;
                 avail_ifaces = avail_ifaces->next;  

         }

}

void seleccionarInterfaz(pcap_if_t *avail_ifaces, char *&nombreInterfaz){

         int n,i;

         cout << "Seleccione interfaz: ";
         cin >> n;
         cout << "Interfaz Elegida: ";

         for(i = 0; i < n; i++){

                 avail_ifaces = avail_ifaces->next;

         }

         nombreInterfaz = avail_ifaces->name;

         cout << nombreInterfaz << endl;

}

void imprimirMACInterface(interface_t *iface, char *nombreInterfaz){

         setDeviceName(iface, nombreInterfaz);
         GetMACAdapter(iface);

         cout << "La MAC es: ";

         for(int i = 0; i < 5; i++){

                 printf("%X:", iface->MACaddr[i]);

         }

         printf ("%X\n", iface->MACaddr[5]);

}

void elegirGrupo(unsigned char tipo[2]){

         int grupo;

         cout << "Introduzca el número de grupo:" << endl;
         cin >> grupo;

         grupo = grupo + 48;

         tipo[0] = grupo;
         tipo[1] = 0;

}

int elegirModo(){

     int modo;   

     cout << "Puerto abierto correctamente" << endl;

     cout << "Seleccione el modo de la estación:" << endl;
     cout << "  [1] Modo Maestra" << endl;
     cout << "  [2] Modo Esclava" << endl;
     cin >> modo;

     return modo;
     
}

void imprimirMAC(unsigned char MAC[6]){

         cout << "La MAC es: ";

         for(int i = 0; i < 5; i++){

                 printf("%X:", MAC[i]);

         }

         printf("%X\n", MAC[5]);

}

void enviarCaracter(interface_t *iface, char caracter, unsigned char MAC_Origen[6], unsigned char MAC_Destino[6], unsigned char tipo[2]){

         // Reservamos memoria
         unsigned char *p = (unsigned char *) malloc(1 * sizeof(char));

         // Almacenamos el caracter
         p[0] = caracter;

         // Construimos la trama
         unsigned char * trama = BuildFrame(MAC_Origen, MAC_Destino, tipo, p);

         // Enviamos la trama (el 1 es el tamaño de datos)
         SendFrame(iface, trama, 1);

         // Liberamos memoria
         free(p);
         free(trama);

}

void recibirCaracter(interface_t *iface, unsigned char tipo[2]){

         apacket_t trama = ReceiveFrame(iface);
         int n, i, j;
         bool enc = false;

         if(trama.packet != NULL){
                 
                 if(trama.packet[12] == tipo[0] && trama.packet[13] == 0){

                         n = trama.header.len;

                         if(trama.packet[15] == '\0'){

                                 cout << "Trama recibida con 1 caracter" << endl;

                                 cout << "Recibido: " << trama.packet[14] << endl;

                         }else{

                                 if(n == 60){

                                         for(i = 14; i < n && !enc; i++){

                                                 if(trama.packet[i] == '\0'){

                                                         enc = true;

                                                 }

                                         }

                                         n = i - 1; // Para que no muestre la posición del primer '\0'

                                         j = i - 15; // Para saber el número de caracteres recibidos sin contar el relleno

                                         printf("Trama recibida con %d caracteres \n", j);

                                         for(i = 14; i < n; i++){

                                                 printf("%c", trama.packet[i]);

                                         }

                                 }else{

                                         printf("Trama recibida con %d caracteres \n", n - 14);

                                         for(i = 14; i < n; i++){

                                                 printf("%c", trama.packet[i]);

                                         }

                                 }

                                 printf("\n");

                         }

                 }
         }

}

void envioInteractivo(interface_t *iface,  unsigned char MAC_Aux[6], unsigned char tipo[2]){

         bool salir = false;
         unsigned char tecla;

         cout << "Pulse los caracteres a enviar: " << endl;

         while(!salir){

                         if(tecla == 27){

                                 if(kbhit()){

                                         __fpurge(stdin); // Para limpiar buffer
                                         tecla = 0;
                                         printf("\n Error, por favor no utilice las teclas de función \n");
                                         cout << "Pulse los caracteres a enviar: " << endl;
                                         
                                 }else{

                                         salir = true;

                                 }

                         }else{

                                 recibirCaracter(iface, tipo);

                                 if(kbhit()){

                                         tecla = getch();

                                         if(tecla != 27){

                                                 enviarCaracter(iface, tecla, iface->MACaddr, MAC_Aux, tipo);

                                         }

                                 }

                         }

         }


                

}

