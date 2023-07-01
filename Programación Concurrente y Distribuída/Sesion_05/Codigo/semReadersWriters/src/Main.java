
import java.util.concurrent.*;

public class Main {

	public static void main (String args[]) {
		Semaphore writer = new Semaphore(1);
	for (int i=0;i<5;i++) 
		new Lector(i,writer).start();
	for (int i=0;i<5;i++) 
		new Escritor (i,writer).start();
	}
}
