import java.util.concurrent.ConcurrentLinkedQueue;
// Example using a non-blocking data structure. 
// Whenever null is printed is because the queue was empty.

public class Main {

	public static void main(String[] args) {
		ConcurrentLinkedQueue <Integer> b = new ConcurrentLinkedQueue <Integer>(); 
		for (int i=0;i<3;i++) {
			new Consumer (i,b);
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			new Producer (i,b);
		}
	}
}
