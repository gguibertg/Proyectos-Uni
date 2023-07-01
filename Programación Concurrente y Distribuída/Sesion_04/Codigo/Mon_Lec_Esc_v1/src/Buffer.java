/* Buffer. Sección crítica.
 * Se accede en E.M. usando monitores de Java 
 */

import java.util.concurrent.locks.*;

public class Buffer {

	int mem;
	
	int numLec = 0;    // Número de lectores dentro
	int numLecEsp = 0; // Número de lectores esperando por entrar
	boolean escribiendo = false;

	final Lock mutex = new ReentrantLock();      // E.M. para actualizar vbles.
	final Condition esc = mutex.newCondition();  // Escritor espera para escribir
	final Condition lee = mutex.newCondition();  // Lector espera para leer

	public Buffer () {
	}

	public void escribir (int elemento) throws InterruptedException {
		/* Entrada en la s.c. */
		mutex.lock();
		try {
			while ((numLec > 0) || (escribiendo)) {
				System.out.println ("Escritor "+elemento +" se va a bloquear");
				esc.await();
			}
			escribiendo = true;
		}
		finally {mutex.unlock();} 

		/* s.c. */
		System.out.println("Escribiendo valor "+elemento+" ... ");
		System.out.println("Escribiendo valor "+elemento+" ... ");
		System.out.println("Escribiendo valor "+elemento+" ... ");
		mem = elemento;
		/* Salida de la s.c. */

		mutex.lock();
		try {	
			escribiendo = false;
			if (numLecEsp == 0) {
				System.out.println ("Escritor que sale despierta a escritor, si lo hay");
				esc.signal();
			}
			else {
				lee.signal();
				System.out.println ("Escritor que sale despierta a lector, si lo hay");
			}
		} 
		finally	{mutex.unlock();}
	}
		
	public int leer (int quienSoy) throws InterruptedException {
		int elem = -1;
		
		/* Entrada en la s.c. */
		mutex.lock();
		try {
			while (escribiendo) {
				numLecEsp++;
				System.out.println ("lector "+quienSoy+" bloqueado porque hay escritor. Lectores esperando : "+numLecEsp);
				lee.await();
				numLecEsp--;
			}
			numLec++;
			lee.signal(); // desbloqueo encadenado
		} 
		finally {mutex.unlock();}
		
		/* s.c. */
		System.out.println("Leyendo el lector "+quienSoy + " el elemento "+mem);
		System.out.println("Leyendo el lector "+quienSoy + " el elemento "+mem);
		System.out.println("Leyendo el lector "+quienSoy + " el elemento "+mem);
		elem = mem;
		/* Salida de la s.c. */
		
		mutex.lock();
		try {
			numLec--;
			if (numLec == 0) {
				System.out.println ("Lector que sale despierta a escritor, si lo hay");
				esc.signal();
			}
		}
		finally {mutex.unlock();}
		return elem;
	}
}
