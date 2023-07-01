import java.util.concurrent.*;
public class Pata extends Thread {
	int id;
	static int patasMovidas = 0;
	static Semaphore mutex = new Semaphore (1);
	static Semaphore dosPatas = new Semaphore (2);
	Semaphore [] ciclo;
	
	public Pata (int _id, Semaphore[] _ciclo){
		id =_id;
		ciclo = _ciclo;
	}
	
	public void run () {
		for (int i=0;i<5;i++){ // cada pata lo hace 5 veces
			try {
				ciclo[id].acquire();
			} catch (InterruptedException e1) {
				e1.printStackTrace();
			}
			try {
				dosPatas.acquire();
			} catch (InterruptedException e1) {
				e1.printStackTrace();
			}
			System.out.println ("*****Moviendo pata" +id+" por "+i+"ª vez");
			// Se pueden mezclar estos  mensajes entre diferentes patas
			//try {Thread.sleep (100);} catch (Exception e) {;}
			System.out.println ("*****Moviendo pata" +id);
			//try {Thread.sleep (100);} catch (Exception e) {;}
			System.out.println ("*****Moviendo pata" +id);
			dosPatas.release();
			try {mutex.acquire();} catch (InterruptedException e) {e.printStackTrace();}
			patasMovidas++;
			if (patasMovidas == 6) {
				patasMovidas = 0;
				for (int j=0; j<6;j++) 
					ciclo[j].release();
			}
			mutex.release();
		}
	}
}
