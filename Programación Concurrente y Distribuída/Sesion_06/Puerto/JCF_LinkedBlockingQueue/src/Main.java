import java.util.concurrent.LinkedBlockingQueue;
// Example using a blocking queue
public class Main {

	public static void main(String[] args) {
		LinkedBlockingQueue <Integer> b = new LinkedBlockingQueue <Integer>(3); 

		for (int i=0;i<3;i++) {
			new Producer (i,b);
			new Consumer (i,b);
		}
	}
}
