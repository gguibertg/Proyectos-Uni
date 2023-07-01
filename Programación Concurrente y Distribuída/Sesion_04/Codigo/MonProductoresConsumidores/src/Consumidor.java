
public class Consumidor implements Runnable {
	  int quienSoy;
	  Buffer buffer;

	  public Consumidor (int _quienSoy, Buffer _buffer) {
	    quienSoy = _quienSoy;
	    buffer = _buffer;
	  }

	  public void run () {
		  int elem;
		  for (int i=0; i<5;i++){
			  try {
				  elem = buffer.extraer ();
			  } catch (Exception e) {}
		  }
	  }
}
