/*
 * Via.cpp
 *
 *  Created on: 20 mar. 2019
 *      Author: goblinl
 */

#include "Via.h"

Via::Via() {

		codeBarrio = 0;
		nombreVia = "";
		longitud = 0.0;
		tipoVia = "";
		code = 0;

}

Via::Via(int codigoBarrio, string nombreVia, float longitud, string tipoVia,
		int code) {

	this->codeBarrio = codigoBarrio;
	this->nombreVia = nombreVia;
	this->longitud = longitud;
	this->tipoVia = tipoVia;
	this->code = code;

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

	cout << this->codeBarrio << "  " << this->nombreVia << " " << this->longitud
			<< " " << this->tipoVia << " " << this->code << endl;

}




Via::~Via() {
	// TODO Auto-generated destructor stub
}

