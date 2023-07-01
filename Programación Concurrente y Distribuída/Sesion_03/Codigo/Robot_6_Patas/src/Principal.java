
public class Principal {


	public static void main (String[] args) {
		Pata patas[] = new Pata[6];
		Control control = new Control ();
		System.out.println ("Comienzo del programa");
		for (int i=0;i<6;i++) {
			patas[i] = new Pata (i, control);
			patas[i].start();
		}
	}

}
