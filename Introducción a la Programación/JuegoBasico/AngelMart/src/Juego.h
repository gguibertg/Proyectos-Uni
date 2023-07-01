/*
 * Juego.h
 *
 *  Created on: 2 ene. 2018
 *      Author: Carlos Garcia Garay y Gabriel Fernando Guiberteau Garcia
 */

#include "Tablero.h"
#include "entorno.h"
#include  <cstdlib>
#ifndef JUEGO_H_
#define JUEGO_H_


struct juego{
	tablero tabler;
	int puntuacion;
	int tamanotablero;
	int tiempoJugada;
	int puntosRestar;
};
//0()
//PRE:
//POST:devuelve true si CargarConfiguracionEntorno se ha realizado correctamente y false en caso contrario
bool iniciar (juego &ju);
//0()
//PRE:el juego debe haberse iniciado correctamente
//POST:gestiona toda la interfaz del juego.
void gestion (juego &ju);
//0()
//PRE:el juego debe haberse iniciado correctamente
//POST:finaliza el juego e imprime en pantalla un mensaje de despedida
void terminar (juego &ju);

#endif /* JUEGO_H_ */
