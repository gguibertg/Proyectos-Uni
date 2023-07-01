
public class Control {
	int patasMoviendose = 0;
	int patasMovidas = 0;
	volatile boolean patas[] = new boolean [6];
	
	public Control () {
		for (int i=0; i<6;i++)
			patas[i] = false;
	}
	
	public synchronized void puedoMover (int id) {
		while ((patasMoviendose == 2)||(patas[id] == true))
			try {
				wait();
			} catch (Exception e) {;}
		patasMoviendose++;
	}
	
	public synchronized void finMover (int id) {
		patas[id] = true;
		patasMoviendose--;
		patasMovidas++; 
		if (patasMovidas == 6) {
			patasMovidas = 0;
			for (int i=0; i<6;i++)
				patas[i]=false;
		}
		notifyAll();	
	}
}