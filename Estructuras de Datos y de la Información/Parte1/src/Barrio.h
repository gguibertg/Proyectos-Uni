/*
 * Barrio.h
 *
 *  Created on: 20 mar. 2019
 *      Author: goblinl
 */

#ifndef BARRIO_H_
#define BARRIO_H_

#include "ConjuntoVias.h"
#include <iostream>
using namespace std;

class Barrio {

	string nombreBarrio;
	float area;
	float perimetro;
	int code;
	string distrito;

	ConjuntoVias* cjtV;

public:

	Barrio();

	Barrio(string nombreBarrio, float area, float perimetro, int code,
			string distrito);

	void setNombreBarrio(string nombreBarrio);

	string getNombreBarrio() const;

	void setArea(float area);

	float getArea() const;

	void setPerimetro(float perimetro);

	float getPerimetro() const;

	void setCode(int code);

	int getCode() const;

	void setDistrito(string distrito);

	string getDistrito() const;

	void mostrar();

	void insertarVia(Via*v);
	void escribirVs(string barrio);
	int numeroV();
	void algoritmo3(string subcadena);
	float algoritmo4(Via*&v,float mayor);

	~Barrio();
};

#endif /* BARRIO_H_ */
