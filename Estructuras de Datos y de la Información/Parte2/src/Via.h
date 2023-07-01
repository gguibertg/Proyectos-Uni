/*
 * Via.h
 *
 *  Created on: 20 mar. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#ifndef VIA_H_
#define VIA_H_

#include <iostream>
#include <fstream>
#include "listapi.h"
#include "Arbol.h"
#include "cola.h"
using namespace std;

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
	 * Pre:{}
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
	 * Post:{Genera un fichero con todos los árboles de una determinada vía}
	 * 0(n)
	 */

	void algoritmo1(string nV);
	void algoritmo2(Cola<Arbol*>*&c, string genero);

	void algoritmo3(ListaPI<Arbol*>*&lAux);

	int algoritmo4();
	void encolarPrioridad(Cola<Arbol*>*&c,Arbol *a);

	~Via();
};

#endif /* VIA_H_ */
