
public class LlenadoAgua implements Runnable {

	private Petrolero p;

	public LlenadoAgua(Petrolero p) {

		this.p = p;

	}

	public void run() {

		ZonaCarga zC = p.getZonaCarga();

		zC.repostarAgua(p);
		
	}

}
