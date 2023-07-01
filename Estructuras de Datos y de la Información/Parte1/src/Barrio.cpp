/*
 * Barrio.cpp
 *
 *  Created on: 20 mar. 2019
 *      Author: goblinl
 */

#include "Barrio.h"
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

Barrio::Barrio() {

	nombreBarrio = "";
	area = 0.0;
	perimetro = 0.0;
	code = 0;
	distrito = "";

	cjtV = NULL;
}

Barrio::Barrio(string nombreBarrio, float area, float perimetro, int code,
		string distrito) {

	this->nombreBarrio = nombreBarrio;
	this->area = area;
	this->perimetro = perimetro;
	this->code = code;
	this->distrito = distrito;

	cjtV = NULL;
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

	cout << this->nombreBarrio << endl;
	cout << this->area << endl;
	cout << this->perimetro << endl;
	cout << this->code << endl;
	cout << this->distrito << endl;

}

void Barrio::insertarVia(Via*v) {

	if (cjtV == NULL) {
		cjtV = new ConjuntoVias;
	}
	cjtV->insertar(v);

}

void Barrio::escribirVs(string barrio) {
	string cad1 = "ViasDe";
	string cad2 = barrio;
	string cad3 = ".txt";
	string cad4 = cad1 + cad2 + cad3;
	ofstream fs;
	int i;
	Via *v;
	if (!cjtV->vacio()) {
		fs.open(cad4.c_str());
		for (i = 0; i < cjtV->cuantos(); i++) {
			cjtV->obtenerPorPos(i, v);
			fs << v->getNombreVia() << endl;

		}
		fs.close();
	} else {
		cout << "Éste barrio no tiene vias" << endl;
	}
}
int Barrio::numeroV() {
	if (cjtV != NULL) {
		return cjtV->cuantos();
	} else {
		return 0;
	}
}

void Barrio::algoritmo3(string subcadena) {

	int i;
	Via*v;
	int pos;

	for (i = 0; i < cjtV->cuantos(); i++) {
		cjtV->obtenerPorPos(i, v);
		pos = v->getNombreVia().find(subcadena);
		if (pos == 0) {
			cout << v->getNombreVia() << endl;
		}
	}

}

float Barrio::algoritmo4(Via*&v, float mayor) {

	int i;
	Via *vAux;
	string tipo;
	tipo = "Avda";
    if(cjtV != NULL){
	for (i = 0; i < cjtV->cuantos(); i++) {
		cjtV->obtenerPorPos(i, vAux);
		if (tipo == vAux->getTipoVia() ) {
			if (vAux->getLongitud() > mayor) {
				mayor = vAux->getLongitud();
				v = vAux;
			}
		}
		}
	}
	return mayor;

}

Barrio::~Barrio() {

	if (cjtV != NULL) {
		delete cjtV;
	}
}

