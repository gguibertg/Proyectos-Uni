/*
 * ConjuntoVias.cpp
 *
 *  Created on: 20 mar. 2019
 *      Author: goblinl
 */

#include "ConjuntoVias.h"

ConjuntoVias::ConjuntoVias() {

	cont = 0;

}

void ConjuntoVias::insertar(Via *v) {

	int i = 0, j;
	bool enc = false;
	Via*v1;
	int codB, codV;
	string clave, claveAux;

	if (vacio()) {
		cjtV[0] = v;
		cont++;

	} else {

		codB = v->getCodeBarrio();
		codV = v->getCode();
		clave = to_string(codB) + to_string(codV);

		while (i < cont && !enc) {

			obtenerPorPos(i, v1);
			codB = v1->getCodeBarrio();
			codV = v1->getCode();
			claveAux = to_string(codB) + to_string(codV);
			if (claveAux > clave)
				enc = true;
			else
				i++;
		}

		if (enc) {
			for (j = cont; j > i; j--) {

				cjtV[j] = cjtV[j - 1];


			}

		}
	cjtV[i] = v;
				cont++;
}}
void ConjuntoVias::borrar(string clave) {

	int i, j;
	string key;
	bool enc = false;

	for (i = 0; i < cont && !enc; i++) {
		key = to_string(cjtV[i]->getCodeBarrio())
				+ to_string(cjtV[i]->getCode());
		if (clave == key) {
			enc = true;
			cont--;
			for (j = i; j < cont; j++) {
				cjtV[j] = cjtV[j + 1];
			}
		}

	}

}

void ConjuntoVias::obtenerPorPos(int pos, Via *&v) {

	v = cjtV[pos];

}

void ConjuntoVias::obtenerPorClave(string clave, Via *&v) {

	string cl;
	int i;
	bool enc;

	for (i = 0; i < cont && !enc; i++) {
		cl = to_string(cjtV[i]->getCodeBarrio())
				+ to_string(cjtV[i]->getCode());
		if (clave == cl) {
			enc = true;
			v = cjtV[i];
		}
	}
}

bool ConjuntoVias::existe(string clave) {

	bool existe = false;
	string key;
	int i;

	for (i = 0; i < cont && !existe; i++) {
		key = to_string(cjtV[i]->getCodeBarrio())
				+ to_string(cjtV[i]->getCode());

		if (clave == key) {
			existe = true;
		}
	}
	return existe;
}

int ConjuntoVias::cuantos() {

	return cont;

}

bool ConjuntoVias::vacio() {

	bool vacio = false;

	if (cont == 0) {
		vacio = true;
	}

	return vacio;
}

ConjuntoVias::~ConjuntoVias() {

	for (int i = 0; i < cont; i++)
		delete cjtV[i];

}

