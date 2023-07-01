import java.util.concurrent.locks.*;

/* MONITOR Aire. Los �tomos llaman al m�todo "quieroCombinar()" y se preparan para formar
 *               una mol�cula de agua. 
 */
public class Aire {

	private int atomosEnMolecula   = 0;
	private boolean[] molecula = {false, false, false}; // Molecula de Agua vac�a (H-H-O)
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
		
			/* 1. Un �tomo quiere combinar */
			/* 1.1. Si es de Oxigeno ira en la posici�n 2 de la molecula. Si la posici�n est�
			 *      ocupada entonces es que hay una mol�cula en formaci�n esperando por hidr�genos y espera.
			 */
			if (queSoy == true) { // es de ox�geno
				while (molecula[2] == true) // ya hay otro �tomo de ox�geno que va a formar parte de esta mol�cula
					try { enaireO.await(); } catch (InterruptedException e) {}
				molecula[2] = true;
			}
			/* 1.2. Si es de Hidr�geno ir� en la posici�n 0 o 1 */
			else {              
				while ((molecula[0] == true) && (molecula[1] == true)) // Ya hay 2 hidr�genos esperando por un ox�geno
					try { enaireH.await(); } catch (InterruptedException e) {}
				if (molecula[0] == false)
					molecula[0] = true;
				else 
					molecula[1] = true;
			}
		
			/* 2. El �tomo va a formar parte de una mol�cula */
			atomosEnMolecula++;
		
			/* 3. Si ya hay 3 �tomos en la mol�cula, despierto a los otros dos y terminan, si no
			 *    espero a que lleguen mis otros compa�eros de mol�cula 
			 */
			if (atomosEnMolecula < 3)
				try { combinando.await(); } catch (InterruptedException e) {}
			else {
				System.out.println("Molecula completa: " + ++numMoleculas);
				combinando.signal();
				combinando.signal();
			} 
		
			/* 4. La mol�cula de agua se ha formado. */
			atomosEnMolecula--;

			/* 5. El �ltimo �tomo de la mol�cula debe despertar m�s �tomos en el aire para que formen
			 * m�s mol�culas nuevas
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
