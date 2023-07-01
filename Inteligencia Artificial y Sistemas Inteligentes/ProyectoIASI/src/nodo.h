/*
 * nodo.h
 *
 *  Created on: 11 mar. 2020
 *      Authors: Canito Rubio, Rafael
 *			 García Garay, Carlos	
 *			 Guiberteau García, Gabriel Fernando
 */

#ifndef NODO_H_
#define NODO_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "listapi.h"
using namespace std;
#include <math.h>

const int TAM = 4;
typedef int TipoMatriz[TAM][TAM];
typedef int TipoVector[TAM];

class nodo {

	TipoMatriz m;
	TipoVector posCeros;
	nodo *padre;
	string movimiento;
	ListaPI<nodo*> *lHijos;

public:

	nodo();

	nodo(nodo *padre, string movimiento);

	string getMovimiento();

	void getPosReal(int n, int &x, int &y);

	void iniciar(string nP);

	int getHp();

	void localizarCeros();

	int getCeros(int i);

	void mover(int i, int j);

	void escaladaSimple(int i, int j, nodo *&hijo, int & nMovimientos, int &nNodos);

	void cambiarVCelda(int i, int j, int v);

	void escaladaMaxPendiente(bool solucion, int &nMovimientos, int &nNodos);

	void primeroMejor(int &nMovimientos,ListaPI<nodo*> *& lAbiertos,
			ListaPI<nodo*> *& lCerrados, int &nNodos);

	void solPrimeroMejor(nodo*padre,int &nMovimientos);

	bool yaInsertado(nodo *h, ListaPI<nodo*> * lNodos);

	void showMatriz();

	int getValorCelda(int i, int j);

	bool matricesIguales(nodo *h, nodo *nAux);

	~nodo();

};
#endif /* NODO_H_ */
