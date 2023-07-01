
import java.util.concurrent.*;

public class Lector extends Thread  {
	static Semaphore mutex = new Semaphore (1); // Sólo compartido por lectores
	Semaphore escritor;
	static int numLec = 0; // Sólo compartido por lectores
	int quienSoy;
	
	public Lector (int _quienSoy, Semaphore _escritor) {
		quienSoy = _quienSoy;
		escritor = _escritor;
	}
	
	public void run () {
	   while (true) {		
		   try {
			mutex.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}	
		   numLec++;
		   if (numLec ==1) { 
			   try {
				escritor.acquire();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		   }
		   mutex.release();
		   System.out.println("Leyendo elemento ... el lector "+quienSoy );
		   try {
			Thread.currentThread().sleep(1);
		   } catch (InterruptedException e1) {
			e1.printStackTrace();
		   }
		   System.out.println("Leyendo elemento ... el lector "+quienSoy );
		   try {
			Thread.currentThread().sleep(1);
		   } catch (InterruptedException e1) {
			e1.printStackTrace();
		   }
		   System.out.println("Leyendo elemento ... el lector "+quienSoy );
		   try {
			mutex.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		   numLec--;
		   if (numLec == 0) 
			   escritor.release();
		   mutex.release();
		   try {Thread.sleep (1000);} catch (Exception e) {e.printStackTrace();}
	   }	
	}
}
