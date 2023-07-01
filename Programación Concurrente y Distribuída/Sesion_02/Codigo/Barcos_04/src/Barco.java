
public class Barco extends Thread {

	int direccion;
	int id;
	Puerta p;
	TorreDeControl tC;

	public Barco(int direccion, int id, Puerta p, TorreDeControl tC) {

		this.direccion = direccion;
		this.id = id;
		this.p = p;
		this.tC = tC;

	}

	public void run() {

		if (direccion == 0) {
			tC.permisoEntrada(this);
			p.entrar(this);
			tC.finEntrada(this);
			}
		
		if(direccion == 1) {
			tC.permisoSalida(this);
			p.salir(this);
			tC.finSalida(this);
		}
	}

}
