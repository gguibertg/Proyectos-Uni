
public class Barco extends Thread {

	int direccion;
	int id;
	Puerta p;

	public Barco(int direccion, int id, Puerta p) {

		this.direccion = direccion;
		this.id = id;
		this.p = p;

	}

	public void run() {

		if (direccion == 0) {
			p.entrar(this);
		}
		
		if(direccion == 1) {
			p.salir(this);
		}
	}

}
