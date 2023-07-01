import java.util.concurrent.*;

public class Producer implements Runnable {
	ConcurrentLinkedQueue<Integer> data;
	Thread t;
	int id;
	boolean result;

	public Producer (int i, ConcurrentLinkedQueue<Integer> l) {
		id = i;
		this.data = l;
		t = new Thread (this);
		t.start();
	}
	public void run() {
		try {
			for(int x=0;x<10;x++) {
				data.add(new Integer(x)); //it doesn't block if there is not space
				// Observe that between the previous and the next line other threads can extract or add elements. 
				// So the output can be confused because messages can be interleaved.
				System.out.println("Thread "+id+" has inserted "+x); 
			}
		}
		catch(Exception e){}
	}
}
