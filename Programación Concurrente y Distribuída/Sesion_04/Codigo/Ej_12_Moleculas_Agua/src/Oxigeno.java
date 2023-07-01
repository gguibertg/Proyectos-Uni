
public class Oxigeno implements Runnable {

	private Aire aire;
	int quienSoy;

	
	public Oxigeno (Aire _aire, int quien) {
		aire = _aire;
		quienSoy = quien;
	}
	
	public void run () {
		aire.quieroCombinar(true, quienSoy);
	}
}
