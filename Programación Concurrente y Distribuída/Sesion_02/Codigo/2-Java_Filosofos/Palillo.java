/* La clase palillo implementa dos funciones que se ejecutan en E.M. */

public class Palillo {
	boolean libre;
	int id;
	
	Palillo (int _id) {
		libre = true;
		id = _id;
	}
	
	 public synchronized void coger () {
		while (!libre) {
			try {
				wait();
				Thread.sleep(1000);
			} catch (InterruptedException e) {}
		}
		
		libre = false;
	}
	
	synchronized public void soltar () {
		libre = true;
		//System.out.println ("Soltando palillo "+id);
		notifyAll();
	}
}