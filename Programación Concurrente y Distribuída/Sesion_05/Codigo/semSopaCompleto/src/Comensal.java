public class Comensal extends Thread {
	PlatoSopa platoSopa;
	int quienSoy;
	PlatoEnsalada platoEnsalada;

	public Comensal (int _quienSoy, PlatoSopa _platoSopa, PlatoEnsalada _platoEnsalada) {
		quienSoy = _quienSoy;
		platoSopa = _platoSopa;
		platoEnsalada = _platoEnsalada;
	}

	public void run () {
		while (true) {
			platoSopa.coger(quienSoy);
			platoEnsalada.coger (quienSoy);
		}
	}
}
