
public class Consumidor extends Thread {

	Buffer buffer;
	
	public Consumidor (Buffer buffer) {
		this.buffer = buffer;
	}
	
	public void run () {
		int elemento;
		for (int i = 0; i < 10; i++)
			 elemento = buffer.quitar();		
	}
}
