
public class Buffer {

	// Cyclic buffer
	int[] mem;
	int cuantos;
	int tam;
	int frente;
	int cola;
	
	public Buffer (int tam) {
		mem      = new int[tam];
		cuantos  = 0;
		this.tam = tam;
		frente   = 0;
		cola     = 0;
	}
	
	public synchronized void poner(int elemento) {
		/* Entry protocol to c.s. */
		while (cuantos == tam)
			try {
				System.out.println ("Buffer lleno");
				wait();
			} catch (InterruptedException e) {}
						
		/* c.s. */
		System.out.println("Pongo elemento " + elemento);
		System.out.println("Pongo elemento " + elemento);
		System.out.println("Pongo elemento " + elemento);
		mem[frente] = elemento;
		frente = (frente + 1) % tam;
		cuantos++;
		/* Exit protocol from c.s. */
		notifyAll();
	}
	
	public synchronized int quitar() {
		int elem = -1;
		
		while (cuantos == 0)
			try {
				System.out.println ("Buffer vacío");
				wait();
			} catch (InterruptedException e) {}
			
		/* c.s. */
		elem = mem[cola];
		cola = (cola + 1) % tam;
		cuantos --;
		System.out.println("Extraigo elemento "+elem);
		System.out.println("Extraigo elemento "+elem);
		System.out.println("Extraigo elemento "+elem);
		
		/* Exit protocol from c.s. */
		notifyAll();
		return elem;
	}
}
