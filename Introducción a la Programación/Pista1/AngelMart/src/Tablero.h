/*
 * Tablero.h
 *
 *  Created on: 2 ene. 2018
 *      Author:  Carlos Garcia Garay y Gabriel Fernando Guiberteau Garcia
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include "Celda.h"
#include  <cstdlib>

typedef celda cmatriz[10][10];
struct tablero{
	cmatriz matriz;
	int TAMANO;
};
//0(n)
//POST:inicia correctamente el tablero con el tamaño indicado
//PRE:el tamaño debe estar entre 4 y 10
void iniciarTablero(tablero &t,int tamano);
//0(1)
//POST:Devuelve true si la celda indicada esta vacia y false en caso contrario
//PRE:el tablero debe estar correctamente inicializado
bool estaVacia(tablero t, int f, int c);
//0(1)
//PRE:el tablero debe estar correctamente inicializado, f y c deben corresponder a filas y columnas reales en el tablero
//POST:devuelve true si cabe una nueva fila de fichas y false en caso contrario
bool caben(tablero &t);
//0(n)
//PRE:el tablero debe estar correctamente inicializado
//POST:devuelve true si el tablero esta vacio y false en caso contrario
	bool estaVacio(tablero t);
	//0(1)
	//PRE:el tablero debe estar correctamente inicializado y la fil y col pertenecer a filas y columnas reales en el
	//POST:devuelve true si la ficha esta del anverso y false si esta del reverso
	bool obtenerEstado(tablero t,int fil, int col);
	int obtenerValor(tablero t, int fil, int col);
	//0(1)
	//PRE:el tablero debe estar correctamente inicializado, f y c deben ser columnas y filas reales en el tablero
	//POST:cambia el estado de la ficha señalada con f y con c
	void modificarEstado(tablero &t, int f, int c);
	//0(1)
	//PRE:el tablero debe estar correctamente inicializado, f y c deben existir como filas y columnas en el tablero y c debe ser un valor positivo del 1 al 10
	//POST:pone una ficha en la celda marcada con f y con c como fila y columna con el valor v
		void ponerFicha(tablero&t, int f, int c, int v);
		//0(1)
		//PRE:el tablero debe estar correctamente inicializado, f y c deben existir como filas y columnas y la celda indicada debe contener una ficha
		//POST:elimina una ficha de la celda indicada
		void borrarFicha(tablero&t, int f, int c);
		//0(1)
		//PRE:el tablero debe estar correctamente inicializado
		//POST:devuelve el tamaño del tablero en forma de numero entero
		int obtenerTamano (tablero t);
		//0(n)
		//PRE:el tablero debe estar correctamente inicializado
		//POST:Crea una nueva fila
		void nuevaFila(tablero &t);
		//O(1)
		//PRE:el tablero debe estar correctamente inicializado
		//POST:compara el estado y el numero de dos celdas; devuelve true si coinciden y false en caso contrario
		bool comparar(tablero t, int ai, int aj, int bi, int bj);


#endif /* TABLERO_H_ */
