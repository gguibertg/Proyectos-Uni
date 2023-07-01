/*
 * Algoritmos.cpp
 *
 *  Created on: 02/03/2019
 *      Author: Profesores de EDI
 */

#include <fstream>
#include <iostream>

#include "algoritmos.h"
#include "cola.h"

using namespace std;

// MAIN function

int main() {

	Algoritmos Algoritmos;

}

// ******************** PRIVATE OPERATIONS ********************

void Algoritmos::run() {

	// TODO invovar a todos los algoritmos para que se ejecuten secuencialemente

	//mostrarBarrios();

	//algoritmo1("Gredos");

	// Algoritmo 2 Parte 2
algoritmo2("CATALPA");
	// Algoritmo 3 Parte 2

	//algoritmo3();

	// Algoritmo 4 Parte 2



}

void Algoritmos::cargarDatos() {

	ifstream fEnt;
	string cad[10], clave;
	int i;
	Barrio*bAux;
	Via *via;

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
				buscarVia(code, via);
				via->insertarArbol(a);
			}
		}


		/*void Via::encolarPrioridad(Cola<Arbol*>*&c, Arbol* a) {
			Cola<Arbol*>*cAux;
			cAux = new Cola<Arbol*>;
			Arbol *b;
			bool enc = false;


				if(c->vacia()) {
					c->encolar(a);
				} else {
					while (!c->vacia() && !enc) {
						c->primero(b);
						c->desencolar();
						if (a->getAltura() > b->getAltura()) {
							enc = true;
							cAux->encolar(a);
						}
						if (a->getAltura() < b->getAltura()) {
							cAux->encolar(b);

							if (a->getAltura() == b->getAltura()) {
								if (a->getCopa() > b->getCopa()) {
									enc = true;
									cAux->encolar(a);
								}
								if (a->getCopa() < b->getCopa()) {
									cAux->encolar(b);
								}
							}
						}
					}

						while (!c->vacia()) {
							c->primero(b);
							c->desencolar();
							cAux->encolar(b);
						}
						while (!cAux->vacia()) {
							cAux->primero(b);
							cAux->desencolar();
							c->encolar(b);
						}

					}*/
		fEnt.close();
	} else {
		cout << "Error al abrir el fichero Arbol.csv" << endl;
	}
}

// ******************** PUBLIC INTERFACE ********************

Algoritmos::Algoritmos() {

	cout << "Programming Project v2.00 (EDI)." << endl;
	cout << "           Author: xx xx xx." << endl;
	cout << "           Date:   April 3th, 2019." << endl;

	cjtB = new ConjuntoBarrios();
	this->cargarDatos();
	this->run();

}

void Algoritmos::buscarVia(int code, Via* &v) {

	Barrio *b;
	bool enc = false;
	int i;

	for (i = 0; i < cjtB->cuantos() && !enc; i++) {
		cjtB->obtenerPorPos(i, b);
		enc = b->buscarVia(code, v);
	}
}

void Algoritmos::mostrarBarrios() {

	int i;
	Barrio*b;

	for (i = 0; i < cjtB->cuantos(); i++) {
		cjtB->obtenerPorPos(i, b);
		b->mostrar();
	}
}

void Algoritmos::algoritmo1(string via) {

	bool enc = false;
	int i;
	Barrio *b;

	for (i = 0; i < cjtB->cuantos() && !enc; i++) {
		cjtB->obtenerPorPos(i, b);
		enc = b->buscarVPorNombre(via);
	}
}

void Algoritmos::algoritmo2(string genero) {
	int i;
	Cola<Arbol*>*c;
	c= new Cola<Arbol*>;
		Barrio *b;
		Arbol *a;
		Via *v;

		for (i = 0; i < cjtB->cuantos(); i++) {
			cjtB->obtenerPorPos(i, b);
			b->algoritmo2(c, genero);
		}
		while(!c->vacia()){
			c->primero(a);
			c->desencolar();
			buscarVia(a->getCodeVia(),v);
			cout<<a->getGenero()<<" "<<a->getAltura()<<" "<<a->getCopa()<<": "<<v->getNombreVia()<<endl;
		}
		delete c;
}

void Algoritmos::algoritmo3() {

	int i;
	Barrio*b;
	ListaPI<Arbol*>*lAux;
	lAux = new ListaPI<Arbol*>;
	Arbol*a;
	ofstream fSal;

	for (i = 0; i < cjtB->cuantos(); i++) {
		cjtB->obtenerPorPos(i, b);
		b->algoritmo3(lAux);
	}

	if (lAux != NULL) {
		fSal.open("Especies.txt");
		if (fSal.is_open()) {
			lAux->moverInicio();
			while (!lAux->finLista()) {
				lAux->consultar(a);
				fSal << "El numero de arboles de la especie " << a->getEspecie()
						<< " es " << a->getUnidades() << endl;
				lAux->avanzar();
			}
		} else {
			cout << "Error crear fichero Especies.txt" << endl;
		}

	} else {
		cout << "La lista esta vacia" << endl;
	}

	lAux->moverInicio();
	while (lAux->finLista()) {
		lAux->consultar(a);
		delete a;
		lAux->borrar();
	}

}

void Algoritmos::algoritmo4() {

	int i;
	Barrio*b;
int acum=0;
int cont=0;
	for (i = 0; i < cjtB->cuantos(); i++) {
		cjtB->obtenerPorPos(i, b);
		cont =b->algoritmo4();

		cout<<b->getNombreBarrio()<< ":"<<cont<<endl;
acum=acum+cont;

	}
	cout<<"total="<<acum<<endl;
}

Algoritmos::~Algoritmos() {

	delete cjtB;

}

