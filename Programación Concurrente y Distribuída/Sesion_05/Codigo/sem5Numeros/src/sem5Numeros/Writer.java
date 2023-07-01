package sem5Numeros;
import java.util.concurrent.Semaphore;

public class Writer implements Runnable {
	Semaphore sumPut, sumWritten;
	int[] s;
	
	public Writer (Semaphore _sumPut, Semaphore _sumWritten, int[] _s) {
		s=_s;
		sumPut = _sumPut;
		sumWritten = _sumWritten;
	}
	
	public void run () {
		while (true) {
			try {
				sumPut.acquire();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			System.out.println("Sum of 5 numbers: "+s[0]);
			sumWritten.release();
		}
	}

}
