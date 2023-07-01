
public class Letra extends Thread {
	char letra;
	Imprime imp;
	
	public Letra (char _letra, Imprime _imp) {
		letra = _letra;
		imp=_imp;
	}
	
	public void run () {
		for (int i=0;i<100;i++) {
			imp.imprimir(letra);
		}
	}
}
