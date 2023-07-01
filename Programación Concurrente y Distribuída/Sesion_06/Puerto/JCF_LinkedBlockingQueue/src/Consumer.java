
import java.util.concurrent.*;

public class Consumer implements Runnable {
	LinkedBlockingQueue<Integer> data;
	Thread t;
	int id;

	public Consumer (int i, LinkedBlockingQueue<Integer> l) {
		id = i;
		this.data = l;
		t = new Thread (this);
		t.start();
	}
	public void run() {
		try {
			for(;;) {//blocking the thread if there is not data available
				System.out.println("Thread "+id+" Extracting "+data.take().intValue());
			}
		}
		catch(InterruptedException e){}
	}
}
