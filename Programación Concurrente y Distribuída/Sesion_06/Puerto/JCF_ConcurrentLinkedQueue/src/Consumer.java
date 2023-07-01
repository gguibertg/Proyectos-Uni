
import java.util.concurrent.*;

public class Consumer implements Runnable {
	ConcurrentLinkedQueue<Integer> data;
	Thread t;
	int id;
	Integer result;
	int success = 0;

	public Consumer (int i, ConcurrentLinkedQueue<Integer> l) {
		id = i;
		this.data = l;
		t = new Thread (this);
		t.start();
	}
	public void run() {
		try {
			for(int i=0;i<30;i++) {
				result = data.poll(); //non-blocking the thread if there is not data available
				if (result !=null) success++; 
				System.out.println("Thread "+id+" has extracted "+result);
			}
		}
		catch(Exception e){}
	}
}
