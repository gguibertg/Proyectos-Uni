/*
 * ConjuntoVias.h
 *
 *  Created on: 20 mar. 2019
 *      Author: goblinl
 */

#ifndef CONJUNTOVIAS_H_
#define CONJUNTOVIAS_H_

#include "Via.h"
#include <iostream>
using namespace std;

const int MAXV = 1229;

class ConjuntoVias {

	Via*cjtV[MAXV];
	int cont;

public:

	ConjuntoVias();

	void insertar(Via *v);

	void borrar(string clave);

	void obtenerPorPos(int pos, Via *&v);

	void obtenerPorClave(string clave, Via *&v);

	bool existe(string clave);

	int cuantos();

	bool vacio();

	~ConjuntoVias();
};

#endif /* CONJUNTOVIAS_H_ */
