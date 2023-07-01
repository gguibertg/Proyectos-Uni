/*
 * Barrio.h
 *
 *  Created on: 20 mar. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#ifndef BARRIO_H_
#define BARRIO_H_

#include "Via.h"
#include "arbol.h"
#include <iomanip>

/*
 * Descripcion: clase encargada de guardar la informacion
 *				proveniente del archivo Barrio.csv creando un
 *				barrio.
 */

class Barrio {

	string nombreBarrio;
	float area;
	float perimetro;
	int code;
	string distrito;

	arbol<Via*, Compare> *aVias;

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{Dado un arbol, muestra todas sus vias en PreOrden}
	 * 0(log n)
	 */

	void mostrarPreOrden(arbol<Via*, Compare> *aAux);

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{}
	 * 0()
	 */

	void buscarViaPorCodeR(int code, Via*& v, arbol<Via*, Compare>* aV,
			bool &enc);

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{}
	 * 0()
	 */

	bool buscarViaPorNombreR(string nom, Via*& v, arbol<Via*, Compare>* aV);

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{}
	 * 0()
	 */

	void algoritmo2R(string especie, arbol<Via*, Compare>* aV, Via* &v,
			ofstream &fSal, int &tA);

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{}
	 * 0()
	 */

	void algoritmo3R(string gen, Via*& v, arbol<Via*, Compare>* aV,
			arbol<Via*, Compare>* &aAux);

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{}
	 * 0()
	 */

	arbol<Via*, Compare>* viasEmpiezanPor(arbol<Via*, Compare>* aV,
			string subCadena);

	/*
	 * Pre:{Estructura correctamente inicializada}
	 * Post:{}
	 * 0()
	 */

	void filtroInOrden(arbol<Via*, Compare>* aV, string subCadena,
			ofstream &fSal, string nB);

public:

	Barrio(); // Constructor por defecto

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Crea un barrio con todos sus atributos}
	 * 0(1)
	 */

	Barrio(string nombreBarrio, float area, float perimetro, int code,
			string distrito);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el nombre del barrio por el de la cadena nombreBarrio}
	 * 0(1)
	 */

	void setNombreBarrio(string nombreBarrio);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el nombre del barrio con el que se esta trabajando}
	 * 0(1)
	 */

	string getNombreBarrio() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el area del barrio por el del float area}
	 * 0(1)
	 */

	void setArea(float area);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el area del barrio con el que se esta trabajando}
	 * 0(1)
	 */

	float getArea() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el perimetro del barrio por el del float perimetro}
	 * 0(1)
	 */

	void setPerimetro(float perimetro);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el perimetro del barrio con el que se esta trabajando}
	 * 0(1)
	 */

	float getPerimetro() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el codigo del barrio por el de la cadena code}
	 * 0(1)
	 */

	void setCode(int code);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el codigo del barrio con el que que esta trabajando}
	 * 0(1)
	 */

	int getCode() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el distrito del barrio por el de la cadena distrito}
	 * 0(1)
	 */

	void setDistrito(string distrito);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el distrito del barrio con el que se esta trabajando}
	 * 0(1)
	 */

	string getDistrito() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Muestra por consola todos los datos del barrio}
	 * 0(n)
	 */

	void mostrar();

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada y la lista creada}
	 * Post:{Inserta Vias en un arbol de vias}
	 * 0(1)
	 */

	void insertarVia(Via*v);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Dado un codigo de via, llama al algoritmo buscarViaPorCodeR y la devuelve por referencia}
	 * 0(1)
	 */

	bool buscarViaPorCode(int code, Via*& v);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Dado un nombre de via, llama al algoritmo buscarViaPorNombreR y la devuelve por referencia}
	 * 0(1)
	 */

	bool buscarViaPorNombre(string nom, Via*& v);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{}
	 * 0()
	 */

	void algoritmo2(string especie, ofstream &fSal, int &tA);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Si el barrio tiene un arbol de vias, llama al algoritmo3R, y devuelve un flujo de salida}
	 * 0(1)
	 */

	void algoritmo3(string gen, arbol<Via*, Compare>* &aAux);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve un arbol con las vias que empiezan por una subcadena}
	 * 0(log n)
	 */

	void algoritmo4(string subCadena, ofstream &fSal);

	~Barrio();
};

#endif /* BARRIO_H_ */
