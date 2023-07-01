
public class Consumidor implements Runnable {
	Dato dato;
	
	public Consumidor (Dato _dato) {
		dato = _dato;
	}
	
	public void run () {
		while (true) {
			System.out.println("Candidato a primo: "+dato.coger());
		}
	}
}
