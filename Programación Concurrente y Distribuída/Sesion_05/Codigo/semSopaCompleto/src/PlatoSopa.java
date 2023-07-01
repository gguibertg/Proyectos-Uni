import java.util.concurrent.Semaphore;

public class PlatoSopa {
	int [] cantidad = new int[5];
	Semaphore [] waiter = new Semaphore [5];
	Semaphore [] full = new Semaphore[5];
	Semaphore mutex =  new Semaphore (1);
	
	public PlatoSopa () {
		for (int i=0; i<5;i++) {
			waiter[i] = new Semaphore (0);
			full[i]=new Semaphore (0);
			cantidad[i]=3; // Considero una cantidad de 3 cucharadas por plato
		}
	}
	
	public void coger (int i) {
		cantidad[i] --;
		if (cantidad[i] ==0) {
			waiter[i].release();
			try {
				full[i].acquire();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println ("Comensal " + i+ " cogiendo y cantidad vale: "+cantidad[i]);
	}
	
	public  void llenar () {
		for (int i=0;i<5;i++) {
			try {
				waiter[i].acquire ();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println("CAMARERO DESPERTADO");
		for (int i=0;i<5;i++){
			cantidad [i] = 3;
			System.out.println ("Camarero llenando plato de comensal "+i);
			full[i].release ();
		}
	}
}
