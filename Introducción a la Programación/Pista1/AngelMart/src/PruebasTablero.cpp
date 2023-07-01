/*
 * PruebasTablero.cpp
 *
 *  Created on: 12 ene. 2018
 *      Author:  Carlos Garcia Garay y Gabriel Fernando Guiberteau Garcia
 */


#include <iostream>
using namespace std;

#include"PruebasTablero.h"

void pruebaIniciarTablero(){
	cout <<  "Inicio Prueba IniciarTablero" << endl;

	tablero t;
	iniciarTablero(t,10);

	if(obtenerTamano(t)!=10){
		cout << "Error Iniciar Tablero" << endl;
	}
}

void pruebaEstaVacia(){
	cout <<  "Inicio PruebaEstaVacia " << endl;

	tablero t;
	iniciarTablero(t,10);

	ponerFicha(t,0,3,4);
	ponerFicha(t,4,4,4);
	ponerFicha(t,7,5,2);

	if(estaVacia(t,0,3)==true){
		cout << "Error EstaVacia " << endl;
	}
	if(estaVacia(t,4,4)==true){
			cout << "Error EstaVacia " << endl;
		}
	if(estaVacia(t,7,5)==true){
			cout << "Error EstaVacia " << endl;
		}
}

void pruebaCaben(){
	cout <<  "Inicio Prueba Caben " << endl;

	tablero t;
	iniciarTablero(t,10);

	ponerFicha(t,0,0,4);
	ponerFicha(t,0,1,2);
	ponerFicha(t,0,2,4);
	ponerFicha(t,0,3,2);

	if(caben(t)==true){
		cout << "Error Caben " << endl;
	}

}

void pruebaEstaVacio(){
	cout <<  "Inicio PruebaEstaVacio " << endl;

	tablero t;
	iniciarTablero(t,10);

	ponerFicha(t,0,3,4);
	ponerFicha(t,4,4,4);
	ponerFicha(t,7,5,2);
	ponerFicha(t,9,0,4);
	ponerFicha(t,5,1,2);
	ponerFicha(t,1,2,4);
	ponerFicha(t,3,3,2);
	ponerFicha(t,2,7,5);
	ponerFicha(t,8,3,4);
	ponerFicha(t,6,9,2);


	if(estaVacio(t)==true){
		cout << "Error EstaVacio " << endl;
	}
}

void pruebaObtenerEstado(){
	cout <<  "Inicio Prueba ObtenerEstado " << endl;

	tablero t;
	iniciarTablero(t,10);

	ponerFicha(t,0,3,4);

	if(obtenerEstado(t,0,3)==false){
		cout << "Error ObtenerEstado" << endl;
	}
}

void pruebaModificarEstado(){
	cout <<  "Inicio Prueba ModificarEstado " << endl;

	tablero t;
	iniciarTablero(t,10);

	ponerFicha(t,5,5,5);
	modificarEstado(t,5,5);

	if(obtenerEstado(t,5,5)==true){
		cout << "Error ModificarEstado" << endl;
	}
}

void pruebaPonerFicha(){
	cout <<  "Inicio Prueba PonerFicha " << endl;

	tablero t;
	iniciarTablero(t,10);

	ponerFicha(t,0,3,4);
	ponerFicha(t,4,4,4);
	ponerFicha(t,7,5,2);
	ponerFicha(t,9,0,4);
	ponerFicha(t,5,1,2);
	ponerFicha(t,1,2,4);
	ponerFicha(t,3,3,2);
	iniciarTablero(t,10);

	ponerFicha(t,4,5,6);
	ponerFicha(t,1,2,3);
	ponerFicha(t,7,8,9);

	if(estaVacia(t,4,5)==true){
		cout << "Error PonerFicha " << endl;
	}
	if(estaVacia(t,1,2)==true){
			cout << "Error PonerFicha" << endl;
		}
	if(estaVacia(t,7,8)==true){
			cout << "Error PonerFicha" << endl;
		}
}

void pruebaBorrarFicha(){
	cout <<  "Inicio Prueba BorrarFicha " << endl;

	tablero t;
	iniciarTablero(t,10);

	ponerFicha(t,0,3,4);
	ponerFicha(t,4,4,4);
	ponerFicha(t,7,5,2);

	borrarFicha(t,0,3);
	borrarFicha(t,4,4);
	borrarFicha(t,7,5);

	if(estaVacia(t,0,3)==false){
		cout << "Error BorrarFicha" << endl;
	}
	if(estaVacia(t,4,4)==false){
			cout << "Error BorrarFicha" << endl;
		}
	if(estaVacia(t,7,5)==false){
			cout << "Error BorrarFicha" << endl;
		}
}

void pruebaObtenerTamano (){
	cout <<  "Inicio Prueba ObtenerTamano " << endl;

	tablero t;
	iniciarTablero(t,10);

	obtenerTamano(t);

	if(obtenerTamano(t)!=10)
		cout << "Error obtenerTamano " << endl;
}

void pruebaNuevaFila(){
	cout <<  "Inicio Prueba " << endl;

	tablero t;
	iniciarTablero(t,10);


		cout << "Error " << endl;
}

void pruebasTablero(){

	cout <<  "Inicio Pruebas TAD Tablero" << endl;

	pruebaIniciarTablero();
	pruebaEstaVacia();
	pruebaCaben();
	pruebaEstaVacio();
	pruebaObtenerEstado();
	pruebaModificarEstado();
	pruebaPonerFicha();
	pruebaBorrarFicha();
	pruebaObtenerTamano ();
	pruebaNuevaFila();

	cout <<  "Fin Pruebas TAD Tablero" << endl;
}





















