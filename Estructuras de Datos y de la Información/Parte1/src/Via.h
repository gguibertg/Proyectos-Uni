/*
 * Via.h
 *
 *  Created on: 20 mar. 2019
 *      Author: goblinl
 */

#ifndef VIA_H_
#define VIA_H_

#include <iostream>
using namespace std;

class Via {

	int codeBarrio;
	string nombreVia;
	float longitud;
	string tipoVia;
	int code;

public:

	Via();

	Via(int codeBarrio, string nombreVia, float longitud, string tipoVia,
				int code);

	void setCodeBarrio(int codeBarrio);

	int getCodeBarrio() const;

	void setNombreVia(string nombreVia);

	string getNombreVia() const;

	void setLongitud(float longitud);

	float getLongitud() const;

	void setTipoVia(string tipoVia);

	string getTipoVia() const;

	void setCode(int code);

	int getCode() const;

	void mostrar();


	~Via();
};

#endif /* VIA_H_ */
