//============================================================================
// Name        : angelMart.cpp
// Author      : Carlos Garcia Garay y Gabriel Fernando Guiberteau Garcia
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "entorno.h"
#include <iostream>
#include <cstdlib>
#include "Juego.h"
#include "PruebasTablero.h"
#include "pruebasCelda.h"
using namespace std;
void jugar(){
	juego J;
	if (iniciar (J)){
	 gestion (J);
	 terminar (J);
	}
}


int main(){
jugar();
pruebasCelda();
pruebasTablero();
return 0;
}
