
import java.util.concurrent.*;

public class Numero extends Thread {
	int miValor = 0;
	static Semaphore mutex = new Semaphore (1);
	int quienSoy;
	static int N = 5;
	Numero [] numeros;
	int comoYo = 0;
	int meHanLlamado = 0;
	Semaphore fin = new Semaphore (0);
	
	public Numero (int _valor, int _numero, Numero[] _numeros) {
		miValor = _valor;
		quienSoy = _numero;
		numeros = _numeros;
	}
	
	public void poner (int suValor, int[] o) {
		try {
			mutex.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		if (suValor == miValor) {
			comoYo++;
			o[0] = miValor;
		}
		else o[0] = -1;
		meHanLlamado++;
		if (meHanLlamado == quienSoy) {
			fin.release();
		}
		mutex.release();
	}
	
	public void run () {
		int o[] = new int [1];

		for (int i=quienSoy+1;i<N;i++) {
			numeros[i].poner (miValor, o);
			if (o[0] == miValor) comoYo++;
		}
		try {
			if (quienSoy!=0) fin.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println ("Soy "+ quienSoy+ ", tengo el "+miValor+"  y como yo hay: " + comoYo);
	}
}
