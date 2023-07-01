public class TorreDeControl {

	int entrando;
	int saliendo;
	int esperando;

	public TorreDeControl() {

		entrando = 0;
		saliendo = 0;
		esperando = 0;

	}

	public synchronized void permisoEntrada(Barco b) {

		while (saliendo > 0 || esperando > 0) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		entrando++;
	}

	public synchronized void finEntrada(Barco b) {

		entrando--;
		if (entrando == 0) {
			notifyAll();
		}

	}

	public synchronized void permisoSalida(Barco b) {

		while (entrando > 0) {
			try {
				esperando++;
				wait();
				esperando--;
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		saliendo++;
	}

	public synchronized void finSalida(Barco b) {

		saliendo--;
		if (saliendo == 0) {
			notifyAll();
		}

	}

}