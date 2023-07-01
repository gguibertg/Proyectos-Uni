
public class Cannibal implements Runnable {

	int id;
	Pot pot;
		
	public Cannibal (int _id, Pot _pot) {
		id = _id;
		pot = _pot;
	}
	
	public void run () {
		while (true) {
			pot.get(id);
			try {
				Thread.currentThread().sleep (100);
			} catch (Exception e) {;}
		}
	}
}