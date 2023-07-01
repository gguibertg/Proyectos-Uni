
public class Ensalada {
	public Ensalada() {
	}

	public synchronized void coger(int i) {
		System.out.println("Comensal " + i + " cogiendo ensalada");
		System.out.println("Comensal " + i + " cogiendo ensalada");
		System.out.println("Comensal " + i + " cogiendo ensalada");
	}

}
