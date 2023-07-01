/*
 * Barrio.cpp
 *
 *  Created on: 20 mar. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#include "Barrio.h"

#include "arbol.h"
Barrio::Barrio() {

	nombreBarrio = "";
	area = 0.0;
	perimetro = 0.0;
	code = 0;
	distrito = "";

	aVias = NULL;

}

Barrio::Barrio(string nombreBarrio, float area, float perimetro, int code,
		string distrito) {

	this->nombreBarrio = nombreBarrio;
	this->area = area;
	this->perimetro = perimetro;
	this->code = code;
	this->distrito = distrito;

	aVias = NULL;

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

	cout << "El Barrio es: " << this->nombreBarrio << " " << this->area << " "
			<< this->perimetro << " " << this->code << " " << this->distrito
			<< endl;

	if (aVias != NULL) {
		cout << "Y sus Vias son" << " ";
		this->mostrarPreOrden(aVias);
	}
}

void Barrio::mostrarPreOrden(arbol<Via*, Compare>*aAux) {

	arbol<Via*, Compare>*bAux;
	Via*vAux;

	if (!aAux->vacio()) {
		vAux = aAux->raiz();
		cout << vAux->getNombreVia() << " ";
		bAux = aAux->hijoIzq();
		if (bAux != NULL) {
			mostrarPreOrden(bAux);
		}
		bAux = aAux->hijoDer();
		if (bAux != NULL) {
			mostrarPreOrden(bAux);
		}
	}
}

void Barrio::insertarVia(Via*v) {

	if (aVias == NULL) {
		aVias = new arbol<Via*, Compare>;
	}
	aVias->insertar(v);
}

bool Barrio::buscarViaPorCode(int code, Via*& v) {

	v = NULL;
	bool enc = false;

	if (aVias != NULL) {
		buscarViaPorCodeR(code, v, this->aVias, enc);
	}

	return enc;

}

void Barrio::buscarViaPorCodeR(int code, Via*& v, arbol<Via*, Compare>* aV,
		bool &enc) {

	if (!aV->vacio()) {

		if (aV->raiz()->getCode() == code) {
			enc = true;
			v = aV->raiz();
		} else {
			if (aV->hijoIzq() != NULL) {
				buscarViaPorCodeR(code, v, aV->hijoIzq(), enc);
			}
			if (aV->hijoDer() != NULL) {
				buscarViaPorCodeR(code, v, aV->hijoDer(), enc);
			}
		}
	}
}

bool Barrio::buscarViaPorNombre(string nom, Via*& v) {

	v = NULL;
	bool enc = false;

	if (aVias != NULL) {
		enc = buscarViaPorNombreR(nom, v, this->aVias);
	}

	return enc;

}

bool Barrio::buscarViaPorNombreR(string nom, Via*& v,
		arbol<Via*, Compare>* aV) {

	bool enc;

	if (aV != NULL) {
		v = aV->raiz();
		if (v->getNombreVia() == nom) {
			v = aV->raiz();
			enc = true;
		} else {
			if (v->getNombreVia() > nom) {
				if (aV->hijoIzq() != NULL) {
					enc = buscarViaPorNombreR(nom, v, aV->hijoIzq());
				}
			} else {
				if (v->getNombreVia() < nom) {
					if (aV->hijoDer() != NULL) {
						enc = buscarViaPorNombreR(nom, v, aV->hijoDer());
					}
				}

			}
		}
	}
	return enc;

}

void Barrio::algoritmo2(string especie, ofstream &fSal, int &tA) {

	Via* v;
	if (aVias != NULL) {
		algoritmo2R(especie, aVias, v, fSal, tA);

	}
}

void Barrio::algoritmo2R(string especie, arbol<Via*, Compare>* aV, Via* &v,
		ofstream &fSal, int &tA) {

	int cont = 0;

	if (!aV->vacio()) {
		if (aV->hijoIzq() != NULL) {
			algoritmo2R(especie, aV->hijoIzq(), v, fSal, tA);
		}

		v = aV->raiz();
		if (v->tieneEspecie(especie) == true) {
			cont = v->cuantosArbolesEspecie(especie);
			fSal << v->getNombreVia() << " " << cont << endl;
			tA = tA + cont;
		}

		if (aV->hijoDer() != NULL) {
			algoritmo2R(especie, aV->hijoDer(), v, fSal, tA);
		}
	}

}

void Barrio::algoritmo3(string gen, arbol<Via*, Compare>* &aAux) {

	Via* v;

	if (aVias != NULL) {
		algoritmo3R(gen, v, this->aVias, aAux);
	}
}

void Barrio::algoritmo3R(string gen, Via*& v, arbol<Via*, Compare>* aV,
		arbol<Via*, Compare>* &aAux) {

	if (!aV->vacio() && aV != NULL) {
		v = aV->raiz();
		if (v->algoritmo3(gen) == true) {
			v = aV->raiz();
			aAux->insertar(v);
			cout << v->getNombreVia() << " " << "del Barrio:" << " "
					<< this->getNombreBarrio() << endl;
		}

		if (aV->hijoIzq() != NULL) {
			algoritmo3R(gen, v, aV->hijoIzq(), aAux);
		}
		if (aV->hijoDer() != NULL) {
			algoritmo3R(gen, v, aV->hijoDer(), aAux);

		}
	}
}

void Barrio::algoritmo4(string subCadena, ofstream &fSal) {

	arbol<Via*, Compare>*aAux;
	aAux = NULL;

	if (aVias != NULL) {
		aAux = this->viasEmpiezanPor(aVias, subCadena);
		if (aAux != NULL) {
			filtroInOrden(aAux, subCadena, fSal, this->getNombreBarrio());
		}
	}
}

arbol<Via*, Compare>* Barrio::viasEmpiezanPor(arbol<Via*, Compare>* aV,
		string subCadena) {

	arbol<Via*, Compare>*aAux = NULL;
	Via* v;

	if (aV != NULL) {
		v = aV->raiz();
		if (v->getNombreVia().find(subCadena) == 0) {
			aAux = aV;
		} else if (subCadena < v->getNombreVia()) {
			aAux = viasEmpiezanPor(aV->hijoIzq(), subCadena);
		} else if (subCadena > v->getNombreVia()) {
			aAux = viasEmpiezanPor(aV->hijoDer(), subCadena);
		}

	}
	return aAux;
}

void Barrio::filtroInOrden(arbol<Via*, Compare>* aV, string subCadena,
		ofstream &fSal, string nB) {

	Via* v;

	if (!aV->vacio()) {
		if (aV->hijoIzq() != NULL) {
			filtroInOrden(aV->hijoIzq(), subCadena, fSal, nB);
		}

		v = aV->raiz();

		if (v->getNombreVia().find(subCadena) == 0)
			aV->raiz()->algoritmo4(fSal, nB);
		if (aV->hijoDer() != NULL) {
			filtroInOrden(aV->hijoDer(), subCadena, fSal, nB);
		}
	}
}

Barrio::~Barrio() {

	Via *v;

	if (aVias != NULL) {
		while (!aVias->vacio()) {
			v = aVias->raiz();
			aVias->borrar(v);
			delete v;
		}
		delete aVias;
	}

}

