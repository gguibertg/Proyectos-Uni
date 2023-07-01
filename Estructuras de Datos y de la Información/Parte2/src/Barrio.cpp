/*
 * Barrio.cpp
 *
 *  Created on: 20 mar. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#include "Barrio.h"
#include <fstream>
using namespace std;

Barrio::Barrio() {

	nombreBarrio = "";
	area = 0.0;
	perimetro = 0.0;
	code = 0;
	distrito = "";

	lV = NULL;

}

Barrio::Barrio(string nombreBarrio, float area, float perimetro, int code,
		string distrito) {

	this->nombreBarrio = nombreBarrio;
	this->area = area;
	this->perimetro = perimetro;
	this->code = code;
	this->distrito = distrito;

	lV = NULL;

}

void Barrio::setNombreBarrio(string nombreBarrio) {

	this->nombreBarrio = nombreBarrio;

}

string Barrio::getNombreBarrio() const {

	return nombreBarrio;

}

void Barrio::setArea(float area) {

	this->area = area;

}

float Barrio::getArea() const {

	return area;

}

void Barrio::setPerimetro(float perimetro) {

	this->perimetro = perimetro;

}

float Barrio::getPerimetro() const {

	return perimetro;

}

void Barrio::setCode(int code) {

	this->code = code;

}

int Barrio::getCode() const {

	return code;

}

void Barrio::setDistrito(string distrito) {

	this->distrito = distrito;

}

string Barrio::getDistrito() const {

	return distrito;

}

void Barrio::mostrar() {

	Via*v;

	cout << "El Barrio es: " << this->nombreBarrio << " " << this->area << " "
			<< this->perimetro << " " << this->code << " " << this->distrito
			<< endl;

	if (lV != NULL) {
		cout << "Y sus Vias son: ";
		lV->moverInicio();
		while (!lV->finLista()) {
			lV->consultar(v);
			v->mostrar();
			lV->avanzar();
		}
	} else {
		cout << "Este barrio no tiene vías" << endl;
	}
}

void Barrio::insertarVia(Via*v) {

	bool enc = false;
	Via*vAux;

	if (lV == NULL) {
		lV = new ListaPI<Via*>;
	}

	lV->moverInicio();
	while (!lV->finLista() && !enc) {
		lV->consultar(vAux);
		if (vAux->getNombreVia() > v->getNombreVia()) {
			enc = true;
		} else {
			lV->avanzar();
		}
	}
	lV->insertar(v);
}

bool Barrio::buscarVia(int code, Via *&v) {

	bool enc = false;

	if (lV != NULL) {
		if (!lV->estaVacia()) {
			lV->moverInicio();
			while (!lV->finLista() && !enc) {
				lV->consultar(v);
				if (code == v->getCode()) {
					enc = true;
				} else {
					lV->avanzar();
				}
			}
		}
	}
	return enc;
}

bool Barrio::buscarVPorNombre(string nV) {

	Via *v;
	bool enc = false;

	if (lV != NULL) {
		lV->moverInicio();
		while (!lV->finLista() && !enc) {
			lV->consultar(v);
			if (v->getNombreVia() == nV) {
				enc = true;
				v->algoritmo1(nV);
			} else {
				lV->avanzar();
			}
		}
	}
	return enc;
}

void Barrio::algoritmo3(ListaPI<Arbol*>*&lAux) {

	Via*v;

	if (lV != NULL) {
		lV->moverInicio();
		while (!lV->finLista()) {
			lV->consultar(v);
			v->algoritmo3(lAux);
			lV->avanzar();
		}
	}
}

int Barrio::algoritmo4() {

	Via *v;
	int total = 0;

	if (lV != NULL) {
		lV->moverInicio();
		while (!lV->finLista()) {
			lV->consultar(v);
			total = total + v->algoritmo4();
			lV->avanzar();
		}
	}
	return total;
}

void Barrio::algoritmo2(Cola<Arbol*>*&c,string genero) {
	Via *v;

	if (lV != NULL) {
		lV->moverInicio();
		while (!lV->finLista()) {
			lV->consultar(v);
            v->algoritmo2(c, genero);
			lV->avanzar();
		}
	}
}

Barrio::~Barrio() {

	Via*v;

	if (lV != NULL) {
		lV->moverInicio();
		while (!lV->finLista()) {
			lV->consultar(v);
			delete v;
			lV->borrar();
		}
	}
}

