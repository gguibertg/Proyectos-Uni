
public class Main {


	public static void main (String args[]) {
		int MAX_FILTROS = 10;
		Thread t;
		Dato [] datos = new Dato [MAX_FILTROS+1];
		
		for (int i=0; i<MAX_FILTROS+1;i++) {
			datos[i] = new Dato ();
		}
		Filtro[] filtros = new Filtro[MAX_FILTROS];
		for (int i=0;i<MAX_FILTROS;i++) {
			filtros[i] = new Filtro (datos[i], datos[i+1]);
			t = new Thread (filtros[i]);
			t.start();
		}
		Productor p = new Productor (datos[0]);
		t = new Thread (p);
		t.start();
		
		Consumidor c = new Consumidor (datos[MAX_FILTROS]);
		t = new Thread (c);
		t.start();
		
		
	}
}
