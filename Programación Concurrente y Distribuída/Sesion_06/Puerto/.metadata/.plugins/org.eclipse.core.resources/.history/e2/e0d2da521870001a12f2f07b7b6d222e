
public class LlenadoPetroleo implements Runnable {

	private Petrolero p;

	public LlenadoPetroleo(Petrolero p) {

		this.p = p;

	}
	
	public void run() {

		ZonaCarga zC = p.getZonaCarga();
	
			zC.repostarPetroleo(p);
			
	}

}
