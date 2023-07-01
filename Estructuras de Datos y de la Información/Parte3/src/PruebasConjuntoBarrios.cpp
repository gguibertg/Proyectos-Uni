/*
 * PruebasConjuntoBarrios.cpp
 *
 *  Created on: 22 mar. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#include "ConjuntoBarrios.h"

void pruebasConjuntoBarrios() {

	cout << "Inicio Pruebas ConjuntoBarrios" << endl;

	ConjuntoBarrios *cjtB;
	cjtB = new ConjuntoBarrios;
	Barrio *b, *bAux, *b1, *b2, *b3, *b4, *b5, *b6, *b7;

	b1 = new Barrio("Winterfell", 3500, 7000, 1, "North");
	b2 = new Barrio("Riverrun", 250, 500, 2, "Northwest");
	b3 = new Barrio("Eyrie", 500, 1000, 3, "Northeast");
	b4 = new Barrio("CasterlyRock", 1500, 3000, 4, "West");
	b5 = new Barrio("KingsLanding", 2000, 4000, 5, "East");
	b6 = new Barrio("Highgarden", 2500, 5000, 6, "Centre");
	b7 = new Barrio("Sunspear", 3000, 6000, 7, "South");

	if (!cjtB->vacio()) {
		cout << "Error del constructor" << endl;
	}

	cjtB->insertar(b1);
	cjtB->insertar(b2);
	cjtB->insertar(b3);
	cjtB->insertar(b4);
	cjtB->insertar(b5);
	cjtB->insertar(b6);
	cjtB->insertar(b7);


	if (cjtB->cuantos() != 7) {
		cout << "Error en el metodo insertar" << endl;
	}
	cjtB->borrar("4");
	if (cjtB->cuantos() != 6) {
		cout << "Error en el metodo borrar" << endl;
	}
	if (cjtB->existe("1") == false) {
		cout << "Error metodo existe" << endl;
	}
	cjtB->obtenerPorClave("7", b);
	if (b->getNombreBarrio() != b7->getNombreBarrio()) {
		cout << "Error metodo obtenerPorClave" << endl;
	}
	cjtB->obtenerPorPos(2, bAux);
	if (bAux->getNombreBarrio() != b3->getNombreBarrio()) {
		cout << "Error modulo obtenerPorPos" << endl;
	}

	delete cjtB;

	cout << "Fin Pruebas ConjuntoBarrios" << endl;
}

//int main() {
//
//	pruebasConjuntoBarrios();
//
//}
