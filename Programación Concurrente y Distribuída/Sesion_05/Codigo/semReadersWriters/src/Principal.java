
import java.util.concurrent.*;

public class Principal {

	public static void main (String args[]) {
		Semaphore escritor = new Semaphore(1);
	for (int i=0;i<5;i++) 
		new Lector(i,escritor).start();
	for (int i=0;i<5;i++) 
		new Escritor (i,escritor).start();
	}
}
