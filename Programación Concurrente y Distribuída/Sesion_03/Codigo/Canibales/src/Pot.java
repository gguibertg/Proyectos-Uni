
public class Pot {
	public int numMissionaries = 0;
	public Pot () {
		numMissionaries = 0;
	}
	
	public synchronized void fill () {
		while (numMissionaries > 0)
			try {
				System.out.println ("Chef is going to block");
				wait();
			} catch (Exception e) {e.printStackTrace();}
		numMissionaries = 10;
		System.out.println ("Chef filling the pot");
		notifyAll(); // notifyAll() is mandatory to wake up all the blocked cannibals
	}
	
	public synchronized void get (int id) {
		while (numMissionaries == 0)
			try {
				System.out.println ("Missionary "+id+" is going to block");
				wait();
			} catch (Exception e) {e.printStackTrace();}
		numMissionaries --;
		System.out.println("Cannibal "+id +" getting. Pot contains "+numMissionaries+" missionaries");
		if (numMissionaries == 0) {
			System.out.println ("Waking up the chef");
			notify(); // in this case with notify() is enough. Only the chef will be potentially blocked
		}
	}
}
