/*
 * Via.cpp
 *
 *  Created on: 20 mar. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#include "Via.h"

Via::Via() {

	codeBarrio = 0;
	nombreVia = "";
	longitud = 0.0;
	tipoVia = "";
	code = 0;

	lA = NULL;

}

Via::Via(int codigoBarrio, string nombreVia, float longitud, string tipoVia,
		int code) {

	this->codeBarrio = codigoBarrio;
	this->nombreVia = nombreVia;
	this->longitud = longitud;
	this->tipoVia = tipoVia;
	this->code = code;

	lA = NULL;

}

void Via::setCodeBarrio(int codeBarrio) {

	this->codeBarrio = codeBarrio;

}

int Via::getCodeBarrio() const {

	return codeBarrio;

}

void Via::setNombreVia(string nombreVia) {

	this->nombreVia = nombreVia;

}

string Via::getNombreVia() const {

	return nombreVia;

}

void Via::setLongitud(float longitud) {

	this->longitud = longitud;

}

float Via::getLongitud() const {

	return longitud;

}

void Via::setTipoVia(string tipoVia) {

	this->tipoVia = tipoVia;

}

string Via::getTipoVia() const {

	return tipoVia;

}

void Via::setCode(int code) {

	this->code = code;

}

int Via::getCode() const {

	return code;

}

void Via::mostrar() {

	Arbol*a;

	cout << this->codeBarrio << "  " << this->nombreVia << " " << this->longitud
			<< " " << this->tipoVia << " " << this->code << endl;

	if (lA != NULL) {
		cout << "Sus arboles son: ";
		lA->moverInicio();
		while (!lA->finLista()) {
			lA->consultar(a);
			a->mostrar();
			lA->avanzar();
		}
	} else {
		cout << "Esta via no tiene árboles" << endl;
	}
}

void Via::insertarArbol(Arbol*a) {

	if (lA == NULL) {
		lA = new ListaPI<Arbol*>;
	}

	lA->insertar(a);

}

void Via::algoritmo1() {

	ofstream fSal;
	Arbol* a;
	string cad1, cad2, cad3, cad4;

	cad1 = "ArbolesDe";
	cad2 = this->nombreVia;
	cad3 = ".txt";
	cad4 = cad1 + cad2 + cad3;

	int tA = 0;

	if (lA != NULL) {
		lA->moverInicio();
		fSal.open(cad4.c_str());
		if (fSal.is_open()) {
			while (!lA->finLista()) {
				lA->consultar(a);
				fSal << "La especie es : " << a->getEspecie()
						<< " La familia es: "

						<< a->getFamilia() << " El nombre es: "
						<< a->getNombre() << " El genero es: " << a->getGenero()
						<< " El diametro es: " << " La altura es: "
						<< a->getAltura() << " La copa es: " << a->getCopa()
						<< " El riego es: " << a->getRiego()
						<< " Las unidades son: " << " El codigo de la via es: "
						<< a->getCodeVia() << endl;
				tA = tA + a->getUnidades();
				lA->avanzar();
			}
		} else {
			cout << "Error crear fichero algoritmo1" << endl;
		}

		fSal << "El total de arboles es: " << tA << endl;

		fSal.close();
	}
}

bool Via::tieneEspecie(string especie) {

	bool enc = false;
	Arbol *a;

	if (lA != NULL) {
		lA->moverInicio();
		while (!lA->finLista() && !enc) {
			lA->consultar(a);
			if (a->getEspecie() == especie) {
				enc = true;

			}
			lA->avanzar();
		}
	}
	return enc;

}

int Via::cuantosArbolesEspecie(string especie) {

	Arbol *a;
	int cont = 0;

	if (lA != NULL) {
		lA->moverInicio();
		while (!lA->finLista()) {
			lA->consultar(a);
			if (a->getEspecie() == especie) {
				cont = cont + a->getUnidades();
			}
			lA->avanzar();
		}
	}
	return cont;

}

bool Via::algoritmo3(string genero) {

	bool enc;
	Arbol *a;

	if (lA != NULL) {
		lA->moverInicio();
		while (!lA->finLista() && !enc) {
			lA->consultar(a);
			if (a->getGenero() == genero) {
				enc = true;
			}
			lA->avanzar();
		}
	}
	return enc;

}

void Via::algoritmo4(ofstream &fSal, string nB) {

	int cont = 0;
	Arbol* a;

	if (lA != NULL) {
		fSal << this->nombreVia << " " << "del Barrio" << nB << " ";
		lA->moverInicio();
		while (!lA->finLista()) {
			lA->consultar(a);
			cont = cont + a->getUnidades();
			lA->avanzar();
		}
		fSal << "Numero de arboles: " << cont << endl;
	}
}

Via::~Via() {

	Arbol*a;

	if (lA != NULL) {
		lA->moverInicio();
		while (!lA->finLista()) {
			lA->consultar(a);
			delete a;
			lA->borrar();
		}
	}
}

