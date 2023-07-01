/*
 * PruebasArbol.cpp
 *
 *  Created on: 26 abr. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#include "Arbol.h"

void pruebasArbol() {

	cout << "Inicio PruebasArbol" << endl;

	Arbol*a1;

	a1 = new Arbol("Ent", "Aceraceae", "Barbol", "ACER", 1, 2, 3, "MANUAL", 4,
			06001);

	if (a1->getEspecie() != "Ent") {
		cout << "Error constructor parametrizado especie" << endl;
	}
	if (a1->getFamilia() != "Aceraceae") {
		cout << "Error constructor parametrizado familia" << endl;
	}
	if (a1->getNombre() != "Barbol") {
		cout << "Error constructor parametrizado nombre" << endl;
	}
	if (a1->getGenero() != "ACER") {
		cout << "Error constructor parametrizado genero" << endl;
	}
	if (a1->getDiametro() != 1) {
		cout << "Error constructor parametrizado diametro" << endl;
	}
	if (a1->getAltura() != 2) {
		cout << "Error constructor parametrizado altura" << endl;
	}
	if (a1->getCopa() != 3) {
		cout << "Error constructor parametrizado copa" << endl;
	}
	if (a1->getRiego() != "MANUAL") {
		cout << "Error constructor parametrizado riego" << endl;
	}
	if (a1->getUnidades() != 4) {
		cout << "Error constructor parametrizado unidades" << endl;
	}
	if (a1->getCodeVia() != 06001) {
		cout << "Error constructor parametrizado codeVia" << endl;
	}

	delete a1;

	Arbol*a2;

	a2 = new Arbol();

	a2->setEspecie("Acer_sacharinum");
	a2->setFamilia("Aceraceae");
	a2->setNombre("ARCE PLATEADO");
	a2->setGenero("ACER");
	a2->setDiametro(9);
	a2->setAltura(8);
	a2->setCopa(7);
	a2->setRiego("NO RIEGO");
	a2->setUnidades(6);
	a2->setCodeVia(54321);

	if (a2->getEspecie() != "Acer_sacharinum") {
		cout << "Error set/get Especie" << endl;
	}
	if (a2->getFamilia() != "Aceraceae") {
		cout << "Error set/get Familia" << endl;
	}
	if (a2->getNombre() != "ARCE PLATEADO") {
		cout << "Error set/get Nombre" << endl;
	}
	if (a2->getGenero() != "ACER") {
		cout << "Error set/get Genero" << endl;
	}
	if (a2->getDiametro() != 9) {
		cout << "Error set/get Diametro" << endl;
	}
	if (a2->getAltura() != 8) {
		cout << "Error set/get Altura" << endl;
	}
	if (a2->getCopa() != 7) {
		cout << "Error set/get Copa" << endl;
	}
	if (a2->getRiego() != "NO RIEGO") {
		cout << "Error set/get Riego" << endl;
	}
	if (a2->getUnidades() != 6) {
		cout << "Error set/get Unidades" << endl;
	}
	if (a2->getCodeVia() != 54321) {
		cout << "Error set/get CodeVia" << endl;
	}

	delete a2;

	cout << "Fin PruebasArbol" << endl;

}
//
//int main() {
//
//	pruebasArbol();
//
//}
