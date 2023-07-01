/* Producer / Consumer v1.0
 * Implementa el problema del productor consumidor sincronizándose por semáforos
 * La sincronización se implementa en las clases Producer y Consumer
 */

import java.util.concurrent.*;

public class Main {
	/**
	 * @param args
	 */
	public static void main(String[] args) {

		Consumer consumers [] = new Consumer [3];
		Producer producers [] = new Producer [3];

		Semaphore mutex = new Semaphore (1);
		Semaphore empty = new Semaphore (3); // initially empty 
		Semaphore full = new Semaphore (0); 
		
		Buffer buffer = new Buffer (3);

		for (int i=0;i<3;i++) {
			producers [i]=new Producer (i,mutex,empty,full,buffer);
		    consumers[i]=new Consumer (i,mutex,empty,full,buffer);
		}

		for (int i=0;i<3;i++) {
			new Thread (producers [i]).start();
			new Thread (consumers [i]).start();
		}
	}
}
