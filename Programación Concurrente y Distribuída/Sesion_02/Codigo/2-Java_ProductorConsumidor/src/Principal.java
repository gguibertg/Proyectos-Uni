
public class Principal {

	public static void main(String[] args) {

		Buffer b = new Buffer(3);
		
		for(int i = 0; i < 3; i++) {
			new Productor(b).start();
			new Consumidor(b).start();
		}
	}

}
