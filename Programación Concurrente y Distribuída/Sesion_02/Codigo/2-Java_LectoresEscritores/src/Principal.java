
public class Principal {

	public static void main(String[] args) {

		final int num = 5;
		
		Buffer b = new Buffer();
		
		for (int i = 0; i < num; i++) {
			new Thread(new Lector(i, b)).start();
			new Thread(new Escritor(i, b)).start();
		}
	}

}
