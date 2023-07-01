package WithInheritance;

import java.util.Random;

public class PrintString extends Thread {
	String word;
	
	public PrintString (String _word) {
		word = _word;
	}
	
	  public void run() {
		    for (int i = 0;i<10;i++) {
		      System.out.print (word);
		      try {
		    	  Thread.sleep (new Random().nextInt(500)); // Hacemos esto para obligar a abandonar la CPU 
		    	  											// y poder ver un intercalado en la ejecución de las instrucciones
		      } catch (Exception e) {}
		    }
		  }
	
	public static void main(String[] args) {
		PrintString a = new PrintString ("1");
		PrintString b = new PrintString ("2");
		a.start();
		b.start();
		System.out.println ("End of main thread");
	}
}
