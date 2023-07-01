import java.util.concurrent.*;

public class Chef implements Runnable {

	Pot pot;
	
	public Chef (Pot pot) {
		this.pot = pot;
	}
	
	public void run () {
		while (true) {
			pot.fill();
		}
	}
}
