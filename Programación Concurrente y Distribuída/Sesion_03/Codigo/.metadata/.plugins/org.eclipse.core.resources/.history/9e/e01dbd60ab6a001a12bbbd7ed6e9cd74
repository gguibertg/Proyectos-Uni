
public class Imprime {
	char anterior = 'C';
	public Imprime () {
		
	}
	
	public void imprimir (char letra) {
		synchronized (this) {
			while (((letra=='A')&&anterior!='C') ||
				((letra=='B')&&anterior!='A')||
				((letra=='C')&&(anterior!='B')))
					try {
						wait();
					}
					catch (Exception e) {e.printStackTrace();}
			System.out.println(letra);
			anterior = letra;
		    notifyAll();
		}
    }
}
