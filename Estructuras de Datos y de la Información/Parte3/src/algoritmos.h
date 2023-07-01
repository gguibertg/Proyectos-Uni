/*
 * Algoritmos.h
 *
 *  Created on: 03/03/2019
 *      Author: Profesores de EDI
 */

#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_

#include "ConjuntoBarrios.h"

/*
 * Descripcion: clase encargada de gestionar
 *				la clase conjuntoBarrios
 */

class Algoritmos {

private:


	 //Almacena un puntero a la clase ConjuntoBarrios

	ConjuntoBarrios *cjtB;

	/*
	 * Pre:{}
	 * Post:{Realiza la carga de los datos de los 3 ficheros csv}
	 * 0(n)
	 */

	void cargarDatos();

	/*
	 * Pre:{}
	 * Post:{Ejecuta los algoritmos}
	 * 0(1)
	 */

	void run();

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{Dado un arbol de vias, lo recorre mostrando por consola la via y el
	 * 		 barrio al que pertenece dicha via}
	 * 0(log n)
	 */

	void recorrerArbolR(arbol<Via*, Compare>* aV);

public:

	// Constructor por defecto

	Algoritmos();

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{Muestra por consola todos los barrios con sus vias y arboles de cada una}
	 * 0(n)
	 */

	void mostrarBarrios();

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{Dado el nombre de una via, recorre el vector de barrios llamando en cada uno al algoritmo
	 * 		 buscarViaPorNombre, cuando encuentra dicha via, llama al algoritmo1 de la clase via}
	 * 0(n)
	 */

	void algoritmo1(string nV);

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{Dada una especie de arbol, recorre el vector de barrios llamando al algoritmo2 de cada barrio}
	 * 0(n)
	 */

	void algoritmo2(string especie);

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{Recorre el vector de barrios llamadndo al algoritmo3 de la clase barrio para cada uno}
	 * 0(n)
	 */

	void algoritmo3(string genero);

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{Dado un arbol de vias, si no esta vacio, llama al metodo recorrerArbolR }
	 * 0(1)
	 */

	void recorrerArbol(arbol<Via*, Compare>* aV);

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{Recorre el vector de barrios y si dicho barrio empieza por la subcadena dada,
	 * 		 ejecuta el algoritmo4 de la clase barrio y genera un fichero}
	 * 0(n)
	 */

	void algoritmo4(string cad);

	// Destructor por defecto

	~Algoritmos();

};

#endif /* ALGORITMOS_H_ */
