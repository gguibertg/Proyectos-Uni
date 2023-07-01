/*
 * maestra.h
 *
 * Autor: Gabriel Fernando Guiberteau Garcia
 * Grupo 8 --> Jueves 08:30 - 10:00 h
 * 
 */

#ifndef _MAESTRA_H
#define _MAESTRA_H

#include "interfaz.h"
#include "trama.h" 
#include <fstream>

void descubrirEsclava(interface_t *iface, unsigned char tipo[2]);

void bucleEsperaMaestra(interface_t *iface, unsigned char tipo[2], unsigned char MAC_Aux[6]);

void seleccionOpcionesMaestra(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]);

void enviarFichero(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]);

void paroEsperaMaestra(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]);

void seleccionMaestra(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]);

void sondeoMaestra(interface_t *iface, unsigned char MAC_Dst[6], unsigned char tipo[2]);

#endif /* _MAESTRA_H */