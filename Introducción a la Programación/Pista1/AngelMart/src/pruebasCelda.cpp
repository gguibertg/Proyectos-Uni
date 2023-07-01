/*
 * pruebasCelda.cpp
 *
 *  Created on: 12 ene. 2018
 *      Author: Carlos Garcia Garay y Gabriel Fernando Guiberteau Garcia
 */

#include "pruebasCelda.h"
#include "Celda.h"
#include <iostream>

  using namespace std;

void pruebaIniciar(){

	cout<<"pruebaIniciar"<<endl;

	celda c;
	iniciarCelda(c);

	if (c.vacia==false || c.reves==false)
		cout<<"error"<<endl;
}
void pruebaVaciarCelda(){

	cout<<"pruebaVaciarCelda"<<endl;

	celda c;
	vaciarCelda(c);

	if (c.vacia!=true)
		cout<<"error"<<endl;
}
void pruebaPonerValor(){

	cout<<"pruebaPonerValor"<<endl;

	celda c;
	ponerValor(c,5);

	if (c.n != 5)
		cout<<"error"<<endl;
}
void pruebaPonerEstado(){

cout<<"pruebaPonerEstado"<<endl;

celda c;
ponerEstado(c,true);

if(c.reves==false)
	cout<<"error"<<endl;
}
void pruebaObtenerValor(){
	cout<<"pruebaPonerValor"<<endl;

	celda c;
	c.n=3;

	if (obtenerValor(c)!=3)
		cout<<"error"<<endl;
}
void pruebaVacia(){

	cout<<"pruebaVacia"<<endl;

	celda c;
	c.vacia=true;

	if(vacia(c)==false)
		cout<<"error"<<endl;
}
void pruebaObtenerPosicion(){
	cout<<"pruebaObtenerPosicion"<<endl;

	celda c;
	c.reves=false;
	if(obtenerPosicion(c)!=false)
		cout<<"error"<<endl;
}
void pruebaComparar(){
	cout<<"pruebaComparar"<<endl;

	celda c;
	celda b;

	c.vacia=false;
	c.n=3;

	b.vacia= false;
	b.n= 4;

	if(compararFicha(c,b)==true){
		cout<<"Error"<<endl;
	}
}

void pruebasCelda(){

	cout<<"Inicio Pruebas TAD Celda "<<endl;

	pruebaIniciar();
	pruebaVaciarCelda();
	pruebaPonerValor();
	pruebaPonerEstado();
	pruebaObtenerValor();
	pruebaVacia();
	pruebaObtenerPosicion();
	pruebaComparar();

	cout<<"Fin Pruebas TAD Celda "<<endl;

	}

