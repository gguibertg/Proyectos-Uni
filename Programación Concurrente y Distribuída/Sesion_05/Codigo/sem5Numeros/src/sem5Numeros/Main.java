package sem5Numeros;
import java.util.concurrent.Semaphore;

public class Main {
	Semaphore dataPut = new Semaphore (0);
	Semaphore dataRead = new Semaphore (1);
	Semaphore sumPut = new Semaphore (0);
	Semaphore sumWritten = new Semaphore (0);
	int [] d = new int[1];
	int [] s = new int[1];
	
	public  Main () {
		Reader r = new Reader (d,dataRead,dataPut);
		Adder a = new Adder (sumPut, sumWritten, dataPut, dataRead, s, d);
		Writer w = new Writer (sumPut, sumWritten, s);
		Thread t1 = new Thread (r);
		Thread t2 = new Thread (a);
		Thread t3 = new Thread (w);
		t1.start ();
		t2.start ();
		t3.start ();
	}
	public static void main(String[] args) {
		new Main ();
	}

}
