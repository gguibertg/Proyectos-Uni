/*
 * tramas.h
 *
 * Autor: Gabriel Fernando Guiberteau Garcia
 * Grupo 8 --> Jueves 08:30 - 10:00 h
 * 
 */

#ifndef _TRAMA_H
#define _TRAMA_H

#include <iostream>
#include "linkLayer.h"

void ENQ(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2], char direccion);

void EOT(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2], char direccion, char nTrama);

void ACK(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2], char direccion, char nTrama);

void NACK(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2], char direccion, char nTrama);

void STX(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2], char direccion, char nTrama, char Datos[255], int Long, int BCE);

void recibirTrama(interface_t *iface, unsigned char tipo[2]);


#endif /* _TRAMA_H */