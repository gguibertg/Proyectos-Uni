/*
 * Algoritmos.cpp
 *
 *  Created on: 02/03/2019
 *      Author: Profesores de EDI
 */

#include "algoritmos.h"

int main() {

	Algoritmos Algoritmos;

}

// ******************** PRIVATE Ovoid Algoritmos::cargarDatos() {PERATIONS ********************

void Algoritmos::run() {

	string nV, especie;

	mostrarBarrios();

	cout << "Introduzca el nombre de la via deseado" << endl;
	getline(cin, nV);

	algoritmo1("De Portugal");

	algoritmo2("Celtis_australis");

	algoritmo3("ACACIA");

	algoritmo4("A");

}

void Algoritmos::cargarDatos() {

	ifstream fEnt;
	string cad[10], clave;
	int i;
	Barrio*bAux;
	Via *via;
	bool enc;

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
				cjtB->insertar(b);
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
				cjtB->obtenerPorClave(cad[0], bAux);
				bAux->insertarVia(v);
			}
		}
		fEnt.close();
	} else {
		cout << "Error al abrir el fichero Via.csv" << endl;
	}

	fEnt.open("Arbol.csv");

	if (fEnt.is_open()) {
		getline(fEnt, cad[0]);
		while (!fEnt.eof()) {
			for (i = 0; i < 9; i++) {
				getline(fEnt, cad[i], ';');
			}
			getline(fEnt, cad[9]);
			if (!fEnt.eof()) {
				Arbol*a = new Arbol(cad[0], cad[1], cad[2], cad[3],
						atof(cad[4].c_str()), atof(cad[5].c_str()),
						atof(cad[6].c_str()), cad[7], atoi(cad[8].c_str()),
						atoi(cad[9].c_str()));
				int code = atoi(cad[9].c_str());
				enc = false;
				for (i = 0; i < cjtB->cuantos() && !enc; i++) {
					cjtB->obtenerPorPos(i, bAux);
					enc = bAux->buscarViaPorCode(code, via);
				}
				if (enc) {
					via->insertarArbol(a);
				}
			}
		}
		fEnt.close();
	} else {
		cout << "Error al abrir el fichero Arbol.csv" << endl;
	}
	cout << "Carga de datos Finalizada" << endl;
}

// ******************** PUBLIC INTERFACE ********************

Algoritmos::Algoritmos() {

	cout << "Programming Project v3.00 (EDI)." << endl;
	cout << "           Author: xx xx xx." << endl;
	cout << "           Date:   April 3th, 2019." << endl;

	cjtB = new ConjuntoBarrios();
	this->cargarDatos();
	this->run();

}

void Algoritmos::mostrarBarrios() {

	Barrio*b;
	int i;

	for (i = 0; i < cjtB->cuantos(); i++) {
		cjtB->obtenerPorPos(i, b);
		b->mostrar();
	}
}

void Algoritmos::algoritmo1(string nv) {

	bool enc = false;
	int i = 0;
	Barrio* b;
	Via* v;

	while (!enc && i < cjtB->cuantos()) {
		cjtB->obtenerPorPos(i, b);
		enc = b->buscarViaPorNombre(nv, v);
		i++;
	}
	v->algoritmo1();
}

void Algoritmos::algoritmo2(string especie) {

	int i = 0;
	ofstream fSal;
	Barrio* b;
	string cad1, cad2, cad3;
	int tA = 0;

	cad1 = "Especie";
	cad2 = ".txt";
	cad3 = cad1 + especie + cad2;

	fSal.open(cad3.c_str());
	if (fSal.is_open()) {
		for (i = 0; i < cjtB->cuantos(); i++) {
			cjtB->obtenerPorPos(i, b);
			b->algoritmo2(especie, fSal, tA);
		}
	} else {
		cout << "Error crear fichero algoritmo2" << endl;
	}

	fSal << "Total árboles: " << tA << endl;

	fSal.close();

}

void Algoritmos::algoritmo3(string genero) {

	int i = 0;
	Barrio* b;
	arbol<Via*, Compare>* aAux;

	aAux = new arbol<Via*, Compare>;
	for (i = 0; i < cjtB->cuantos(); i++) {
		cjtB->obtenerPorPos(i, b);
		b->algoritmo3(genero, aAux);
	}
	recorrerArbol(aAux);

}

void Algoritmos::recorrerArbol(arbol<Via*, Compare>* aV) {

	if (aV != NULL) {
		recorrerArbolR(aV);
	}

}

void Algoritmos::recorrerArbolR(arbol<Via*, Compare>* aV) {

	Via *v;
	Barrio *b;
	bool enc;
	int i = 0;

	if (!aV->vacio()) {
		v = aV->raiz();
		for (i = 0; i < cjtB->cuantos() && !enc; i++) {
			cjtB->obtenerPorPos(i, b);
			if (v->getCodeBarrio() == b->getCode()) {
				enc = true;
			}
		}
		cout << v->getNombreVia() << "      " << "Barrio:" << " "
				<< b->getNombreBarrio() << endl;
		if (aV->hijoIzq() != NULL) {
			recorrerArbolR(aV->hijoIzq());
		}
		if (aV->hijoDer() != NULL) {
			recorrerArbolR(aV->hijoDer());
		}
	}

}

void Algoritmos::algoritmo4(string cad) {

	int i = 0;
	Barrio* b;
	ofstream fSal;
	string cad1, cad2, cad3;

	cad1 = "EmpiezanPor";
	cad2 = ".txt";
	cad3 = cad1 + cad + cad2;

	fSal.open(cad3.c_str());
	if (fSal.is_open()) {
		for (i = 0; i < cjtB->cuantos(); i++) {
			cjtB->obtenerPorPos(i, b);
			if (b->getNombreBarrio().find(cad) == 0) {
				b->algoritmo4(cad, fSal);
			}
		}

	} else {
		cout << "Error crear fichero algoritmo4" << endl;
	}
	fSal.close();

}

Algoritmos::~Algoritmos() {

	delete cjtB;

}

