import java.util.concurrent.*;

public class Principal {


	public static void main (String[] args) {
		Semaphore [] ciclo = new Semaphore [6];
		Pata patas[] = new Pata[6];
		System.out.println ("Comienzo del programa");
		for (int i=0;i<6;i++) {
			ciclo[i]= new Semaphore (1);
		}
		for (int i=0;i<6;i++) {
			patas[i] = new Pata (i, ciclo);
			patas[i].start();
		}
	}
}
