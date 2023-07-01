/*
 * Celda.h
 *
 *  Created on: 2 ene. 2018
 *      Author:  Carlos Garcia Garay y Gabriel Fernando Guiberteau Garcia
 */

#ifndef CELDA_H_
#define CELDA_H_
#include "entorno.h"


struct celda {
	int n;
	bool reves;
	bool vacia;
};
//0(1)
//PRE
//POST{Se inicia correctamente la celda}
void iniciarCelda(celda &c);

//0(1)
//PRE{la celda debe estar correctamente inicializada}
//POST{vacia el contenido de la celda}
void vaciarCelda(celda &c);

//0(1)
//PRE{la celda debe estar correctamente inicializada}
//POST{pone el valor indicado en la posicion indicada}
void ponerValor(celda &c, int valor);
//0(1)
//PRE{la celda debe estar correctamente inicializada}
//POST{pone el estado de la ficha que puede ser anverso o reverso}
void ponerEstado(celda &c,bool estado);
//0(1)
//PRE{la celda debe estar correctamente inicializada}
//POST{devuelve el valor de la ficha indicada}
int obtenerValor(celda c);
//0(1)
//PRE{la celda debe estar correctamente inicializada}
//POST{devuelve true si la ficha esta vacia y false en caso contrario}
bool vacia(celda c);
//0(1)
//PRE{la celda debe estar correctamente inicializada}
//POST{devuelve true si la ficha indicada esta del anverso y false si esta del reverso}
bool obtenerPosicion(celda c);
//0(1)
//PRE{la celda debe estar correctamente inicializada}
//POST{devuelve true si son iguales y false en el caso contrario}
bool compararFicha(celda c, celda b);
#endif /* CELDA_H_ */
