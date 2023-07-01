
public class Escritor implements Runnable {
	int quienSoy;
	Buffer buffer;
	
	public Escritor (int quienSoy, Buffer buffer) {
		this.quienSoy = quienSoy;
		this.buffer = buffer;
	}
	
	public void run () {
		for (int i = 0; i < 20; i++) {
			buffer.escribir(i,quienSoy);
			try {Thread.sleep(1000); } catch (InterruptedException e) {}
		}
	}
}
