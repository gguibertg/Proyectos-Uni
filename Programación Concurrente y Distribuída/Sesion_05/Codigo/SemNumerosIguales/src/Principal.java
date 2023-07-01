
public class Principal {

	public static void main(String[] args) {
		Numero[] numeros = new Numero[5];
		for (int i =0; i<5;i++) {
			numeros[i] =  new Numero (i%3,i,numeros);
		}
		for (int i =0; i<5;i++) {
			numeros[i].start();
		}
		for (int i =0; i<5;i++) {
			try {
				numeros[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			System.out.println ("terminado "+i);
		}
	}
}
