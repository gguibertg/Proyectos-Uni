/*
 * PruebasTablero.h
 *
 *  Created on: 12 ene. 2018
 *      Author:  Carlos Garcia Garay y Gabriel Fernando Guiberteau Garcia
 */

#ifndef PRUEBASTABLERO_H_
#define PRUEBASTABLERO_H_

#include <iostream>
using namespace std;

#include "Tablero.h"
#include"entorno.h"

//Pruebas del tad Tablero.

/*
 * DESCRIPCION: Modulo de prueba para iniciarTablero, iniciamos el tablero con un tamaño determinado y comprobamos
 * 				que se ha iniciado correctamente y que todas las casillas están vacías.
 * COMPLEJIDAD:O(1)
 */
void pruebaIniciarTablero();
/*
 * DESCRIPCION: Modulo de prueba para estaVacia, iniciamos el tablero, colocamos fichas y comprobamos que al
 * 				ejecutar el modulo estaVacia en la posicion en la que hemos puesto una ficha devuelva false.
 * COMPLEJIDAD:O(1)
 */
void pruebaEstaVacia();
/*
 * DESCRIPCION: Modulo de prueba para caben, iniciamos el tablero, colocamos fichas en la fila 0 y si el módulo ha de
 * 				devolver false.
 * COMPLEJIDAD:O(n)
 */
void pruebaCaben();
/*
 * DESCRIPCION:Modulo de prueba para estaVacio, iniciamos el tablero, colocamos fichas, y el modulo comprueba si esta
 * 				el tablero vacio (que es false pues hemos colocado ficha previamente) o no.
 * COMPLEJIDAD:O(n)
 */
void pruebaEstaVacio();
/*
 * DESCRIPCION:Modulo de prueba para obtenerEstado, iniciamos el tablero y colocamos una ficha y ha de devolver
 * 				su estado.
 * COMPLEJIDAD:O(1)
 */
void pruebaObtenerEstado();
/*
 * DESCRIPCION:Modulo de prueba para modificarEstado, iniciamos el tablero, colocamos una ficha y le cambiamos el estado.
 * 				Si no lo hace, da error.
 * COMPLEJIDAD:O(1)
 */
void pruebaModificarEstado();
/*
 * DESCRIPCION:Modulo de prueba para ponerFicha, iniciamos el tablero, colocamos fichas y preguntamos si la posición
 * 				en la que hemos colocado las fichas está vacía o no.
 * COMPLEJIDAD:O(1)
 */
void pruebaPonerFicha();
/*
 * DESCRIPCION:Modulo de prueba para BorrarFichas, colocamos fichas, las borramos y preguntamos si esas posiciones están
 * 				o no vacías.
 * COMPLEJIDAD:O(n)
 */
void pruebaBorrarFicha();
/*
 * DESCRIPCION:Modulo de prueba para obtenerTamano, iniciamos el tablero y nos ha de devolver el tamaño con el que
 * 				lo hemos iniciado.
 * COMPLEJIDAD:O(1)
 */
void pruebaObtenerTamano ();
/*
 * DESCRIPCION:Modulo de prueba para
 * COMPLEJIDAD:O(n)
 */
void pruebaNuevaFila();
/*
 * DESCRIPCION:Modulo de prueba para nuevaFila, iniciamos el tablero,
 * COMPLEJIDAD:O(1)
 */
void pruebasTablero();



#endif /* PRUEBASTABLERO_H_ */
