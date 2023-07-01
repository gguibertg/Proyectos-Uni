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
void Via::algoritmo1(string nV) {

	Arbol *a;
	ofstream fSal;
	string cad1, cad2, cad3;

	cad1 = "ArbolesDe";
	cad2 = ".txt";
	cad3 = cad1 + nV + cad3;

	if (lA != NULL) {
		lA->moverInicio();
		fSal.open(cad3.c_str());
		if (fSal.is_open()) {
			while (!lA->finLista()) {
				lA->consultar(a);
				fSal << a->getNombre() << endl;
				lA->avanzar();
			}
		} else {
			cout << "Error crear fichero algoritmo1" << endl;
		}
	}
	fSal.close();
}

void Via::algoritmo3(ListaPI<Arbol*>*&lAux) {

	Arbol*a;
	bool existe = false;
	Arbol*b;
	bool enc = false;

	if (lA != NULL) {
		lA->moverInicio();
		while (!lA->finLista()) {
			lA->consultar(a);
			lAux->moverInicio();
			if (lAux == NULL) {
				lAux->insertar(a);
			} else {
				while (!lAux->finLista() && !existe) {
					lAux->consultar(b);
					if (b->getEspecie() == a->getEspecie()) {
						b->setUnidades(b->getUnidades() + a->getUnidades());
						existe = true;
					} else {
						lAux->avanzar();
					}
				}
				if (!existe && lAux != NULL) {
					lAux->moverInicio();
					while (!lAux->finLista() && !enc) {
						lAux->consultar(b);
						if (b->getEspecie() > a->getEspecie()) {
							enc = true;
						} else {
							lAux->avanzar();
						}
					}
					lAux->insertar(a);
				}
			}
			lA->avanzar();
		}
	}

}

int Via::algoritmo4() {

	int suma;
	Arbol *a;
	suma = 0;
	if (lA != NULL) {
		lA->moverInicio();
		while (!lA->finLista()) {
			lA->consultar(a);
			suma = suma + a->getUnidades();
			lA->avanzar();
		}
	}
	return suma;

}
void Via::algoritmo2(Cola<Arbol*>*& c, string genero) {
	Arbol* a;
	if (lA != NULL) {

		lA->moverInicio();
		while (!lA->finLista()) {
			lA->consultar(a);
			if (a->getGenero() == genero && a->getAltura() > 5
					&& a->getCopa() > 3) {
				encolarPrioridad(c, a);
			}
			lA->avanzar();
		}
	}
}
void Via::encolarPrioridad(Cola<Arbol*>*&c, Arbol* a) {
	Cola<Arbol*>*cAux;
	cAux = new Cola<Arbol*>;
	Arbol *b;
	bool enc = false;

	if (c->vacia()) {
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

			}
			if (a->getAltura() == b->getAltura()) {
				if (a->getCopa() > b->getCopa()) {
					enc = true;
					cAux->encolar(a);
					cAux->encolar(b);
				}
				if (a->getCopa() < b->getCopa()) {
					cAux->encolar(b);
				}
				if (a->getCopa() == b->getCopa()) {
					enc = true;
					cAux->encolar(a);
					cAux->encolar(b);
				}
			}

		}
		if (!enc) {
			cAux->encolar(a);
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

	}
}
//			c->primero(b);
//		c->desencolar();
//		if (a->getAltura() > b->getAltura()) {
//			while (!c->vacia() && !enc) {
//				c->primero(b);
//			if()
//		}
//	}
//	if (a->getAltura() < b->getAltura()) {
//		while (!c->vacia()) {
//			c->primero(b);
//			c->desencolar();
//			cAux->encolar(b)
//		}
//		cAux->encolar(a);
//	}

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

