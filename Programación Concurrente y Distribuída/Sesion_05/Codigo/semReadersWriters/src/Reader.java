
import java.util.concurrent.*;

public class Reader extends Thread  {
	static Semaphore mutex = new Semaphore (1); // Shared only by readers
	Semaphore writer;
	static int numReaders = 0; // Shared only by readers
	int me;
	
	public Reader (int _me, Semaphore _writer) {
		me = _me;
		writer = _writer;
	}
	
	public void run () {
	   while (true) {		
		   try {
			mutex.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}	
		   numReaders++;
		   if (numReaders ==1) { 
			   try {
				writer.acquire();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		   }
		   mutex.release();
		   System.out.println("Reading an element ... the reader "+me );
		   try {
			Thread.currentThread().sleep(1);
		   } catch (InterruptedException e1) {
			e1.printStackTrace();
		   }
		   System.out.println("Reading an element ... the reader "+me );
		   try {
			Thread.currentThread().sleep(1);
		   } catch (InterruptedException e1) {
			e1.printStackTrace();
		   }
		   System.out.println("Reading an element ... the reader "+me );
		   try {
			mutex.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		   numReaders--;
		   if (numReaders == 0) 
			   writer.release();
		   mutex.release();
		   try {Thread.sleep (1000);} catch (Exception e) {e.printStackTrace();}
	   }	
	}
}
