import java.util.concurrent.locks.*;

/* MONITOR Aire. Los átomos llaman al método "quieroCombinar()" y se preparan para formar
 *               una molécula de agua. 
 */
public class Aire {

	private int atomosEnMolecula   = 0;
	private boolean[] molecula = {false, false, false}; // Molecula de Agua vacía (H-H-O)
	private Lock mon;
	private Condition enaireO;
	private Condition enaireH;
	private Condition combinando;
	private int numMoleculas = 0;
	
	public Aire () {
		mon = new ReentrantLock();
		enaireO = mon.newCondition();
		enaireH = mon.newCondition();
		combinando = mon.newCondition();
	}
	
	public void quieroCombinar (boolean queSoy, int id) {
		
		mon.lock();
		try {
		
			/* 1. Un átomo quiere combinar */
			/* 1.1. Si es de Oxigeno ira en la posición 2 de la molecula. Si la posición está
			 *      ocupada entonces es que hay una molécula en formación esperando por hidrógenos y espera.
			 */
			if (queSoy == true) { // es de oxígeno
				while (molecula[2] == true) // ya hay otro átomo de oxígeno que va a formar parte de esta molécula
					try { enaireO.await(); } catch (InterruptedException e) {}
				molecula[2] = true;
			}
			/* 1.2. Si es de Hidrógeno irá en la posición 0 o 1 */
			else {              
				while ((molecula[0] == true) && (molecula[1] == true)) // Ya hay 2 hidrógenos esperando por un oxígeno
					try { enaireH.await(); } catch (InterruptedException e) {}
				if (molecula[0] == false)
					molecula[0] = true;
				else 
					molecula[1] = true;
			}
		
			/* 2. El átomo va a formar parte de una molécula */
			atomosEnMolecula++;
		
			/* 3. Si ya hay 3 átomos en la molécula, despierto a los otros dos y terminan, si no
			 *    espero a que lleguen mis otros compañeros de molécula 
			 */
			if (atomosEnMolecula < 3)
				try { combinando.await(); } catch (InterruptedException e) {}
			else {
				System.out.println("Molecula completa: " + ++numMoleculas);
				combinando.signal();
				combinando.signal();
			} 
		
			/* 4. La molécula de agua se ha formado. */
			atomosEnMolecula--;

			/* 5. El último átomo de la molécula debe despertar más átomos en el aire para que formen
			 * más moléculas nuevas
			 */
			if (atomosEnMolecula == 0) { 
				for (int i = 0; i < 3; i++) 
					molecula[i] = false;
				enaireO.signal();
				enaireH.signal();
				enaireH.signal();
			}
		
		} finally {
			mon.unlock();
		}
	}
}
