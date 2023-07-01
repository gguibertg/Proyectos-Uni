/* Misioneros v1.0
 * 
 * Una tribu de Caníbales come Misioneros que se cocinan en una Olla. En esta pot caben un
 * número limitado de Misioneros y cuando los Salvajes han terminado con ellos se lo hacen
 * saber a un Chef que refull la Olla. Mientras el Chef está refullndo la pot
 * ningún Salvaje puede comer.
 * 
 */

import java.util.concurrent.*;

public class Main {
	// Version with the sempahore operations in the pot
	// Considering full a binary semaphore
	final static int CANNIBALS_NUMBER = 15;
	
	public static void main(String[] args) {

		Semaphore empty = new Semaphore(1); // empty initially
		Semaphore full = new Semaphore(0); 
		Pot pot = new Pot(full, empty);
		Chef c = new Chef(pot);
		Thread t = new Thread(c);
		t.start();
		
		for (int i = 0; i < CANNIBALS_NUMBER; i++) {
			new Thread(new Cannibal(i, pot)).start();
		}
	}
}
