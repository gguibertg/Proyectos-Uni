/* Buffer que implementa la secci�n cr�tica */

import java.util.concurrent.locks.*;

public class Buffer {
	int cuantos = 0;
	int N=2;
	int frente = 0;
	int cola = 0;
	int recurso [] = new int [N];
	
	/* Para la exclusi�n mutua */
	final Lock lock = new ReentrantLock(true);
	/* Variables de condici�n */
	final Condition lleno = lock.newCondition();
	final Condition vacio = lock.newCondition();

	public Buffer () {
	}

	public void insertar (int elemento) throws InterruptedException {
		/* Acceso a la s.c. */
		lock.lock();
		try {
			while (cuantos == N) 
				lleno.await(); // Si est� lleno me espero en la vble. de condicion
			
			/* s.c. */
			System.out.print("Insertando elemento "+elemento+" ... ");
			recurso[frente] = elemento;
			frente = (frente + 1) % N;
			cuantos++;
			System.out.println("OK");
			
			/* Se�alo la vble. de condici�n */
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
				vacio.await(); // Si est� vac�o me bloqueo en la vble. de condici�n
			
			/* s.c. */
			System.out.print("Extraigo elemento ... ");
			int result = recurso[cola];
			cola = (cola + 1) % N;
			cuantos--;
			System.out.println(result);
			
			/* Se�alo la vble. de condici�n */
			lleno.signal();
			return result;
	    } 
		/* Salida de la s.c. */
		finally {
			lock.unlock();
		}
	}
}
