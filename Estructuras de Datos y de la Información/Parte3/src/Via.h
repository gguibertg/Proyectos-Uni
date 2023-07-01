/*
 * Via.h
 *
 *  Created on: 20 mar. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#ifndef VIA_H_
#define VIA_H_

#include "Arbol.h"
#include "listapi.h"
#include <fstream>

/*
 * Descripcion: clase encargada de guardar la informacion
 *				proveniente del archivo Via.csv creando
 *				una Via.
 */

class Via {

	int codeBarrio;
	string nombreVia;
	float longitud;
	string tipoVia;
	int code;

	ListaPI<Arbol*>*lA;

public:

	Via(); // Constructor por defecto

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Constructor parametrizado}
	 * 0(1)
	 */

	Via(int codeBarrio, string nombreVia, float longitud, string tipoVia,
			int code);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el codigo del barrio de la via por el del int codeBarrio}
	 * 0(1)
	 */

	void setCodeBarrio(int codeBarrio);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el codigo del barrio de la via con la que se esta trabajando}
	 * 0(1)
	 */

	int getCodeBarrio() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el nombre de la via por el de la cadena nombreVia}
	 * 0(1)
	 */

	void setNombreVia(string nombreVia);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el nombre de la via con la que se esta trabajando}
	 * 0(1)
	 */

	string getNombreVia() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica la longitud de la via por la del float longitud}
	 * 0(1)
	 */

	void setLongitud(float longitud);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve la longitud de la via con la que se esta trabajando}
	 * 0(1)
	 */

	float getLongitud() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el tipo de la via por el de la cadena tipoVia}
	 * 0(1)
	 */

	void setTipoVia(string tipoVia);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el tipo de la via con la que se esta trabajando}
	 * 0(1)
	 */

	string getTipoVia() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el codigo de la via por el del int code}
	 * 0(1)
	 */

	void setCode(int code);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el codigo de la via con la que se esta trabajando}
	 * 0(1)
	 */

	int getCode() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Muestra por consola todos los datos de la via y su lista de arboles}
	 * 0(1)
	 */

	void mostrar();

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Inserta un arbol el la lista de arboles}
	 * 0(1)
	 */

	void insertarArbol(Arbol*a);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Crea un fichero con todos los datos de los árboles de una via}
	 * 0(n)
	 */

	void algoritmo1();

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Dada una especie, busca en la lista de arboles de la via si existe o no,devuelve true si la encuentra
	 * 		 o false en caso contrario}
	 * 0(n)
	 */

	bool tieneEspecie(string especie);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Dada una especie, devuelve cuantos arboles de dicha especie tiene la via}
	 * 0(n)
	 */

	int cuantosArbolesEspecie(string especie);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Dado un genero, busca si en la lista de arboles de la via existe o no alguno con dicho genero.
	 * 		 Devuelve true si lo encuentra o false en caso contrario}
	 * 0(n)
	 */

	bool algoritmo3(string genero);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Dados un flujo y un nombre de un barrio, escribe en un fichero la cantidad de arboles de un barrio y sus vias}
	 * 0(n)
	 */

	void algoritmo4(ofstream &fSal, string nB);

	~Via();

};

class Compare {

public:

	int operator()(Via *v1, Via * v2) {
		int result;
		if (v1->getNombreVia() == v2->getNombreVia())
			result = 0;
		else if (v1->getNombreVia() > v2->getNombreVia())
			result = 1;
		else
			result = -1;
		return result;
	}
};

#endif /* VIA_H_ */
