
public class Escritor implements Runnable {
	int quienSoy;
	Buffer buffer;
	
	public Escritor (int quienSoy, Buffer buffer) {
		this.quienSoy = quienSoy;
		this.buffer = buffer;
	}
	
	public void run () {
		for (int i = 0; i < 20; i++) { 
			buffer.escribir(quienSoy, i);
			if (i>10) {
				try {Thread.currentThread().sleep(0);
				}
				catch (Exception e) {e.printStackTrace();}
			}
		}
	}
}
