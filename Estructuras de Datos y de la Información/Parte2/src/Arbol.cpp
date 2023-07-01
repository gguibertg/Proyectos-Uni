/*
 * Arbol.cpp
 *
 *  Created on: 14 abr. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#include "Arbol.h"

Arbol::Arbol() {

	especie = "";
	familia = "";
	nombre = "";
	genero = "";
	diametro = 0.0;
	altura = 0.0;
	copa = 0.0;
	riego = "";
	unidades = 0;
	codeVia = 0;

}

Arbol::Arbol(string especie, string familia, string nombre, string genero,
		float diametro, float altura, float copa, string riego, int unidades,
		int codeVia) {

	this->especie = especie;
	this->familia = familia;
	this->nombre = nombre;
	this->genero = genero;
	this->diametro = diametro;
	this->altura = altura;
	this->copa = copa;
	this->riego = riego;
	this->unidades = unidades;
	this->codeVia = codeVia;

}

void Arbol::setEspecie(string especie) {

	this->especie = especie;

}

string Arbol::getEspecie() const {

	return especie;

}

void Arbol::setFamilia(string familia) {

	this->familia = familia;

}

string Arbol::getFamilia() const {

	return familia;

}

void Arbol::setNombre(string nombre) {

	this->nombre = nombre;

}

string Arbol::getNombre() const {

	return nombre;

}

void Arbol::setGenero(string genero) {

	this->genero = genero;

}

string Arbol::getGenero() const {

	return genero;

}

void Arbol::setDiametro(float diametro) {

	this->diametro = diametro;

}

float Arbol::getDiametro() const {

	return diametro;

}

void Arbol::setAltura(float altura) {

	this->altura = altura;

}

float Arbol::getAltura() const {

	return altura;

}

void Arbol::setCopa(float copa) {

	this->copa = copa;

}

float Arbol::getCopa() const {

	return copa;

}

void Arbol::setRiego(string riego) {

	this->riego = riego;

}

string Arbol::getRiego() const {

	return riego;

}

void Arbol::setUnidades(int unidades) {

	this->unidades = unidades;

}

int Arbol::getUnidades() const {

	return unidades;

}

void Arbol::setCodeVia(int codeVia) {

	this->codeVia = codeVia;

}

int Arbol::getCodeVia() const {

	return codeVia;

}

void Arbol::mostrar() {

	cout << "La especie es : " << this->especie << " La familia es: "

	<< this->familia << " El nombre es: " << this->nombre << " El genero es: "
			<< this->genero << " El diametro es: " << " La altura es: "
			<< this->altura << " La copa es: " << this->copa << " El riego es: "
			<< this->riego << " Las unidades son: "
			<< " El codigo de la via es: " << this->codeVia << endl;

}

Arbol::~Arbol() {
// TODO Auto-generated destructor stub
}

