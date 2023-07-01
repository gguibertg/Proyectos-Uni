package simpleSynchroSample2;

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
    	// We print three times the message : xSy, where x means the thread executing the code and Sy means the sentence being executed.
    	// We print it three times just to see if they are interleaved.
    	
    		if (c.getName().compareTo("1")==0)
    				System.out.println (c.getName()+s);
    		else if (c.getName().compareTo("2")==0 )
    				System.out.println ("    "+c.getName()+s);
    		else if (c.getName().compareTo("3")==0)
    				System.out.println ("                   "+c.getName()+s);
    		else System.out.println ("                        "+c.getName()+s);
    		try {
				Thread.currentThread().sleep (1);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
    }

	public static void main(String[] args) {
		Object o = new Object();
    	System.out.println ("First example       Second example");
		System.out.println ("a    b              c   d");
    	System.out.println ("--   --             --  --");
    	
		Example e1 =new Example (o);
		Example e2 = new Example (o);
		Example e3 = new Example (new Object());
		
		Client a = new Client(e1) ; // a and b are for the fist example in the slides
		Client b = new Client(e1);  // c and d are for the second example in the slides
		Client c = new Client (e2);
		Client d = new Client (e3);
		
		Thread t1 = new Thread (a,"1"); // t1 and t2 work against the same object: e1
		Thread t2 = new Thread (b,"2");
		Thread t3 = new Thread (c,"3");
		Thread t4 = new Thread (d,"4");
		t1.start();
		t2.start();
		t3.start();
		t4.start();
	}
}
