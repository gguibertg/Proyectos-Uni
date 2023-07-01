public class Lector implements Runnable {
	int quienSoy;
	Buffer buffer;
	
	public Lector (int quienSoy, Buffer buffer) {
		this.quienSoy = quienSoy;
		this.buffer = buffer;
	}
	
	public void run () {
		for (int i = 0; i < 5; i++) { 
			try {
				buffer.leer(quienSoy);
			} catch (InterruptedException e) {}
		}
	}
}
