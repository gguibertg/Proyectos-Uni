import java.util.concurrent.*;

public class Writer extends Thread {
	int me;
	Semaphore writer;
	
	public Writer (int _me, Semaphore _writer) {
		me = _me;
		writer = _writer;
	}

	public void run () {
    while (true) {
        try {
			writer.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
        System.out.println("writer writing ... "+me );
        System.out.println("writer writing ... "+me );
        System.out.println("writer writing ... "+me );
        writer.release();
		try {Thread.sleep (1000);} catch (Exception e) {e.printStackTrace();}
      }
	}
}
