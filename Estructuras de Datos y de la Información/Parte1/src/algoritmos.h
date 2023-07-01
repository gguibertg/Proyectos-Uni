/*
 * Algoritmos.h
 *
 *  Created on: 02/03/2019
 *      Author: Profesores de EDI
 */

#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_

#include "ConjuntoBarrios.h"
#include "ConjuntoVias.h"




class Algoritmos {

private:
    
    // TODO atributo, puntero a la clase conjunto de barrios
	ConjuntoBarrios *cjtoB;

	// carga los datos desde los ficheros de texto
	void cargarDatos();
    // ejecuta todos los algoritmos del proyecto
	void run ();

public:

	 Algoritmos();
	 // Algoritmo 0 (ejemplo), muestra todos los barrios con sus vías
	 void mostrarBarrios();

     // Algoritmo  1:
	 void algoritmo1(string barrio);
	 // Algoritmo  2:
	 void algoritmo2(Barrio*& a, Barrio*& b);
	 // Algoritmo  3:
	 void algoritmo3(string subcadena);
	 // Algoritmo  4:
	 void algoritmo4();

	 ~Algoritmos();
    
};

#endif /* ALGORITMOS_H_ */
