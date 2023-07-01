/*
 * Barrio.h
 *
 *  Created on: 20 mar. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#ifndef BARRIO_H_
#define BARRIO_H_

#include "Via.h"
#include "listapi.h"
#include <iostream>
#include "cola.h"
using namespace std;

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

	ListaPI<Via*>*lV;

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
	 * Post:{Inserta Vias en una lista de vias por orden alfabetico}
	 * 0(n)
	 */

	void insertarVia(Via*v);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada y la lista creada}
	 * Post:{Devuelve true si encuentra la via y llama al algoritmo 1 de la clase via o false en caso contrario}
	 * 0(n)
	 */

	bool buscarVPorNombre(string nV);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada y la lista creada}
	 * Post:{Devuelve true si encuentra la via y o false en caso contrario}
	 * 0(n)
	 */

	bool buscarVia(int code, Via *&v);
	void algoritmo2(Cola<Arbol*>*&c, string genero);

	void algoritmo3(ListaPI<Arbol*>*&lAux);

	int algoritmo4();

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Borra todas las vias de la lista y la lista}
	 * 0(n)
	 */

	~Barrio();
};

#endif /* BARRIO_H_ */
