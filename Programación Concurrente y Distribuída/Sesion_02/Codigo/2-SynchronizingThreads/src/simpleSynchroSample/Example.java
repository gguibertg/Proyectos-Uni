package simpleSynchroSample;

public class Example {
	Object o;
	
    public Example (Object _o) {
    	o=_o;
    }

    public synchronized void m1(Thread c) {
        print (c,"s1"); 
    }

    public void m2(Thread c) {
    	print (c,"s2");
        synchronized (this) {
            print (c,"s3"); 
        }
        synchronized (o) {
          print (c,"s4"); 
        }
    }

    public void m3(Thread c) {
        synchronized (this) {
        	print (c,"s5");
        	synchronized (o) {
        		print (c,"s6"); 
        	}
       } 
    }
      
    public void print (Thread c, String s) {
    	// Auxiliary method to see what is happening.
    	// We print three times the message just to see if they are interleaved. 
    	// For example Th1-s1 cannot be interleaved with Th2-s1. However, Th1-s2 could be interleaved with Th2-s2
    	for (int i=0;i<3;i++) {
    		if (c.getName().compareTo("Th1")==0)
    				System.out.println (c.getName()+"-"+s);
    		else System.out.println ("      "+c.getName()+"-"+s);
    		try {
    			Thread.currentThread().sleep (1); // to force the thread to leave the CPU and give a chance to the other thread
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
    	}
    }

	public static void main(String[] args) {
		Object o = new Object();
    	System.out.println ("First example");
    	System.out.println ("-------------");
    	
		Example e1 =new Example (o);
		
		Client a = new Client(e1) ; // a and b are for the fist example in the slides
		Client b = new Client(e1);  // c and d are for the second example in the slides
		
		Thread t1 = new Thread (a,"Th1"); // t1 and t2 work against the same object: e1
		Thread t2 = new Thread (b,"Th2");
		t1.start();
		t2.start();
	}
}
