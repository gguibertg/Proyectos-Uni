/*
 * Algoritmos.h
 *
 *  Created on: 03/03/2019
 *      Author: Profesores de EDI
 */

#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_

#include "ConjuntoBarrios.h"

class Algoritmos {

private:

	// TODO atributo, puntero a la clase conjunto de barrios

	ConjuntoBarrios *cjtB;

	// carga los datos desde los ficheros de texto

	void cargarDatos();

	// ejecuta todos los algoritmos del proyecto

	void run();

public:

	Algoritmos();

	/*
	 * Pre:{Datos cargados correctamente}
	 * Post:{Muestra todos los barrios con sus vías y los árboles de dichas vías}
	 * 0(n)
	 */

	void mostrarBarrios();

	/*
	 * Pre:{}
	 * Post:{}
	 * 0()
	 */

	void algoritmo1(string via);

	void buscarVia(int code, Via* &v);

	// Algoritmo  2 Parte 2:

	void algoritmo2(string genero);

	// Algoritmo  3 Parte 2:

	void algoritmo3();

	// Algoritmo  4 Parte 2:

	void algoritmo4();

	~Algoritmos();

};

#endif /* ALGORITMOS_H_ */
