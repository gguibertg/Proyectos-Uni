/*
 * Arbol.h
 *
 *  Created on: 14 abr. 2019
 *      Author: Carlos Garcia Garay y Gabriel F. Guiberteau Garcia
 */

#ifndef ARBOL_H_
#define ARBOL_H_

#include <iostream>
using namespace std;

/*
 * Descripcion: clase encargada de guardar la informacion
 *				proveniente del archivo Arbol.csv creando
 *				un arbol.
 */

class Arbol {

	string especie;
	string familia;
	string nombre;
	string genero;
	float diametro;
	float altura;
	float copa;
	string riego;
	int unidades;
	int codeVia;

public:

	Arbol(); // Constructor por defecto

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Crea un arbol con todos sus atributos}
	 * 0(1)
	 */

	Arbol(string especie, string familia, string nombre, string genero,
			float diametro, float altura, float copa, string riego,
			int unidades, int codeVia);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica la especie del arbol por la del string especie}
	 * 0(1)
	 */

	void setEspecie(string especie);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve la especie del arbol con el que se esta trabajando}
	 * 0(1)
	 */

	string getEspecie() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica la familia del arbol por el del string familia}
	 * 0(1)
	 */

	void setFamilia(string familia);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve la familia del arbol con el que se esta trabajando }
	 * 0(1)
	 */

	string getFamilia() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el nombre del arbol por el del string nombre}
	 * 0(1)
	 */

	void setNombre(string nombre);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el nombre del arbol con el que se esta trabajando}
	 * 0(1)
	 */

	string getNombre() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el genero del arbol por el del string genero}
	 * 0(1)
	 */

	void setGenero(string genero);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el genero del arbol con el que se esta trabajando}
	 * 0(1)
	 */

	string getGenero() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el diametro del arbol por el del float diametro}
	 * 0(1)
	 */

	void setDiametro(float diametro);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el diametro del arbol con el que se esta trabajando}
	 * 0(1)
	 */

	float getDiametro() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica la altura del arbol por el del float altura}
	 * 0(1)
	 */

	void setAltura(float altura);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve la altura del arbol con el que se esta trabajando}
	 * 0(1)
	 */

	float getAltura() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el tamaño de la copa del arbol por el del float copa}
	 * 0(1)
	 */

	void setCopa(float copa);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el tamaño de la copa del arbol con el que se esta trabajando}
	 * 0(1)
	 */

	float getCopa() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el tipo de riego del arbol por el del string riego}
	 * 0(1)
	 */

	void setRiego(string riego);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve tipo de riego del arbol con el que se esta trabajando}
	 * 0(1)
	 */

	string getRiego() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica las unidades que hay del arbol por el del int unidades}
	 * 0(1)
	 */

	void setUnidades(int unidades);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el número de unidades que hay del arbol con el que se esta trabajando}
	 * 0(1)
	 */

	int getUnidades() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Modifica el codigo de la via del arbol por el del int code}
	 * 0(1)
	 */

	void setCodeVia(int codeVia);

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Devuelve el código de la via del arbol con el que se esta trabajando}
	 * 0(1)
	 */

	int getCodeVia() const;

	/*
	 * Pre:{La estructura debe de estar correctamente inicializada}
	 * Post:{Muestra los datos del arbol}
	 * 0(1)
	 */

	void mostrar();

	~Arbol();
};

#endif /* ARBOL_H_ */
