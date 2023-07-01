/*
 * ConjuntoBarrios.h
 *
 *  Created on: 20 mar. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#ifndef CONJUNTOBARRIOS_H_
#define CONJUNTOBARRIOS_H_

#include "Barrio.h"
#include <iostream>
using namespace std;

const int MAXB = 78;

/*
 * Descripcion: clase encargada de gestionar
 *				un vector de punteros a barrios
 */

class ConjuntoBarrios {

	Barrio*cjtB[MAXB];
	int cont;

public:

	ConjuntoBarrios(); // Constructor por defecto

	/*
	 * Pre:{Que cjtB no este a NULL}
	 * Post:{Inserta un barrio en cjtB}
	 * 0(n²)
	 */

	void insertar(Barrio*b);

	/*
	 * Pre:{Que cjtB no este a NULL}
	 * Post:{Borra por clave un abrrio de cjtB}
	 * 0(n²)
	 */

	void borrar(string clave);

	/*
	 * Pre:{Que cjtB no este a NULL}
	 * Post:{Dada una posicion, devuelve por referencia el barrio en esa posicion de cjtB}
	 * 0(1)
	 */

	void obtenerPorPos(int pos, Barrio *&b);

	/*
	 * Pre:{Que cjtB no este a NULL}
	 * Post:{Dada una clave, devuelve por referencia el barrio de cjtB al que pertenece dicha clave}
	 * 0(n)
	 */

	void obtenerPorClave(string clave, Barrio *&b);

	/*
	 * Pre:{Que cjtB no este a NULL}
	 * Post:{Dada una clave, devuelve true si encuentra el barrio al que pertenece dicha clave en cjtB y false en caso contrario}
	 * 0(n)
	 */

	bool existe(string clave);

	/*
	 * Pre:{Que cjtB no este a NULL}
	 * Post:{Devuelve el contador de cjtB}
	 * 0(1)
	 */

	int cuantos();

	/*
	 * Pre:{Que cjtB no este a NULL}
	 * Post:{Devuelve true si cont es 0 y false en caso contrario}
	 * 0(1)
	 */

	bool vacio();

	~ConjuntoBarrios();
};

#endif /* CONJUNTOBARRIOS_H_ */
