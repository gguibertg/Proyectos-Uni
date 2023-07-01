
public class Main {

	final static int NUM_CANNIBALS = 15;
	
	public static void main(String[] args) {

		Pot pot = new Pot();
		
		Chef c = new Chef(pot);
		Thread t = new Thread(c);
		t.start();
		for (int i = 0; i < NUM_CANNIBALS; i++) {
			new Thread(new Cannibal(i, pot)).start();
		}
	}
}
