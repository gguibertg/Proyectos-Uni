/*
 * ConjuntoBarrios.cpp
 *
 *  Created on: 20 mar. 2019
 *      Author: goblinl
 */

#include "ConjuntoBarrios.h"

ConjuntoBarrios::ConjuntoBarrios() {

	cont = 0;

}

void ConjuntoBarrios::insertar(Barrio *b) {

	int i=0, j;
	bool enc = false;
	Barrio*bAux;

	if (vacio()) {
		cjtB[0] = b;
		cont++;
	} else {

		while (i < cont && !enc) {
			obtenerPorPos(i, bAux);
			if (bAux->getCode() > b->getCode()) {
				enc = true;
			} else {
				i++;
			}
		}
		if (enc) {
			for (j = cont; j > i; j--) {
				cjtB[j] = cjtB[j - 1];

			}
		}
	cjtB[i] = b;
				cont++;
	}
}
void ConjuntoBarrios::borrar(string clave) {

	int i, j, cAux;
	bool enc = false;

	for (i = 0; i < cont && !enc; i++) {
		cAux = cjtB[i]->getCode();
		if (atoi(clave.c_str()) == cAux) {
			enc = true;
			cont--;
			for (j = i; j < cont; j++) {
				cjtB[j] = cjtB[j + 1];
			}

		}
	}

}

void ConjuntoBarrios::obtenerPorPos(int pos, Barrio *&b) {

	b = cjtB[pos];

}

void ConjuntoBarrios::obtenerPorClave(string clave, Barrio *&b) {

	int i, cB;
	bool enc = false;

	for (i = 0; i < cont && !enc; i++) {
		cB = cjtB[i]->getCode();
		if (atoi(clave.c_str()) == cB) {
			enc = true;
			b = cjtB[i];
		}
	}

}

bool ConjuntoBarrios::existe(string clave) {

	bool existe = false;
	int i, cB;

	for (i = 0; i < cont && !existe; i++) {
		cB = cjtB[i]->getCode();
		if (atoi(clave.c_str()) == cB) {
			existe = true;
		}
	}
	return existe;
}

int ConjuntoBarrios::cuantos() {

	return cont;

}

bool ConjuntoBarrios::vacio() {

	bool vacio = false;

	if (cont == 0) {
		vacio = true;
	}
	return vacio;
}

ConjuntoBarrios::~ConjuntoBarrios() {

	for (int i = 0; i < cont; i++)
		delete cjtB[i];

}

