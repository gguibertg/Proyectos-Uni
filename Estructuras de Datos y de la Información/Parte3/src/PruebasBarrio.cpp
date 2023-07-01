/*
 * PruebasBarrio.cpp
 *
 *  Created on: 22 mar. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#include "Barrio.h"

void pruebasBarrio() {

	cout << "Inicio PruebasBarrio" << endl;

	Barrio *b1;

	b1 = new Barrio("Fantasma", 123, 456, 42, "centro");

	if (b1->getNombreBarrio() != "Fantasma") {
		cout << "Error constructor parametrizado en nombreBarrio" << endl;
	}
	if (b1->getArea() != 123) {
		cout << "Error constructor parametrizado en area" << endl;
	}
	if (b1->getPerimetro() != 456) {
		cout << "Error constructor parametrizado en perimetro" << endl;
	}
	if (b1->getCode() != 42) {
		cout << "Error constructor parametrizado en code" << endl;
	}
	if (b1->getDistrito() != "centro") {
		cout << "Error constructor parametrizado en distrito" << endl;
	}

	b1->setNombreBarrio("Winterfell");
	b1->setArea(1500);
	b1->setPerimetro(5000);
	b1->setCode(46);
	b1->setDistrito("norte");

	if (b1->getNombreBarrio() != "Winterfell") {
		cout << "Error en el metodo setNombreBArrio" << endl;
	}
	if (b1->getArea() != 1500) {
		cout << "Error en el metodo setArea" << endl;
	}
	if (b1->getPerimetro() != 5000) {
		cout << "Error en el metodo setPerimetro" << endl;
	}
	if (b1->getCode() != 46) {
		cout << "Error en el metodo setCodigo" << endl;
	}
	if (b1->getDistrito() != "norte") {
		cout << "Error en el metodo setDistrito" << endl;
	}

	delete b1;

	Barrio*b2;

	b2 = new Barrio();

	Via*v, *v1, *v2, *v3, *v4, *v5, *v6, *v7;

	v1 = new Via(35, "De España", 1100, "Avda", 3048);
	v2 = new Via(9, "Hornillos", 99, "Calle", 1195);
	v3 = new Via(16, "Alcantara", 113, "Calle", 12);
	v4 = new Via(5, "Rio Po", 121, "Calle", 401);
	v5 = new Via(35, "Profesor Rodriguez Moñino", 97, "Calle", 3539);
	v6 = new Via(24, "Beata Madre Matilde", 78, "Calle", 3954);

	b2->insertarVia(v1);
	b2->insertarVia(v2);
	b2->insertarVia(v3);
	b2->insertarVia(v4);
	b2->insertarVia(v5);
	b2->insertarVia(v6);

	b2->buscarViaPorCode(12, v);
	if (v->getNombreVia() != v3->getNombreVia()) {
		cout << "Error modulo buscarViaPorCode" << endl;
	}

	b2->buscarViaPorNombre("Profesor Rodriguez Moñino", v7);
	if (v7->getNombreVia() != "Profesor Rodriguez Moñino") {
		cout << "Error modulo buscarViaPorNombre" << endl;
	}

	b2->mostrar();

	delete b2;

	cout << "Fin Pruebas Barrio" << endl;

}

/*int main (){

	pruebasBarrio();

}*/
