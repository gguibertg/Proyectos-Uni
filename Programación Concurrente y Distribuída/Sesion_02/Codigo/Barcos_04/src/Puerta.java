
public class Puerta {

	public Puerta() {

	}

	public synchronized void entrar(Barco b) {

		System.out.println("El barco " + b.id + " entra");
		System.out.println("El barco " + b.id + " entra");
		System.out.println("El barco " + b.id + " entra");

	}

	public synchronized void salir(Barco b) {
		
		System.out.println("El barco " + b.id + " sale");
		System.out.println("El barco " + b.id + " sale");
		System.out.println("El barco " + b.id + " sale");

	}

}
