
public class Puerta {

	public Puerta() {

	}

	public synchronized void entrar(Barco b) {

		System.out.println("El barco " + b.getId() + " entra");
		System.out.println("El barco " + b.getId() + " entra");
		System.out.println("El barco " + b.getId() + " entra");

	}

	public synchronized void salir(Barco b) {

		System.out.println("El barco " + b.getId() + " sale");
		System.out.println("El barco " + b.getId() + " sale");
		System.out.println("El barco " + b.getId() + " sale");

	}

}
