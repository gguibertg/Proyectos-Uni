import java.util.concurrent.PriorityBlockingQueue;
import java.util.Date;
// Example using a blocking priority queue in which elements are ordered in the queue.

public class Main {
	public static void main(String[] args) {
		PriorityBlockingQueue <Date> p = new PriorityBlockingQueue <Date>();
		Date d = new Date();
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
 			e.printStackTrace();
		}
		Date d2 = new Date();
		p.add(d2);
		p.add(d); // Elements are ordered by 'Date'
		System.out.println(p);
	}
}
