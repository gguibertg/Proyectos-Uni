/*
 * Tablero.cpp
 *
 *  Created on: 2 ene. 2018
 *      Author:  Carlos Garcia Garay y Gabriel Fernando Guiberteau Garcia
 */

#include "Tablero.h"
void iniciarTablero(tablero &t, int tamano) {
	t.TAMANO = tamano;
	int i;
	int j;
	for (i = 0; i < t.TAMANO; i++) {
		for (j = 0; j < t.TAMANO; j++) {
			iniciarCelda(t.matriz[i][j]);

		}
	}

}
bool estaVacia(tablero t, int f, int c) {
	return vacia(t.matriz[f][c]);
}
bool caben(tablero &t) {
	bool caben;
	caben = true;
	int c;
	for(c=0;c<t.TAMANO;c++){
		if(!estaVacia(t,0,c))
			caben=false;
	}
	return caben;
}
bool estaVacio(tablero t) {
	bool estavacio;
	estavacio = true;
	int c;
	for (c = 0; c < t.TAMANO; c++) {
			if (estaVacia(t, t.TAMANO - 1, c) == false)
				estavacio = false;
	}
	return estavacio;
}
bool obtenerEstado(tablero t, int fil, int col) {
	return obtenerPosicion(t.matriz[fil][col]);
}
int obtenerValor(tablero t, int fil, int col) {
	return obtenerValor(t.matriz[fil][col]);
}
void modificarEstado(tablero &t, int f, int c) {
	if (obtenerPosicion(t.matriz[f][c]) == false)
		ponerEstado(t.matriz[f][c], true);
	else
		ponerEstado(t.matriz[f][c], false);
}
void ponerFicha(tablero&t, int f, int c, int v) {
	iniciarCelda(t.matriz[f][c]);
	ponerValor(t.matriz[f][c], v);

}

void borrarFicha(tablero&t, int f, int c) {
	int i;
	for (i = f; i >0; i--) {
		t.matriz[i][c] = t.matriz[i - 1][c];
		if (estaVacia(t, i - 1, c) == true)
			entornoBorrarCelda(i , c);
		else
			entornoFichaReves(i,c);
	}
	entornoBorrarCelda(0 , c);
}
int obtenerTamano(tablero t) {
	return t.TAMANO;
}
void nuevaFila(tablero &t) {
	int valor;
		int f;
		int c;
		int i;
		int col;
		f = 0;
		srand(time(NULL));
		for (valor = 0; valor < t.TAMANO/2; valor++) {
			c = rand() % t.TAMANO;
			while (!estaVacia(t, f, c)) {
				c = rand() % t.TAMANO;
			}
			ponerFicha(t, f, c, valor);
			c = rand() % t.TAMANO;
			while (!estaVacia(t, f, c)) {
				c = rand() % t.TAMANO;
			}
			ponerFicha(t, f, c, valor);

		}
		for (i = 0; i<t.TAMANO-1; i++) {
			for(col=0;col<t.TAMANO;col++){
			if (estaVacia(t,i+1,col)){
				t.matriz[i+1][col] = t.matriz[i][col];
				entornoFichaReves(i+1,col);
				entornoBorrarCelda(i,col);
				vaciarCelda(t.matriz[i][col]);
			}
			}
		}
}





bool comparar(tablero t, int ai, int aj, int bi, int bj) {
	if (ai!=bi || aj!=bj){
		return compararFicha(t.matriz[ai][aj], t.matriz[bi][bj]);
	}
		else
			return false;
}


