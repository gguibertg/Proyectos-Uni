import java.util.concurrent.*;

public class Producer implements Runnable {
	int me;
	Semaphore mutex;
	Semaphore empty;
	Semaphore full;
	Buffer buffer;

	public Producer (int _me , 
			Semaphore _mutex , 
			Semaphore _empty, 
			Semaphore _full,
			Buffer _buffer) {
		
		me = _me;
		mutex = _mutex;
		empty = _empty;
		full = _full;
		buffer = _buffer;
	}
	
	public void putElements () throws InterruptedException{
		for (int i=0; i<10;i++){
			/* entry protocol. */
			empty.acquire();
		    mutex.acquire();

		    /* accessing the critical section */
		    buffer.insert (i);

		    /* exit protocol */
		    mutex.release();
		    full.release();
		}
	}
	
	public void run () {
		try {putElements();
		} catch (Exception e) {}
	}

}
