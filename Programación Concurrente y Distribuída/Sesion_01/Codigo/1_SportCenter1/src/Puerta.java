public class Puerta extends Thread {
	int id;
	int aforo;
	int i = 0;
	// contador will be shared among all the instances of Puerta class
	static double contador=0;
		
	public Puerta (int _id, int _aforo) {
		id = _id;
		aforo = _aforo;
		contador = 0;
	}
	
	public void run () {
		while (contador < aforo) {
			// an spectator enters
			contador++;
			i++;
		}
		System.out.println ("Through the door " + id + " have passed  " + i + " and contador is: "+contador);
	}
}