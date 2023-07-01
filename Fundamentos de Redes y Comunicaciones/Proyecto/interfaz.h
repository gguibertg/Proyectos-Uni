/*
 * interfaz.h
 *
 * Autor: Gabriel Fernando Guiberteau Garcia
 * Grupo 8 --> Jueves 08:30 - 10:00 h
 * 
 */

#ifndef _INTERFAZ_H
#define _INTERFAZ_H

#include <iostream>
#include "stdio_ext.h"
#include "linkLayer.h"

void listarInterfaces(pcap_if_t *avail_ifaces);

void seleccionarInterfaz(pcap_if_t *avail_ifaces, char *&nombreInterfaz);

void imprimirMACInterface(interface_t *iface, char *nombreInterfaz);

void elegirGrupo(unsigned char tipo[2]);

int elegirModo();

void imprimirMAC(unsigned char MAC[6]);

void enviarCaracter(interface_t *iface, char caracter, unsigned char MAC_Origen[6], unsigned char MAC_Destino[6], unsigned char tipo[2]);

void recibirCaracter(interface_t *iface, unsigned char tipo[2]);

void envioInteractivo(interface_t *iface,  unsigned char MAC_Aux[6], unsigned char tipo[2]);

#endif /* _INTERFAZ_H */