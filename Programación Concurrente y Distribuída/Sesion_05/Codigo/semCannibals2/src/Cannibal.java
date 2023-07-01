import java.util.concurrent.Semaphore;

public class Cannibal implements Runnable {

	int id;
	Pot pot;
	Semaphore mutex;
	Semaphore empty;
	Semaphore full;
	
	public Cannibal (int _id, Pot _pot) {
		id = _id;
		pot = _pot;
	}
	
	public void run () {
		while (true) {
			pot.get(id);
			System.out.println ("Cannibal "+id + " eating");
			try {Thread.sleep(1000);} catch (Exception e) {;}
		}
	}
}
