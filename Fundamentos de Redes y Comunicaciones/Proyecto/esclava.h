/*
 * esclava.h
 *
 * Autor: Gabriel Fernando Guiberteau Garcia
 * Grupo 8 --> Jueves 08:30 - 10:00 h
 * 
 */

#ifndef _ESCLAVA_H
#define _ESCLAVA_H

#include "interfaz.h"
#include "trama.h"  
#include <fstream>

void bucleEsperaEsclava(interface_t *iface, unsigned char tipo[2], unsigned char MAC_Aux[6]);

void contestarMaestra(interface_t *iface, unsigned char tipo[2], unsigned char MAC_Aux[6]);

void seleccionOpcionesEsclava(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]);

void paroEsperaEsclava(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]);

void seleccionEsclava(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]);

void sondeoEsclava(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]);

#endif /* _ESCLAVA_H */