/*
 * ConjuntoBarrios.h
 *
 *  Created on: 20 mar. 2019
 *      Author: goblinl
 */

#ifndef CONJUNTOBARRIOS_H_
#define CONJUNTOBARRIOS_H_

#include "Barrio.h"
#include <iostream>
using namespace std;

const int MAXB = 78;

class ConjuntoBarrios {

	Barrio*cjtB[MAXB];
	int cont;

public:

	ConjuntoBarrios();

	void insertar(Barrio*b);

	void borrar(string clave);

	void obtenerPorPos(int pos, Barrio *&b);

	void obtenerPorClave(string clave, Barrio *&b);

	bool existe(string clave);

	int cuantos();

	bool vacio();

	~ConjuntoBarrios();
};

#endif /* CONJUNTOBARRIOS_H_ */
