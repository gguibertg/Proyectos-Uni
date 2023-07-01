
// Considering all the semaphore operations in the Soap plate
// Considering five semaphores for the waiter to wait.

public class Principal {
	
	Comensal [] comensal = new Comensal [5];
	PlatoSopa platoSopa = new PlatoSopa();
	Camarero camarero = new Camarero (platoSopa);
	PlatoEnsalada platoEnsalada = new PlatoEnsalada();
	
	public Principal () {
		camarero.start();
		for (int i=0; i<5;i++) {
			comensal[i] = new Comensal(i, platoSopa, platoEnsalada);
			comensal[i].start();
		}
	}
	
	public static void main (String [] args) {
		new Principal();
	}
}
