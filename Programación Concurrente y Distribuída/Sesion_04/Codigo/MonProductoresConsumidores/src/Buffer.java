/* Buffer que implementa la sección crítica */

import java.util.concurrent.locks.*;

public class Buffer {
	int cuantos = 0;
	int N=2;
	int frente = 0;
	int cola = 0;
	int recurso [] = new int [N];
	
	/* Para la exclusión mutua */
	final Lock lock = new ReentrantLock(true);
	/* Variables de condición */
	final Condition lleno = lock.newCondition();
	final Condition vacio = lock.newCondition();

	public Buffer () {
	}

	public void insertar (int elemento) throws InterruptedException {
		/* Acceso a la s.c. */
		lock.lock();
		try {
			while (cuantos == N) 
				lleno.await(); // Si está lleno me espero en la vble. de condicion
			
			/* s.c. */
			System.out.print("Insertando elemento "+elemento+" ... ");
			recurso[frente] = elemento;
			frente = (frente + 1) % N;
			cuantos++;
			System.out.println("OK");
			
			/* Señalo la vble. de condición */
			vacio.signal();
		}
		/* Salida de la s.c. */
		finally  {
			lock.unlock();
		}
	}
		
	public int extraer () throws InterruptedException {
		/* Acceso a la s.c. */
		lock.lock();
		try {
			while (cuantos == 0) 
				vacio.await(); // Si está vacío me bloqueo en la vble. de condición
			
			/* s.c. */
			System.out.print("Extraigo elemento ... ");
			int result = recurso[cola];
			cola = (cola + 1) % N;
			cuantos--;
			System.out.println(result);
			
			/* Señalo la vble. de condición */
			lleno.signal();
			return result;
	    } 
		/* Salida de la s.c. */
		finally {
			lock.unlock();
		}
	}
}
