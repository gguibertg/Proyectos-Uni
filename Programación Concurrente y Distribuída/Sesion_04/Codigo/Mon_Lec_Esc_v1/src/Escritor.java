
public class Escritor implements Runnable {
	int quienSoy;
	Buffer buffer;
	
	public Escritor (int quienSoy, Buffer buffer) {
		this.quienSoy = quienSoy;
		this.buffer = buffer;
	}
	
	public void run () {
		for (int i = 0; i < 5; i++) { 
			try {
				buffer.escribir(quienSoy);
			} catch (InterruptedException e) {}
		}
	}
}
