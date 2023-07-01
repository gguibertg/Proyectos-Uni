import java.util.*;
import java.util.concurrent.*;
public class Main {
// Example using Synchronous queue. We obtain strict alternation (in this case desired)
	public static void main(String[] args) {
		BlockingQueue<String> drop = 
                new SynchronousQueue<String>();
        (new Thread(new Producer(drop))).start();
        (new Thread(new Consumer(drop))).start();
	}
}
