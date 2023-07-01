
public class Hidrogeno implements Runnable {

	private Aire aire;
	int quienSoy;
    
	public Hidrogeno (Aire _aire, int quien) {
		aire = _aire;
		quienSoy = quien;
	}
	
	public void run () {
		aire.quieroCombinar (false, quienSoy);
	}
}
