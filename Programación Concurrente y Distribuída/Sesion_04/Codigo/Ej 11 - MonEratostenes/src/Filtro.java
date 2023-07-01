
public class Filtro implements Runnable {
	Dato derecha, izquierda;
	
	public Filtro (Dato _izquierda, Dato _derecha) {
		derecha = _derecha;
		izquierda = _izquierda;
	}
	
	public void run () {
		int divisor = -1;
		int num = 0;
		while (true) {
			num = izquierda.coger();
			if (divisor ==-1) {
				divisor = num;
				System.out.println("Primo: "+num);
			}
			else 
				if ((num%divisor) !=0)
					derecha.poner(num); // Candidato a primo
			
		}
	}
}
