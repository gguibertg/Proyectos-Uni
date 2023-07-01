/* Para evitar el interbloqueo. */

public class Contador {
	int cont;
	int tope;
	
	Contador (int tope) {
		cont = 0;
		this.tope = tope;
	}
	
	synchronized public void inc (int i){
		while (cont == tope) {
			System.out.println("El filósofo "+i+ "se bloquea en el contador ....");
			try {
				wait();
			} catch (InterruptedException e) {}
		}
			
		cont++;
	}
	
	synchronized public void dec() {
		cont--;
		notifyAll();
	}
	
	synchronized public int valor() {
		return cont;
	}
}