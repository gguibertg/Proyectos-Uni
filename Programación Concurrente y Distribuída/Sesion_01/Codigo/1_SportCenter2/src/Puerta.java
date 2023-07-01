
public class Puerta extends Thread {
	int id;
	int aforo;
	int i = 0;
	static int contador;
	
	public Puerta (int _id, int _aforo) {
		id = _id;
		aforo = _aforo;
	}
	
	public void run () {
		while (i < aforo/2) {
			// An spectator enters
			contador++;
			i++;
		}
		System.out.println ("Through the door " + id + " haved passed " + i+", but contador is: "+contador);
	}
}