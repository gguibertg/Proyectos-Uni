package sem5Numeros;
import java.util.concurrent.Semaphore;

public class Reader implements Runnable {
	int[] number;
	Semaphore dataRead, dataPut;
	
	public Reader (int[] _number, Semaphore _dataRead, Semaphore _dataPut) {
		number = _number;
		dataRead = _dataRead;
		dataPut = _dataPut;
	}
	
	public void run () {
		for (int i=1;i<26;i++) {
			try {
				dataRead.acquire();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			number[0]=i;
			dataPut.release();
		}
	}

}
