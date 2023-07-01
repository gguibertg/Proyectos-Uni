public class Filosofo implements Runnable {
	Mesa mesa;
	int id;
	
	public Filosofo (Mesa _mesa, int _id) {
		mesa = _mesa;
		id = _id;
	}
		
	public void run () {
		for (int i=0;i<5;i++) {
			System.out.println ("Filosofo "+id+" pensando");
			try {Thread.sleep (1000);}
			catch (Exception e) {}
			mesa.coger (id);
			System.out.println ("Filosofo "+id+" comiendo");
			try {Thread.sleep (1000);}
			catch (Exception e) {}
			mesa.poner (id);
		}
	}
}
		
		