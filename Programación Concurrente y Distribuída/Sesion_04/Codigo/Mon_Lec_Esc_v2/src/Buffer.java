/* Buffer. Sección crítica.
 * Se accede en E.M. usando la clase ReentrantReadWriteLock de java
 */

import java.util.concurrent.locks.*;

public class Buffer {

	int mem;
	int numLec = 0; // Comprobación de número de lectores leyendo
	int numEsc = 0; // Comprobación de número de escritores escribiendo
	
	ReadWriteLock mutex = new ReentrantReadWriteLock();      // E.M. para actualizar vbles.

	public Buffer () {
	}

	public void escribir (int elemento, int id) {
		/* Entrada en la s.c. */
		mutex.writeLock().lock();
		try {
			/* s.c. */
			numEsc++;
			System.out.println("Escribiendo valor "+elemento+" el escritor  "+id);
			mem = elemento;
			try {Thread.sleep(500); } catch (InterruptedException e) {}
			if (numEsc > 1)
				System.out.print("ERROR: Demasiados escritores escribiendo a la vez");
		}
		/* Salida de la s.c. */
		finally  {
			numEsc--;
			mutex.writeLock().unlock();
		}
	}
		
	public int leer (int id) {
		int elem = -1;
		
		/* Entrada en la s.c. */
		mutex.readLock().lock();
		try {
			/* s.c. */
			numLec++;
			elem = mem;
			System.out.println("Leyendo el elemnto "+elem + " el lector "+ id);

			try {Thread.sleep(100); } catch (InterruptedException e) {}
			if (numLec > 1)
				System.out.println("Acceso concurrente de lectores");

			return elem;	
	    } 
		/* Salida de la s.c. */
		finally {
			numLec--;
			mutex.readLock().unlock();
		}
	}
}
