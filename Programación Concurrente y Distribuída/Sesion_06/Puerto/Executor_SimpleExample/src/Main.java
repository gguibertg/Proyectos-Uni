import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class Main {
	public static void main(String[] args) {
		ThreadPoolExecutor executor;
			 
	    executor=(ThreadPoolExecutor)Executors.newCachedThreadPool();
	    // Send 100 request to the server and finish
	    for (int i=0; i<100; i++){
	    	Task task=new Task("Task "+i);
			executor.execute(task);
			System.out.printf("Server: Pool Size: %d\n",executor.getPoolSize());
			System.out.printf("Server: Active Count: %d\n",executor.getActiveCount());
			System.out.printf("Server: Completed Tasks:%d\n",executor.getCompletedTaskCount());
		}
		executor.shutdown();	
	}
}

