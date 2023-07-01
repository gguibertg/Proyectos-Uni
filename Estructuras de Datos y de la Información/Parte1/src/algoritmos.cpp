/*
 * Algoritmos.cpp
 *
 *  Created on: 02/03/2019
 *      Author: Profesores de EDI
 */

#include <fstream>
#include <iostream>

#include "algoritmos.h"

using namespace std;

// MAIN function
int main() {
	Algoritmos Algoritmos;
}

// ******************** PRIVATE OPERATIONS ********************

void Algoritmos::run() {

	Barrio *a;
	Barrio *b;

	// TODO invovar a todos los algoritmos para que se ejecuten secuencialemente

	//mostrarBarrios();

	// Algoritmo 1

	 algoritmo1("Campus Universitario");

	// Algoritmo 2

	algoritmo2(a,b);

	cout << "El barrio con menos calles es " << a->getNombreBarrio() << endl;
	cout << "El barrio con mas calles es " << b->getNombreBarrio() << endl;

	// Algoritmo 3

	 algoritmo3("El");

	// Algoritmo 4

	 algoritmo4();
}

void Algoritmos::cargarDatos() {

	ifstream fEnt;
	string cad[5], clave;
	int i;
	Barrio*bAux;

	fEnt.open("Barrio.csv");

	if (fEnt.is_open()) {
		getline(fEnt, cad[0]);
		while (!fEnt.eof()) {
			for (i = 0; i < 4; i++) {
				getline(fEnt, cad[i], ';');
			}
			getline(fEnt, cad[4]);
			if (!fEnt.eof()) {
				Barrio *b = new Barrio(cad[0], atof(cad[1].c_str()),
						atof(cad[2].c_str()), atoi(cad[3].c_str()), cad[4]);
				cjtoB->insertar(b);
			}
		}
		fEnt.close();
	} else {
		cout << "Error al abrir el fichero Barrio.csv" << endl;
	}

	fEnt.open("Via.csv");
	if (fEnt.is_open()) {
		getline(fEnt, cad[0]);
		while (!fEnt.eof()) {
			for (i = 0; i < 4; i++) {
				getline(fEnt, cad[i], ';');
			}
			getline(fEnt, cad[4]);
			if (!fEnt.eof()) {

				Via*v = new Via(atoi(cad[0].c_str()), cad[1],
						atof(cad[2].c_str()), cad[3], atoi(cad[4].c_str()));
				clave = v->getCodeBarrio();
				cjtoB->obtenerPorClave(cad[0], bAux);
				bAux->insertarVia(v);
			}
		}
	} else {
		cout << "Error al abrir el fichero Via.csv" << endl;
	}

}
// ******************** PUBLIC INTERFACE ********************

Algoritmos::Algoritmos() {

	cout << "Programming Project v1.00 (EDI)." << endl;
	cout << "           Author: xx xx xx." << endl;
	cout << "           Date:   March 8th, 2019." << endl;

	cjtoB = new ConjuntoBarrios();
	this->cargarDatos();
	this->run();
}

void Algoritmos::mostrarBarrios() {

	int i;
	Barrio *b;

	for (i = 0; i < cjtoB->cuantos(); i++) {
		cjtoB->obtenerPorPos(i, b);
		b->mostrar();
	}

}

void Algoritmos::algoritmo1(string barrio) {
	Barrio *b;
	int i;
	bool enc = false;
	for (i = 0; i < cjtoB->cuantos() && !enc; i++) {
		cjtoB->obtenerPorPos(i, b);
		if (b->getNombreBarrio() == barrio) {
			b->escribirVs(barrio);

		}
	}
}


void Algoritmos::algoritmo2(Barrio*& a, Barrio*& b)  {

	Barrio *aux;
	int i;
	cjtoB->obtenerPorPos(0, a);
	cjtoB->obtenerPorPos(1, b);
	if (cjtoB !=NULL) {
		for (i = 0; i < cjtoB->cuantos(); i++) {
			cjtoB->obtenerPorPos(i, aux);
		if (aux->numeroV() < a->numeroV()) {
				a = aux;
			}
			if (aux->numeroV() > b->numeroV()) {
				b = aux;
			}
		}

	}
}


void Algoritmos::algoritmo3(string subcadena) {

	int i;
	Barrio *b;
	int pos;

	for (i = 0; i < cjtoB->cuantos(); i++) {
		cjtoB->obtenerPorPos(i, b);
		pos = b->getNombreBarrio().find(subcadena);
		if (pos == 0) {
			cout << "El Barrio es: " << b->getNombreBarrio()
					<< " y sus vias son: " << endl;
			b->algoritmo3(subcadena);
		}
	}

}

void Algoritmos::algoritmo4() {

	float mayor = 0.0;
	Barrio*b;
	int i;
	Via*v;
	for (i = 0; i < cjtoB->cuantos(); i++) {
		cjtoB->obtenerPorPos(i, b);
		b->algoritmo4(v,mayor);
		mayor = b->algoritmo4(v,mayor);
	}

	cout << "La via es: " << v->getNombreVia() << "Su distrito es: " << b->getDistrito() << endl;
}


Algoritmos::~Algoritmos() {

// Complete memory deallocation

	delete cjtoB;
}

