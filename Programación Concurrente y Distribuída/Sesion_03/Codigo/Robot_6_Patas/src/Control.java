
public class Control {
	int patasMoviendose = 0;
	int patasMovidas = 0;
	boolean patas[] = new boolean [6];
	
	public Control () {
		for (int i=0; i<6;i++)
			patas[i] = false;
	}
	
	public synchronized void puedoMover (int id) {
		while ((patasMoviendose == 2)||(patas[id] == true)) // Condición para bloqueo
			try {
				wait();
			} catch (Exception e) {;}
		patasMoviendose++; // Actualizando el estado del controlador
	}
	
	public synchronized void finMover (int id) {
		// actualizando el estado del controlador
		patas[id] = true;
		patasMoviendose--;
		patasMovidas++; 
		// verificando si el cambio de estado afecta a threads bloqueados
		if (patasMovidas == 6) {
			patasMovidas = 0;
			for (int i=0; i<6;i++)
				patas[i]=false;
			System.out.println("\n**** NUEVO CICLO ****");
		}
		for (int i=0;i<6;i++) {
			System.out.print(patas[i]+" ");
		}
		notifyAll(); // Al menos una condición ha cambiado (patasMoviendose). He de despertar a todos. 	

	}
}