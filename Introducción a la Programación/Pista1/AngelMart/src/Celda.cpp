/*
 * Celda.cpp
 *
 *  Created on: 2 ene. 2018
 *      Author:  Carlos Garcia Garay y Gabriel Fernando Guiberteau Garcia
 */

#include "Celda.h"
#include <cstdlib>
#include "entorno.h"

void iniciarCelda(celda &c) {
	c.vacia = true;
	c.reves = true;

}

void vaciarCelda(celda &c) {
	c.vacia = true;
	c.reves = true;
}

void ponerValor(celda &c, int valor) {
	c.n = valor;
	c.vacia = false;
}

void ponerEstado(celda &c, bool estado) {
	c.reves = estado;
}

int obtenerValor(celda c) {
	return c.n;
}

bool vacia(celda c) {
	return c.vacia;
}

bool obtenerPosicion(celda c) {
	return c.reves;
}

bool compararFicha(celda c, celda b) {
	bool iguales;
	iguales = false;
	if (c.n == b.n)
		iguales = true;
	return iguales;
}
