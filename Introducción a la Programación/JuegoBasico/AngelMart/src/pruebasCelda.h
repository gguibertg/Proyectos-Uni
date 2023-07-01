/*
 * pruebasCelda.h
 *
 *  Created on: 12 ene. 2018
 *      Author: Carlos Garcia Garay y Gabriel Fernando Guiberteau Garcia
 */

#ifndef PRUEBASCELDA_H_
#define PRUEBASCELDA_H_

#include <iostream>
using namespace std;

#include "Celda.h"

/*
 * DESCRIPCION: modulo de pruebas de iniciarCelda, si la celda no se inicia correctamente da error.
 * COMPLEJIDAD:O(1)
 */

void pruebaIniciar();

/*
 * DESCRIPCION: modulo de pruebas de vaciarCelda, si la celda no se vacia correctamente, da error.
 * COMPLEJIDAD:O(1)
 */

void pruebaVaciarCelda();

/*
 * DESCRIPCION: modulo de pruebas de ponerValor, si el valor no se pone  correctamente, da error.
 * COMPLEJIDAD:O(1)
 */

void pruebaPonerValor();

/*
 * DESCRIPCION: modulo de pruebas de ponerEstado, si no se pone el estadp, da error.
 * COMPLEJIDAD:O(1)
 */

void pruebaPonerEstado();

/*
 * DESCRIPCION: modulo de pruebas de obtenerValor, si no lo devuelve correctamente, da error.
 * COMPLEJIDAD:O(1)
 */

void pruebaObtenerValor();

/*
 * DESCRIPCION: modulo d pruebas de estaVacia, si la celda llena y devuelve true, da error.
 * COMPLEJIDAD:O(1)
 */

void pruebaVacia();

/*
 * DESCRIPCION: modulo de pruebas obtenerPosicion, si no devuelve la posicion correctamente, da error.
 * COMPLEJIDAD:O(1)
 */

void pruebaObtenerPosicion();

/*
 * DESCRIPCION: modulo de pruebas Comparar, si son distintas y devuelve true , da error.
 * COMPLEJIDAD:O(1)
 */

void pruebaComparar();

/*
 * DESCRIPCION: ejecuta todos los modulos de pruebas.
 * COMPLEJIDAD:O(1)
 */

void pruebasCelda();

#endif /* PRUEBASCELDA_H_ */
