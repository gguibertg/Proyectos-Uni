/*
 * PruebasVia.cpp
 *
 *  Created on: 22 mar. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#include "Via.h"

void pruebasVia() {

	cout << "Inicio PruebasVia" << endl;

	Via *v1;

	v1 = new Via(42, "Fake", 50, "Street", 123);

	if (v1->getCodeBarrio() != 42) {
		cout << "Error constructor parametrizado en codeBarrio" << endl;
	}
	if (v1->getNombreVia() != "Fake") {
		cout << "Error constructor parametrizado en nombreVia" << endl;
	}
	if (v1->getLongitud() != 50) {
		cout << "Error constructor parametrizado en longitud" << endl;
	}
	if (v1->getTipoVia() != "Street") {
		cout << "Error constructor parametrizado en tipoVia" << endl;
	}
	if (v1->getCode() != 123) {
		cout << "Error constructor parametrizado en code" << endl;
	}

	delete v1;

	Via *v2;

	v2 = new Via();

	v2->setCodeBarrio(06001);
	v2->setNombreVia("San Pedro de Alcantara");
	v2->setLongitud(192);
	v2->setTipoVia("Calle");
	v2->setCode(23);

	if (v2->getCodeBarrio() != 06001) {
		cout << "Error en el metodo setCodeBarrio" << endl;
	}
	if (v2->getNombreVia() != "San Pedro de Alcantara") {
		cout << "Error en el metodo setNombreVia" << endl;
	}
	if (v2->getLongitud() != 192) {
		cout << "Error en el metodo setLongitud" << endl;
	}
	if (v2->getTipoVia() != "Calle") {
		cout << "Error en el metodo setTipoVia" << endl;
	}
	if (v2->getCode() != 23) {
		cout << "Error en el metodo setCode" << endl;
	}

	delete v2;

	cout << "Fin Pruebas Via" << endl;

}

//int main() {
//
//	pruebasVia();
//
//}
