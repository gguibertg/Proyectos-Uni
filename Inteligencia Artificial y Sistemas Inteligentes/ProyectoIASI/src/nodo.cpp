/*
 * nodo.cpp
 *
 *  Created on: 11 mar. 2020
 *      Authors: Canito Rubio, Rafael
 *			 García Garay, Carlos	
 *			 Guiberteau García, Gabriel Fernando
 */

#include "nodo.h"

nodo::nodo() {

	padre = nullptr;
	movimiento = "";
	lHijos = new ListaPI<nodo*>;

}

nodo::nodo(nodo *padre, string movimiento) {

	this->padre = padre;
	this->movimiento = movimiento;
	this->lHijos = new ListaPI<nodo*>;

}

string nodo::getMovimiento() {

	return movimiento;

}

void nodo::iniciar(string nP) {

	ifstream flujo;
	string cad1;

	flujo.open("puzzle" + nP + ".txt");
	if (flujo.is_open()) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				getline(flujo, cad1, ',');
				m[i][j] = atoi(cad1.c_str());
			}

			getline(flujo, cad1);
			m[i][3] = atoi(cad1.c_str());
		}
	}

}

int nodo::getCeros(int i) {
	return posCeros[i];
}

void nodo::localizarCeros() {
	int x = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (this->m[i][j] == 0) {
				this->posCeros[x] = i;
				x++;
				this->posCeros[x] = j;
				x++;
			}
		}
	}
}
void nodo::getPosReal(int n, int &x, int &y) {
	int cont = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (cont == n) {
				x = i;
				y = j;
			}
			cont++;
		}
	}
}
int nodo::getHp() {
	int hp = 0;
	int dif;
	int cont = 1;
	int x;
	int y;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m[i][j] != cont && m[i][j] != 0) {
				getPosReal(m[i][j], x, y);
				dif = fabs(x - i) + fabs(y - j);
				hp = hp + dif;
			}
			cont++;
		}
	}

	return hp;
}

void nodo::escaladaSimple(int i, int j, nodo* &h, int &nMovimientos,
		int &nNodos) {

	bool sol = false;
	TipoMatriz mAux;
	TipoVector fallidos;
	TipoVector fail;
	int b = 0;

	for (int i = 0; i < 4; i++) {
		fallidos[i] = 1; //actualizar fallidos
		fail[i] = -1;
		for (int j = 0; j < 4; j++) {
			mAux[i][j] = m[i][j];
		}

	}
	string movAux;

	if (getHp() > 0) {

		while (!sol) {

			srand(time(NULL));
			int r = rand() % 4;
			bool esta = false;
			for (int i = 0; i < 4; i++) {
				if (fail[i] == r) {
					esta = true;
				}
			}

			int cont = 0;

			for (int i = 0; i < 4; i++) {
				if (fail[i] == 0) {
					cont++;
				}
				if (fail[i] == 1) {
					cont++;
				}
				if (fail[i] == 2) {
					cont++;
				}
				if (fail[i] == 3) {
					cont++;
				}
			}

			if (cont == 4) {
				sol = true;
				cout << "No encuentro solucion" << endl;
			}

			if (!esta) {

				if (r == 0) {
					fail[b] = r;
					b++;
					if (j > 0 && fallidos[0] != 0) { //mover el 0 hacia izq
						mAux[i][j] = mAux[i][j - 1];
						mAux[i][j - 1] = 0;
						movAux = to_string(mAux[i][j]) + " E";
						fallidos[0] = 0;

						h = new nodo(this, movAux);
						nNodos++;
						for (int i = 0; i < 4; i++) {
							for (int j = 0; j < 4; j++) {
								h->cambiarVCelda(i, j, mAux[i][j]);

							}
						}

						if (h->getHp() >= getHp()) {
							for (int i = 0; i < 4; i++) {
								for (int j = 0; j < 4; j++) {
									mAux[i][j] = m[i][j];

								}
							}
							sol = false;
							delete h;
							h = nullptr;

						} else {
							sol = true;
							nMovimientos++;
							cout << h->getMovimiento() << endl;

							h->localizarCeros();

							srand(time(NULL));

							// Si el primer 0 esta colocado, llama al algoritmo con el segundo y viceversa
							// Si ninguno de los 2 esta colocado, llama a uno de forma aleatoria

							int r2 = rand() % 2;
							if (((h->getCeros(0) == 3) && (h->getCeros(1) == 2))
									|| ((h->getCeros(0) == 3)
											&& (h->getCeros(1) == 3))) {
								h->escaladaSimple(h->getCeros(2),
										h->getCeros(3), h, nMovimientos,
										nNodos);
							} else {

								if (((h->getCeros(2) == 3)
										&& (h->getCeros(3) == 2))
										|| ((h->getCeros(2) == 3)
												&& (h->getCeros(3) == 3))) {
									h->escaladaSimple(h->getCeros(0),
											h->getCeros(1), h, nMovimientos,
											nNodos);

								} else {

									if (r2 == 0) {
										h->escaladaSimple(h->getCeros(0),
												h->getCeros(1), h, nMovimientos,
												nNodos);
									} else {
										h->escaladaSimple(h->getCeros(2),
												h->getCeros(3), h, nMovimientos,
												nNodos);
									}
								}
							}
						}

					}
				} else {

					if (r == 1) {

						fail[b] = r;
						b++;

						if (i > 0 && fallidos[1] != 0) { //mover el 0 hacia arriba
							mAux[i][j] = mAux[i - 1][j];
							mAux[i - 1][j] = 0;
							movAux = to_string(mAux[i][j]) + " S";
							fallidos[1] = 0;

							h = new nodo(this, movAux);
							nNodos++;
							for (int i = 0; i < 4; i++) {
								for (int j = 0; j < 4; j++) {
									h->cambiarVCelda(i, j, mAux[i][j]);

								}
							}

							if (h->getHp() >= getHp()) {
								for (int i = 0; i < 4; i++) {
									for (int j = 0; j < 4; j++) {
										mAux[i][j] = m[i][j];

									}
								}

								sol = false;
								delete h;
								h = nullptr;

							} else {
								sol = true;
								nMovimientos++;
								cout << h->getMovimiento() << endl;

								h->localizarCeros();

								srand(time(NULL));
								int r2 = rand() % 2;
								if (((h->getCeros(0) == 3)
										&& (h->getCeros(1) == 2))
										|| ((h->getCeros(0) == 3)
												&& (h->getCeros(1) == 3))) {
									h->escaladaSimple(h->getCeros(2),
											h->getCeros(3), h, nMovimientos,
											nNodos);
								} else {

									if (((h->getCeros(2) == 3)
											&& (h->getCeros(3) == 2))
											|| ((h->getCeros(2) == 3)
													&& (h->getCeros(3) == 3))) {
										h->escaladaSimple(h->getCeros(0),
												h->getCeros(1), h, nMovimientos,
												nNodos);

									} else {

										if (r2 == 0) {
											h->escaladaSimple(h->getCeros(0),
													h->getCeros(1), h,
													nMovimientos, nNodos);
										} else {
											h->escaladaSimple(h->getCeros(2),
													h->getCeros(3), h,
													nMovimientos, nNodos);
										}
									}
								}
							}

						}
					} else {

						if (r == 2) {
							fail[b] = r;
							b++;

							if (j < 3 && fallidos[2] != 0) { //mover el 0 hacia der
								mAux[i][j] = mAux[i][j + 1];
								mAux[i][j + 1] = 0;
								movAux = to_string(mAux[i][j]) + " O";
								fallidos[2] = 0;

								h = new nodo(this, movAux);
								nNodos++;
								for (int i = 0; i < 4; i++) {
									for (int j = 0; j < 4; j++) {
										h->cambiarVCelda(i, j, mAux[i][j]);

									}
								}

								if (h->getHp() >= getHp()) {
									for (int i = 0; i < 4; i++) {
										for (int j = 0; j < 4; j++) {
											mAux[i][j] = m[i][j];

										}
									}
									sol = false;
									delete h;
									h = nullptr;
								} else {
									sol = true;
									nMovimientos++;
									cout << h->getMovimiento() << endl;

									h->localizarCeros();

									srand(time(NULL));
									int r2 = rand() % 2;
									if (((h->getCeros(0) == 3)
											&& (h->getCeros(1) == 2))
											|| ((h->getCeros(0) == 3)
													&& (h->getCeros(1) == 3))) {
										h->escaladaSimple(h->getCeros(2),
												h->getCeros(3), h, nMovimientos,
												nNodos);
									} else {

										if (((h->getCeros(2) == 3)
												&& (h->getCeros(3) == 2))
												|| ((h->getCeros(2) == 3)
														&& (h->getCeros(3) == 3))) {
											h->escaladaSimple(h->getCeros(0),
													h->getCeros(1), h,
													nMovimientos, nNodos);

										} else {

											if (r2 == 0) {
												h->escaladaSimple(
														h->getCeros(0),
														h->getCeros(1), h,
														nMovimientos, nNodos);
											} else {
												h->escaladaSimple(
														h->getCeros(2),
														h->getCeros(3), h,
														nMovimientos, nNodos);
											}
										}
									}
								}

							}
						} else {

							if (r == 3) {
								fail[b] = r;
								b++;

								if (i < 3 && fallidos[3] != 0) {

									mAux[i][j] = mAux[i + 1][j];
									mAux[i + 1][j] = 0;
									movAux = to_string(mAux[i][j]) + " N";
									fallidos[3] = 0;

									h = new nodo(this, movAux);
									nNodos++;
									for (int i = 0; i < 4; i++) {
										for (int j = 0; j < 4; j++) {
											h->cambiarVCelda(i, j, mAux[i][j]);

										}
									}

									if (h->getHp() >= getHp()) {
										for (int i = 0; i < 4; i++) {
											for (int j = 0; j < 4; j++) {
												mAux[i][j] = m[i][j];

											}
										}
										sol = false;
										delete h;
										h = nullptr;
									} else {
										sol = true;
										nMovimientos++;
										cout << h->getMovimiento() << endl;

										h->localizarCeros();

										srand(time(NULL));
										int r2 = rand() % 2;
										if (((h->getCeros(0) == 3)
												&& (h->getCeros(1) == 2))
												|| ((h->getCeros(0) == 3)
														&& (h->getCeros(1) == 3))) {
											h->escaladaSimple(h->getCeros(2),
													h->getCeros(3), h,
													nMovimientos, nNodos);
										} else {

											if (((h->getCeros(2) == 3)
													&& (h->getCeros(3) == 2))
													|| ((h->getCeros(2) == 3)
															&& (h->getCeros(3)
																	== 3))) {
												h->escaladaSimple(
														h->getCeros(0),
														h->getCeros(1), h,
														nMovimientos, nNodos);

											} else {

												if (r2 == 0) {
													h->escaladaSimple(
															h->getCeros(0),
															h->getCeros(1), h,
															nMovimientos,
															nNodos);
												} else {
													h->escaladaSimple(
															h->getCeros(2),
															h->getCeros(3), h,
															nMovimientos,
															nNodos);
												}
											}
										}
									}

								}
							}
						}
					}
				}
			}
		}
	}

}

void nodo::escaladaMaxPendiente(bool solucion, int &nMovimientos, int &nNodos) {

	if (!solucion) {
		localizarCeros();

		TipoMatriz mAux;
		string movAux;
		nodo *h;

		int i = getCeros(0);
		int j = getCeros(1);

		if (j > 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[i][j] = mAux[i][j - 1];
			mAux[i][j - 1] = 0;
			movAux = to_string(mAux[i][j]) + " E";

			h = new nodo(this, movAux);
			nNodos++;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}
			lHijos->insertar(h);
		}

		if (i > 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[i][j] = mAux[i - 1][j];
			mAux[i - 1][j] = 0;
			movAux = to_string(mAux[i][j]) + " S";

			h = new nodo(this, movAux);
			nNodos++;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}
			lHijos->insertar(h);
		}

		if (j < 3) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[i][j] = mAux[i][j + 1];
			mAux[i][j + 1] = 0;
			movAux = to_string(mAux[i][j]) + " O";

			h = new nodo(this, movAux);
			nNodos++;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}
			lHijos->insertar(h);
		}

		if (i < 3) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[i][j] = mAux[i + 1][j];
			mAux[i + 1][j] = 0;
			movAux = to_string(mAux[i][j]) + " N";

			h = new nodo(this, movAux);
			nNodos++;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}
			lHijos->insertar(h);
		}

		i = getCeros(2);
		j = getCeros(3);

		if (j > 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[i][j] = mAux[i][j - 1];
			mAux[i][j - 1] = 0;
			movAux = to_string(mAux[i][j]) + " E";

			h = new nodo(this, movAux);
			nNodos++;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}
			lHijos->insertar(h);
		}

		if (i > 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[i][j] = mAux[i - 1][j];
			mAux[i - 1][j] = 0;
			movAux = to_string(mAux[i][j]) + " S";

			h = new nodo(this, movAux);
			nNodos++;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}
			lHijos->insertar(h);
		}

		if (j < 3) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[i][j] = mAux[i][j + 1];
			mAux[i][j + 1] = 0;
			movAux = to_string(mAux[i][j]) + " O";

			h = new nodo(this, movAux);
			nNodos++;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}
			lHijos->insertar(h);
		}

		if (i < 3) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[i][j] = mAux[i + 1][j];
			mAux[i + 1][j] = 0;
			movAux = to_string(mAux[i][j]) + " N";

			h = new nodo(this, movAux);
			nNodos++;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}
			lHijos->insertar(h);
		}

		nodo *aux;
		int hpMin = 999;

		while (!lHijos->finLista()) {
			lHijos->consultar(aux);
			if (aux->getHp() < hpMin) {
				hpMin = aux->getHp();
			}
			lHijos->avanzar();
		}

		if (this->getHp() <= hpMin) {
			cout << "No encuentra solucion" << endl;
			escaladaMaxPendiente(true, nMovimientos, nNodos);
		} else {

			lHijos->moverInicio();

			bool enc = false;
			while (!lHijos->finLista() && !enc) {
				lHijos->consultar(aux);
				if (aux->getHp() == hpMin) {
					if (aux->getHp() == 0) {
						enc = true;
						cout << aux->movimiento << endl;
						nMovimientos++;
						aux->escaladaMaxPendiente(true, nMovimientos, nNodos);

					} else {
						enc = true;
						cout << aux->movimiento << endl;
						nMovimientos++;
						aux->escaladaMaxPendiente(false, nMovimientos, nNodos);
					}
				}
				lHijos->avanzar();

			}
		}
	}
}

void nodo::primeroMejor(int &nMovimientos, ListaPI<nodo*> *& lAbiertos,
		ListaPI<nodo*> *& lCerrados, int &nNodos) {

	if (getHp() > 0) {

		localizarCeros();

		TipoMatriz mAux;
		string movAux;
		nodo *h;

		int x = getCeros(0);
		int y = getCeros(1);

		if (y > 0 && m[x][y - 1] != 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[x][y] = mAux[x][y - 1];
			mAux[x][y - 1] = 0;
			movAux = to_string(mAux[x][y]) + " E";

			h = new nodo(this, movAux);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}

			if (!yaInsertado(h, lAbiertos)) {
				nodo *aux;
				bool enc = false;

				lAbiertos->moverInicio();
				while (!lAbiertos->finLista() && !enc) {
					lAbiertos->consultar(aux);
					if (aux->getHp() > h->getHp()) {
						enc = true;
					} else {
						lAbiertos->avanzar();
					}
				}
				if (!yaInsertado(h, lCerrados)) {
					lAbiertos->insertar(h);
					nNodos++;
				}
			}

		}

		if (x > 0 && m[x - 1][y] != 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[x][y] = mAux[x - 1][y];
			mAux[x - 1][y] = 0;
			movAux = to_string(mAux[x][y]) + " S";

			h = new nodo(this, movAux);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}

			if (!yaInsertado(h, lAbiertos)) {
				nodo *aux;
				bool enc = false;

				lAbiertos->moverInicio();
				while (!lAbiertos->finLista() && !enc) {
					lAbiertos->consultar(aux);
					if (aux->getHp() > h->getHp()) {
						enc = true;
					} else {
						lAbiertos->avanzar();
					}
				}
				if (!yaInsertado(h, lCerrados)) {
					lAbiertos->insertar(h);
					nNodos++;
				}
			}

		}

		if (y < 3 && m[x][y + 1] != 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[x][y] = mAux[x][y + 1];
			mAux[x][y + 1] = 0;
			movAux = to_string(mAux[x][y]) + " O";

			h = new nodo(this, movAux);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}

			if (!yaInsertado(h, lAbiertos)) {
				nodo *aux;
				bool enc = false;

				lAbiertos->moverInicio();
				while (!lAbiertos->finLista() && !enc) {
					lAbiertos->consultar(aux);
					if (aux->getHp() > h->getHp()) {
						enc = true;
					} else {
						lAbiertos->avanzar();
					}
				}
				if (!yaInsertado(h, lCerrados)) {
					lAbiertos->insertar(h);
					nNodos++;
				}
			}

		}

		if (x < 3 && m[x + 1][y] != 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[x][y] = mAux[x + 1][y];
			mAux[x + 1][y] = 0;
			movAux = to_string(mAux[x][y]) + " N";

			h = new nodo(this, movAux);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}

			if (!yaInsertado(h, lAbiertos)) {
				nodo *aux;
				bool enc = false;

				lAbiertos->moverInicio();
				while (!lAbiertos->finLista() && !enc) {
					lAbiertos->consultar(aux);
					if (aux->getHp() > h->getHp()) {
						enc = true;
					} else {
						lAbiertos->avanzar();
					}
				}
				if (!yaInsertado(h, lCerrados)) {
					lAbiertos->insertar(h);
					nNodos++;
				}
			}

		}

		x = getCeros(2);
		y = getCeros(3);

		if (y > 0 && m[x][y - 1] != 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[x][y] = mAux[x][y - 1];
			mAux[x][y - 1] = 0;
			movAux = to_string(mAux[x][y]) + " E";

			h = new nodo(this, movAux);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}

			if (!yaInsertado(h, lAbiertos)) {
				nodo *aux;
				bool enc = false;

				lAbiertos->moverInicio();
				while (!lAbiertos->finLista() && !enc) {
					lAbiertos->consultar(aux);
					if (aux->getHp() > h->getHp()) {
						enc = true;
					} else {
						lAbiertos->avanzar();
					}
				}
				if (!yaInsertado(h, lCerrados)) {
					lAbiertos->insertar(h);
					nNodos++;
				}
			}

		}

		if (x > 0 && m[x - 1][y] != 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[x][y] = mAux[x - 1][y];
			mAux[x - 1][y] = 0;
			movAux = to_string(mAux[x][y]) + " S";

			h = new nodo(this, movAux);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}

			if (!yaInsertado(h, lAbiertos)) {
				nodo *aux;
				bool enc = false;

				lAbiertos->moverInicio();
				while (!lAbiertos->finLista() && !enc) {
					lAbiertos->consultar(aux);
					if (aux->getHp() > h->getHp()) {
						enc = true;
					} else {
						lAbiertos->avanzar();
					}
				}
				if (!yaInsertado(h, lCerrados)) {
					lAbiertos->insertar(h);
					nNodos++;
				}
			}

		}

		if (y < 3 && m[x][y + 1] != 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[x][y] = mAux[x][y + 1];
			mAux[x][y + 1] = 0;
			movAux = to_string(mAux[x][y]) + " O";

			h = new nodo(this, movAux);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}

			if (!yaInsertado(h, lAbiertos)) {
				nodo *aux;
				bool enc = false;

				lAbiertos->moverInicio();
				while (!lAbiertos->finLista() && !enc) {
					lAbiertos->consultar(aux);
					if (aux->getHp() > h->getHp()) {
						enc = true;
					} else {
						lAbiertos->avanzar();
					}
				}
				if (!yaInsertado(h, lCerrados)) {
					lAbiertos->insertar(h);
					nNodos++;
				}
			}

		}

		if (x < 3 && m[x + 1][y] != 0) {

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mAux[i][j] = m[i][j];
				}
			}

			mAux[x][y] = mAux[x + 1][y];
			mAux[x + 1][y] = 0;
			movAux = to_string(mAux[x][y]) + " N";

			h = new nodo(this, movAux);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					h->cambiarVCelda(i, j, mAux[i][j]);

				}
			}
			if (!yaInsertado(h, lAbiertos)) {

				nodo *aux;
				bool enc = false;

				lAbiertos->moverInicio();
				while (!lAbiertos->finLista() && !enc) {
					lAbiertos->consultar(aux);
					if (aux->getHp() > h->getHp()) {
						enc = true;
					} else {
						lAbiertos->avanzar();
					}
				}
				if (!yaInsertado(h, lCerrados)) {
					lAbiertos->insertar(h);
					nNodos++;
				}
			}

		}
		nodo *aux;

		lAbiertos->moverInicio();
		lAbiertos->consultar(aux);
		lAbiertos->borrar();
		while (yaInsertado(aux, lCerrados)) { //caso de que se hayan expandido (no expandimos y pasamos al siguiente)
			lAbiertos->consultar(aux);
			lAbiertos->borrar();
		}
		lCerrados->insertar(aux); //si no se ha expandido, lo expandimos
		aux->primeroMejor(nMovimientos, lAbiertos, lCerrados, nNodos);

	} else {
		solPrimeroMejor(this, nMovimientos);
	}

}

void nodo::solPrimeroMejor(nodo *n, int &nMovimientos) {

	if (n != nullptr && n->movimiento != "") {
		nMovimientos++;
		solPrimeroMejor(n->padre, nMovimientos);
		cout << n->movimiento << endl;
	}
}

bool nodo::matricesIguales(nodo *h, nodo *nAux) {

	bool iguales = true;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (h->getValorCelda(i, j) != nAux->getValorCelda(i, j)) {
				iguales = false;
			}

		}
	}
	return iguales;
}

int nodo::getValorCelda(int i, int j) {
	return m[i][j];
}

bool nodo::yaInsertado(nodo *h, ListaPI<nodo*> * lNodos) {

	bool esta = false;
	nodo *nAux;

	lNodos->moverInicio();
	while (!lNodos->finLista() && !esta) {
		lNodos->consultar(nAux);
		if (matricesIguales(h, nAux)) {
			esta = true;
		}
		lNodos->avanzar();
	}

	return esta;
}

void nodo::showMatriz() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << m[i][j];
		}
		cout << endl;

	}
}
void nodo::cambiarVCelda(int i, int j, int v) {
	m[i][j] = v;

}

nodo::~nodo() {
	padre = nullptr;
	lHijos->moverInicio();
	while (!lHijos->estaVacia()) {
		lHijos->borrar();
	}
	delete lHijos;
}

