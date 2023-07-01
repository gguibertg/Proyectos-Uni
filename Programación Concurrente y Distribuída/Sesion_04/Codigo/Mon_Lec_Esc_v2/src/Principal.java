/* Lectores/Escritores v2.0 con monitores de Java 
 * Se usa la clase ReentrantReadWriteLock, con lo que no necesitamos variables de
 * condición porque los locks que implementa esta clase están orientados a este tipo de
 * problemas:
 * 	- ReadLock:  Lock que permite el acceso concurrente de varios hilos (lectores)
 *  - WriteLock: Lock que obliga a un acceso excluyente (escritores)
 *  
 * Se han introducido algunos sleep() para comprobar mejor en la salida que funciona de 
 * forma correcta
 */

public class Principal {
	/**
	 * @param args
	 */
	public static void main(String[] args) {

		/* Creamos el recurso compartido */
		Buffer controlador = new Buffer ();

		/* Creación de los hilos */
		for (int i=0;i<3;i++) {
			new Thread (new Escritor (i,controlador)).start();
			new Thread (new Lector (i,controlador)).start();
		}
	}
}
