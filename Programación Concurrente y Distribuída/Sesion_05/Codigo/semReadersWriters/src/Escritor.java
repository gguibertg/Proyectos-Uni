import java.util.concurrent.*;

public class Escritor extends Thread {
	int quienSoy;
	Semaphore escritor;
	
	public Escritor (int _quienSoy, Semaphore _escritor) {
		quienSoy = _quienSoy;
		escritor = _escritor;
	}

	public void run () {
    while (true) {
        try {
			escritor.acquire();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        System.out.println("escritor escribiendo ... "+quienSoy );
        System.out.println("escritor escribiendo ... "+quienSoy );
        System.out.println("escritor escribiendo ... "+quienSoy );
        escritor.release();
		try {Thread.sleep (1000);} catch (Exception e) {e.printStackTrace();}
      }
	}
}
