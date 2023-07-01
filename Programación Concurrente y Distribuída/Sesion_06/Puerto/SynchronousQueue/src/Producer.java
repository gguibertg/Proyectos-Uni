
import java.util.*;
import java.util.concurrent.*;

public class Producer implements Runnable  {
    private BlockingQueue<String> drop;

    List<String> messages = Arrays.asList( 
    	"Message 1",
        "Message 2",
        "Message 3",
        "Message 4");

       public Producer(BlockingQueue<String> d) { 
              this.drop = d; 
       }
 
       public void run()    {
        try
        {
            for (String s : messages) 
               drop.put(s);
            drop.put("DONE");
        }
        catch (InterruptedException intEx)        {
            System.out.println("Interrupted! " +
                 "Last one out, turn out the lights!");
        }
    }
}
