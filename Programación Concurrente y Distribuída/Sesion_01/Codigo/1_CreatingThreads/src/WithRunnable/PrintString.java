package WithRunnable;
import java.util.Random;

public class PrintString implements Runnable {
  String word;
  public PrintString (String _word) {
    word = _word;
  }
  public void run() {
    for (int i = 0;i<10;i++) {
      System.out.print (word);
      try {
    	  Thread.sleep (new Random().nextInt(500)); // Hacemos esto para obligar a abandonar la CPU y poder ver un intercalado
      } catch (Exception e) {}
    }
  }
	  
  public static void main (String args[]) {
    PrintString a = new PrintString ("1");
    PrintString b = new PrintString ("2");
    Thread t1 = new Thread (a); // podríamos haber hecho directamente Thread t1 = new Thread (new PrintString ("1"));
    Thread t2 = new Thread (b); // podríamos haber hecho directamente Thread t2 = new Thread (new PrintString("2"));
    t1.start(); t2.start();
    System.out.println ("End of main thread");
  }
}
