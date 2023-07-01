import java.util.concurrent.*;

public class Consumer implements Runnable {
	int me;
	Semaphore mutex;
	Semaphore empty;
	Semaphore full;
	Buffer buffer;

	public Consumer (int _me, 
			Semaphore _mutex, 
			Semaphore _empty, 
			Semaphore _full,
			Buffer _buffer) {
		
		me = _me;
		mutex = _mutex;
		empty = _empty;
		full = _full;
		buffer = _buffer;
	}

	public void getElement () throws InterruptedException {
		for (int i=0; i<10; i++){
			/* Entry protocol */
			full.acquire();
		    mutex.acquire();
		    
		    /* Access to the critical section */
		    buffer.extract();
		    
		    /* Exit protocol */
		    mutex.release();
		    empty.release();
		}	
	}
	
	public void run () {
		try {getElement();
		} catch (InterruptedException e) {}
	}
}
