
public class Puerta {

	public Puerta() {

	}

	public synchronized void entrar(Barco b) {

		System.out.println("El barco " + b.getIdentificador() + " entra");
		System.out.println("El barco " + b.getIdentificador() + " entra");
		System.out.println("El barco " + b.getIdentificador() + " entra");

	}

	public synchronized void salir(Barco b) {

		System.out.println("El barco " + b.getIdentificador() + " sale");
		System.out.println("El barco " + b.getIdentificador() + " sale");
		System.out.println("El barco " + b.getIdentificador() + " sale");

	}

}
