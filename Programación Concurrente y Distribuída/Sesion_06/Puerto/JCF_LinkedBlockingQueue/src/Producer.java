import java.util.concurrent.*;

public class Producer implements Runnable {
	LinkedBlockingQueue<Integer> data;
	Thread t;
	int id;

	public Producer (int i, LinkedBlockingQueue<Integer> l) {
		id = i;
		this.data = l;
		t = new Thread (this);
		t.start();
	}
	public void run() {
		try {
			for(int x=0;;x++) {
				data.put(new Integer(x)); //block if there is not space
				// Observe that between the previous and the next line other threads can extract or add elements. 
				// So the output can be confused because messages can be interleaved.
				System.out.println("Thread "+id+" inserting "+x);
			}
		}
		catch(InterruptedException e){}
	}
}
