
public class Productor implements Runnable {
	  int quienSoy;
	  Buffer buffer;

	  public Productor (int _quienSoy, Buffer _buffer) {
	    quienSoy = _quienSoy;
	    buffer = _buffer;
	  }

	  public void run () {
	    for (int i=0; i<5; i++){
	      try {
	    	  buffer.insertar(i);
	      } catch (Exception e) {}
	    }
	  }
}
