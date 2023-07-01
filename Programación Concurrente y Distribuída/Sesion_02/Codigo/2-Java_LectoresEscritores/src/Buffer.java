
public class Buffer {

	int numLec; // Number of readers reading
	Boolean escribiendo; // Indicates if there is a writer writing
	
	int mem = -1; 
	
	public Buffer () {
		numLec      = 0;
		escribiendo = false;
	}
	
	public void escribir (int quien, int elem) {
		/* Entry protocol. */
		synchronized (this) {
			// If there is somone reading or writing I must wait
			while (escribiendo || (numLec > 0))
				try {
					wait();
				} catch (InterruptedException e) {}
			escribiendo = true;
		}
		
		/* c.s. */
		System.out.println("Escribiendo el escritor " + quien + " el valor "+elem);
		try {Thread.currentThread().sleep (10);}
		catch (Exception e) {;}
		System.out.println("Escribiendo el escritor " + quien + " el valor "+elem);
		try {Thread.currentThread().sleep (10);}
		catch (Exception e) {;}
		System.out.println("Escribiendo el escritor " + quien + " el valor "+elem);
		mem = elem;
		
		/* Exit protocol from c.s. */
		synchronized (this) {
			escribiendo = false;
			notifyAll();
		}
	}
	
	public int leer (int quien) {
		int elem = -1;
		
		/* Entry protocol */
		synchronized (this) {
			// If there is someone writing I must wait
			while (escribiendo) {
				try {
					wait();
				} catch (InterruptedException e) {}
			}
			numLec++;
		}
		
		/* c.s. */
		System.out.println("Leyendo el lector "+quien+ " el valor: "+mem);
		try {Thread.currentThread().sleep (10);}
		catch (Exception e) {;}
		System.out.println("Leyendo el lector "+quien+ " el valor: "+mem);
		try {Thread.currentThread().sleep (10);}
		catch (Exception e) {;}
		System.out.println("Leyendo el lector "+quien+ " el valor: "+mem);
		elem = mem;
		
		/* Exit protocol */
		synchronized (this) {
			numLec--;
			if (numLec == 0)
				notifyAll();
		}
		return elem;
	}
}
