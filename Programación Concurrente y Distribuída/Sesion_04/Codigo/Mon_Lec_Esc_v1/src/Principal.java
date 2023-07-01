/* Lectores/Escritores con monitores de Java 
 * Prioridad: A los lectores 
 */

public class Principal {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		/* Creamos el buffer que implementa la s.c. */
		Buffer controlador = new Buffer ();

		/* Creación de los hilos */
		System.out.println ("Empieza el programa");
		for (int i=0;i<3;i++) {
			new Thread (new Escritor (i,controlador)).start();
			new Thread (new Lector (i,controlador)).start();
		}
	}
}
