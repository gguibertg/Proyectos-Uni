
import java.util.concurrent.*;

public class PlatoEnsalada {
	Semaphore mutex = new Semaphore (1);
	
	public PlatoEnsalada () {
	
	}
	
	public void coger (int id) {
		try {
			mutex.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println("cogiendo ensalada el comensal "+id);
		System.out.println("cogiendo ensalada el comensal "+id);
		System.out.println("cogiendo ensalada el comensal "+id);
		
		mutex.release();
	}

}
