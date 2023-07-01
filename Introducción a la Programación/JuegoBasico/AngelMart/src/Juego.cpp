/*
 * Juego.cpp
 *
 *  Created on: 2 ene. 2018
 *      Author:  Carlos Garcia Garay y Gabriel Fernando Guiberteau Garcia
 */

#include "Juego.h"

void pintarJuego(juego&ju) {
	int i;
	int j;
	for (i = 0; i < obtenerTamano(ju.tabler); i++) {
		for (j = 0; j < obtenerTamano(ju.tabler); j++) {
			if (estaVacia(ju.tabler, i, j) == true)
				entornoBorrarCelda(i, j);
			else
				entornoFichaReves(i, j);

		}
	}
}
bool iniciar(juego &ju) {
	int tamanoTablero; //guardará el número de filas y columnas del tablero, rol: valor fijo
	bool sePuedeIniciar;
	sePuedeIniciar = false;
	if (entornoCargarConfiguracion(tamanoTablero, ju.tiempoJugada,
			ju.puntosRestar)) {
		sePuedeIniciar = true;
		entornoIniciar(tamanoTablero);
		iniciarTablero(ju.tabler, tamanoTablero);
		ju.puntuacion = 0;
		int valor;
		int f;
		int c;
		int r;
		srand(time(NULL));
		for (valor = 0; valor < tamanoTablero; valor++) {
			r = rand() % 2;
			if (r == 0)
				f = tamanoTablero - 1;
			else
				f = tamanoTablero - 2;
			c = rand() % tamanoTablero;
			while (!estaVacia(ju.tabler, f, c)) {
				r = rand() % 2;
				if (r == 0)
					f = tamanoTablero - 1;
				else
					f = tamanoTablero - 2;
				c = rand() % tamanoTablero;
			}
			ponerFicha(ju.tabler, f, c, valor);

			r = rand() % 2;
			if (r == 0)
				f = tamanoTablero - 1;
			else
				f = tamanoTablero - 2;
			c = rand() % tamanoTablero;
			while (!estaVacia(ju.tabler, f, c)) {
				r = rand() % 2;
				if (r == 0)
					f = tamanoTablero - 1;
				else
					f = tamanoTablero - 2;
				c = rand() % tamanoTablero;
			}
			ponerFicha(ju.tabler, f, c, valor);

		}
		pintarJuego(ju);

	}
	return sePuedeIniciar;

}
void gestion(juego &ju) {
	int seg;   //almacena los segundos del cronómetro, rol: más reciente

	bool salir;   //controla la salida del bucle, rol: bandera
	TipoTecla tecla;   //almacena las teclas pulsadas, rol: más reciente
	int fila, col; //almacena la posición de lentornoFichaAnverso(fila,col,rand()%10);a celda seleccionada, rol: transformación

//las siguentes instrucciones simulan el desplazamiento por el tablero
//utilizando las teclas de movimiento: arriba, abajo, derecha e izquierda
	salir = false;
	fila = obtenerTamano(ju.tabler) - 1;
	col = 0;
	entornoActivarCelda(fila, col);
	seg = 0;   //se inician los segundos del cronómetro
	bool encontrada;
	encontrada = false;
	int i;
	int j;
	i = 0;
	ju.puntuacion = 0;
	entornoPonerPuntuacion(ju.puntuacion);
	while (!salir) {
		if (estaVacio(ju.tabler)) {
			ju.puntuacion = ju.puntuacion + 50;
			entornoPonerPuntuacion(ju.puntuacion);
			salir = true;
		}

		entornoTiempo(seg, ju.tiempoJugada); //se actualizan y muestran los segundos del cronómetro
		if (seg == ju.tiempoJugada) { //al llegar a 10 segundos, el cronómetro se vuelve a iniciar
			seg = 0;
			if (caben(ju.tabler)) {
				nuevaFila(ju.tabler);
				pintarJuego(ju);

			} else
				salir = true;
		}

		tecla = entornoLeerTecla();
		switch (tecla) {
		case TEnter:
			encontrada = false;
			if (!estaVacia(ju.tabler, fila, col)) {
				if (obtenerEstado(ju.tabler, fila, col) == true) {
					entornoFichaCanto(fila, col);
					entornoPausa(0.1);
					entornoFichaAnverso(fila, col,
							obtenerValor(ju.tabler, fila, col));
					modificarEstado(ju.tabler, fila, col);
					for (i = 0; i < obtenerTamano(ju.tabler) && !encontrada;
							i++) {
						for (j = 0; j < obtenerTamano(ju.tabler) && !encontrada;
								j++) {
							if ((obtenerEstado(ju.tabler, fila, col)
									== obtenerEstado(ju.tabler, i, j))
									&& (fila != i || j != col)
									&& (!obtenerEstado(ju.tabler, fila, col)))
								encontrada = true;
						}
					}

					i--;
					j--;
					if (encontrada == true) {
						if (comparar(ju.tabler, i, j, fila, col) == true) {
							entornoFichaCanto(fila, col);
							entornoFichaCanto(i, j);
							entornoFichaAnverso(fila, col,
									obtenerValor(ju.tabler, fila, col));
							entornoFichaAnverso(i, j,
									obtenerValor(ju.tabler, i, j));
							entornoPausa(0.1);
							if (i < fila) {
								borrarFicha(ju.tabler, i, j);
								borrarFicha(ju.tabler, fila, col);
							} else {
								borrarFicha(ju.tabler, fila, col);
								borrarFicha(ju.tabler, i, j);
							}
							ju.puntuacion = ju.puntuacion + 10;
							entornoPonerPuntuacion(ju.puntuacion);

						} else {
							entornoPausa(0.5);
							entornoFichaReves(i, j);
							entornoFichaReves(fila, col);
							modificarEstado(ju.tabler, i, j);
							modificarEstado(ju.tabler, fila, col);
						}
					}

				}
			}

			break;
		case TDerecha:
			entornoDesactivarCelda(fila, col);
			if (col < obtenerTamano(ju.tabler) - 1)
				col++;
			entornoActivarCelda(fila, col);
			break;
		case TIzquierda:
			entornoDesactivarCelda(fila, col);
			if (col > 0)
				col--;
			entornoActivarCelda(fila, col);
			break;
		case TArriba:
			entornoDesactivarCelda(fila, col);
			if (fila > 0)
				fila--;
			entornoActivarCelda(fila, col);
			break;
		case TAbajo:
			entornoDesactivarCelda(fila, col);
			if (fila < obtenerTamano(ju.tabler) - 1)
				fila++;
			entornoActivarCelda(fila, col);
			break;
		case TX:

			break;
		case TY:
			break;
		case TZ:
			break;
		case TSalir:
			salir = true;
			break;
		case TNada:
			break;
		} //acaba el switch
	} // acaba el while
}
void terminar(juego &ju) {
	string mensaje; //almacena los diferentes mensajes que aparecen durante la ejecución, rol: valor fijo
	mensaje = "                 ¡¡¡Hasta luego Lucas!!!";
	entornoMostrarMensajeFin(mensaje);
	entornoPausa(1);
	entornoTerminar();

}
