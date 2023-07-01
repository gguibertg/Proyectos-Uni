//============================================================================
// Name        : ProyectoIASI.cpp
// Authors	    :	 Canito Rubio, Rafael
// 			 Garc�a Garay, Carlos	
//			 Guiberteau Garc�a, Gabriel Fernando
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "nodo.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

int main() {

	srand(time(NULL));

	nodo *n;
	nodo *h;
	string nP;
	string opcion;

	int nMovimientos = 0;
	int nNodos = 0;

	ListaPI<nodo*> *lAbiertos = new ListaPI<nodo*>;
	ListaPI<nodo*> *lCerrados = new ListaPI<nodo*>;

	clock_t tIni, tFin;
	double secs;

	n = new nodo();

	cout << "Indique el número del puzzle (del 1 al 10 sin espacios)" << endl;
	getline(cin, nP);

	n->iniciar(nP);

	cout << "Seleccione el algoritmo que desea ejecutar" << endl;
	cout << " (1) Escalada Simple" << endl;
	cout << " (2) Escalada Máxima Pendiente" << endl;
	cout << " (3) Primero Mejor" << endl;
	cout << " (4) Todos a la vez" << endl;

	getline(cin, opcion);

	n->localizarCeros();

	int op = atoi(opcion.c_str());

	if (op == 1) {

		nMovimientos = 0;

		tIni = clock();

		cout << "Algoritmo de Escalada Simple: " << endl;

		cout << "Calculando, esto puede tardar unos segundos..." << endl;

		int r2 = rand() % 2;

		if (r2 == 0) {
			n->escaladaSimple(n->getCeros(0), n->getCeros(1), h, nMovimientos,
					nNodos);
		} else {
			n->escaladaSimple(n->getCeros(2), n->getCeros(3), h, nMovimientos,
					nNodos);
		}

		tFin = clock();

		cout << "El número de movimientos ha sido: " << nMovimientos << endl;

		secs = (double) (tFin - tIni) / CLOCKS_PER_SEC;

		cout << "Ha tardado en ejecutarse: " << secs << " segundos" << endl;

		cout << "El número de nodos generados es: " << nNodos << endl;

	} else {
		if (op == 2) {

			nMovimientos = 0;

			tIni = clock();

			cout << "Algoritmo de Escalada de Máxima Pendiente: " << endl;

			n->escaladaMaxPendiente(false, nMovimientos, nNodos);

			tFin = clock();

			cout << "El número de movimientos ha sido: " << nMovimientos
					<< endl;

			secs = (double) (tFin - tIni) / CLOCKS_PER_SEC;

			cout << "Ha tardado en ejecutarse: " << secs << " segundos" << endl;

			cout << "El número de nodos generados es: " << nNodos << endl;

		} else {
			if (op == 3) {

				nMovimientos = 0;

				tIni = clock();

				cout << "Algoritmo de Primero Mejor: " << endl;

				cout << "Calculando, esto puede tardar unos segundos..."
						<< endl;

				n->primeroMejor(nMovimientos, lAbiertos, lCerrados, nNodos);

				tFin = clock();

				cout << "El número de movimientos ha sido: " << nMovimientos
						<< endl;

				secs = (double) (tFin - tIni) / CLOCKS_PER_SEC;

				cout << "Ha tardado en ejecutarse: " << secs << " segundos"
						<< endl;

				cout << "El número de nodos generados es: " << nNodos << endl;

			} else {
				if (op == 4) {

					nMovimientos = 0;

					cout << "Todos a la vez: " << endl;

					cout
							<< "------------------------------------------------------------------------"
							<< endl;

					tIni = clock();

					cout << "Algoritmo de Escalada Simple: " << endl;

					cout << "Calculando, esto puede tardar unos segundos..."
							<< endl;

					int r2 = rand() % 2;

					if (r2 == 0) {
						n->escaladaSimple(n->getCeros(0), n->getCeros(1), h,
								nMovimientos, nNodos);
					} else {
						n->escaladaSimple(n->getCeros(2), n->getCeros(3), h,
								nMovimientos, nNodos);
					}

					tFin = clock();

					cout << "El número de movimientos ha sido: " << nMovimientos
							<< endl;

					secs = (double) (tFin - tIni) / CLOCKS_PER_SEC;

					cout << "Ha tardado en ejecutarse: " << secs << " segundos"
							<< endl;

					cout << "El número de nodos generados es: " << nNodos
							<< endl;

					cout
							<< "------------------------------------------------------------------------"
							<< endl;

					nMovimientos = 0;

					tIni = clock();

					cout << "Algoritmo de Escalada de Máxima Pendiente: "
							<< endl;

					n->escaladaMaxPendiente(false, nMovimientos, nNodos);

					tFin = clock();

					cout << "El número de movimientos ha sido: " << nMovimientos
							<< endl;

					secs = (double) (tFin - tIni) / CLOCKS_PER_SEC;

					cout << "Ha tardado en ejecutarse: " << secs << " segundos"
							<< endl;

					cout << "El número de nodos generados es: " << nNodos
							<< endl;

					cout
							<< "------------------------------------------------------------------------"
							<< endl;

					nMovimientos = 0;

					tIni = clock();

					cout << "Algoritmo de Primero Mejor: " << endl;

					cout << "Calculando, esto puede tardar unos segundos..."
							<< endl;

					n->primeroMejor(nMovimientos, lAbiertos, lCerrados, nNodos);

					tFin = clock();

					cout << "El número de movimientos ha sido: " << nMovimientos
							<< endl;

					secs = (double) (tFin - tIni) / CLOCKS_PER_SEC;

					cout << "Ha tardado en ejecutarse: " << secs << " segundos"
							<< endl;

					cout << "El número de nodos generados es: " << nNodos
							<< endl;

				}
			}
		}

	}

	return 0;
}
