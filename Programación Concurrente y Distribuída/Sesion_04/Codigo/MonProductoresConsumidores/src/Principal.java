/* Productor/Consumidor con monitores de Java   */

public class Principal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		/* Se crea el buffer que implementa la sección crítica */
		Buffer controlador = new Buffer ();

		/* Creando los hilos productores y consumidores */
		for (int i=0;i<3;i++) {
			new Thread (new Productor (i,controlador)).start();
			new Thread (new Consumidor (i,controlador)).start();
		}
	}
}
