
public class Lector implements Runnable {
	int quienSoy;
	Buffer buffer;
	
	public Lector (int quienSoy, Buffer buffer) {
		this.quienSoy = quienSoy;
		this.buffer = buffer;
	}
	
	public void run () {
		for (int i = 0; i < 20; i++) { 
			buffer.leer(quienSoy);
			try {Thread.currentThread().sleep (0);}
			catch (Exception e) {;}
		}
	}
}
