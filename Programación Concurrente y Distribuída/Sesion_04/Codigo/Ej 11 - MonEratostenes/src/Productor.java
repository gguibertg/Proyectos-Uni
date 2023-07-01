
public class Productor implements Runnable {
	Dato dato;
	
	public Productor (Dato _dato) {
		dato = _dato;
	}
	
	public void run () {
		int i=2;
		while (true) {
			System.out.println("Produciendo: "+i);
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			dato.poner (i);
			i++;
		}
	}
}
