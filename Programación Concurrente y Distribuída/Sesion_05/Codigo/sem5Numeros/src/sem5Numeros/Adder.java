package sem5Numeros;
import java.util.concurrent.Semaphore;

public class Adder implements Runnable {
	Semaphore dataPut, dataRead, sumPut, sumWritten;
	int[] s, d;
	int sum = 0;
	int added = 0;
	
	public Adder (Semaphore _sumPut, Semaphore _sumWritten, Semaphore _dataPut, Semaphore _dataRead, int[] _s, int[] _d) {
		s=_s;
		sumPut = _sumPut;
		sumWritten = _sumWritten;
		dataRead = _dataRead;
		dataPut = _dataPut;
		d=_d;
	}
	
	public void run () {
		while (true) {
			try {
				dataPut.acquire();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			sum =sum + d[0];
			System.out.println(d[0]);
			added ++;
			if (added >= 5) {
				s[0] = sum;
				sumPut.release();
				try {
					sumWritten.acquire();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				sum = 0;
				added = 0;
			}
			dataRead.release();
		}
	}

}
