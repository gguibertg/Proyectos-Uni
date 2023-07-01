
public class Camarero extends Thread {

	PlatoSopa  platoSopa;
	
	public Camarero (PlatoSopa _platoSopa) {
		platoSopa = _platoSopa;	
	}
	public void run () {
		while (true) {
			platoSopa.llenar();
		}
	}
}