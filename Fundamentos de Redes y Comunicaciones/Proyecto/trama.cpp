/*
 * maestra.cpp
 *
 * Autor: Gabriel Fernando Guiberteau Garcia
 * Grupo 8 --> Jueves 08:30 - 10:00 h
 * 
 */

#include "trama.h"         

using namespace std;

void ENQ(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2], char direccion){

        unsigned char *c = (unsigned char *) malloc(3 * sizeof(char));

        c[0] = direccion;
        c[1] = 5;
        c[2] = '0';

        unsigned char *tramaControl = BuildFrame(iface->MACaddr, MAC_Dst, tipo, c);
        SendFrame(iface, tramaControl, 3);

        cout << "  E  " << c[0] << "  ENQ  " << c[2] << endl;

        free(tramaControl);
        free(c);

}

void EOT(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2], char direccion, char nTrama){

        unsigned char *c = (unsigned char *) malloc(3 * sizeof(char));

        c[0] = direccion;
        c[1] = 4;
        c[2] = nTrama;

        unsigned char *tramaControl = BuildFrame(iface->MACaddr, MAC_Dst, tipo, c);
        SendFrame(iface, tramaControl, 3);

        cout << "  E  " << c[0] << "  EOT  " << c[2] << endl;

        free(tramaControl);
        free(c);

}

void ACK(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2], char direccion, char nTrama){

        unsigned char *c = (unsigned char *) malloc(3 * sizeof(char));

        c[0] = direccion;
        c[1] = 6;
        c[2] = nTrama;

        unsigned char *tramaControl = BuildFrame(iface->MACaddr, MAC_Dst, tipo, c);
        SendFrame(iface, tramaControl, 3);

        cout << "  E  " << c[0] << "  ACK  " << c[2] << endl;

        free(tramaControl);
        free(c);

}

void NACK(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2], char direccion, char nTrama){

        unsigned char *c = (unsigned char *) malloc(3 * sizeof(char));

        c[0] = direccion;
        c[1] = 21;
        c[2] = nTrama;

        unsigned char *tramaControl = BuildFrame(iface->MACaddr, MAC_Dst, tipo, c);
        SendFrame(iface, tramaControl, 3);

        cout << "  E  " << c[0] << "  NACK  " << c[2] << endl;

        free(tramaControl);
        free(c);

}

void STX(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2], char direccion, char nTrama, char Datos[255], int Long, int BCE){

        unsigned char *d = (unsigned char *) malloc(259 * sizeof(char));

        d[0] = direccion;
        d[1] = 2;
        d[2] = nTrama;
        d[3] = Long;

        memcpy(d + 4, Datos, Long);

        d[Long + 4] = BCE;

        unsigned char *tramaControl = BuildFrame(iface->MACaddr, MAC_Dst, tipo, d);
        SendFrame(iface, tramaControl, Long + 5);

        cout << "  E  " << d[0] << "  STX  " << d[2] << "  " << BCE << endl;

        free(tramaControl);
        free(d);

}

void recibirTrama(interface_t *iface, unsigned char tipo[2]){

         bool enc = false;
         apacket_t frame;
         unsigned char control;


         while (!enc){

                 frame = ReceiveFrame(iface);
                 if(frame.packet != NULL){

                         if(frame.packet[12] == tipo[0] && frame.packet[13] == 0){

                                 unsigned char control = frame.packet[15];

                                 switch (control){

                                         case 4: 

                                                 cout << "  R  " << frame.packet[14] << "  EOT  " << frame.packet[16] << endl;
                                                 break;

                                         case 5: 

                                                 cout << "  R  " << frame.packet[14] << "  ENQ  " << frame.packet[16] << endl;
                                                 break;

                                         case 6: 

                                                 cout << "  R  " << frame.packet[14] << "  ACK  " << frame.packet[16] << endl;
                                                 break;

                                         case 21:

                                                 cout << "  R  " << frame.packet[14] << "  NACK  " << frame.packet[16] << endl;
                                                 break;
                                 
                                 }

                                 enc = true;

                         }

                 }
       
         } 

}