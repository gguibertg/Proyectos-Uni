import java.util.concurrent.locks.*;

public class Dato {
	int dato = -1;
	Lock lock = new ReentrantLock();
	Condition c1 = lock.newCondition();
	Condition c2 = lock.newCondition();
	
	public Dato () {
		
	}
	
	public void poner (int _dato) {
		lock.lock();
		try {
			while (dato != -1) {
				try {
					c1.await();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			dato = _dato;
			c2.signal();
		} finally {lock.unlock();}
	}
	
	public int coger () {
		int temp;
		lock.lock();
		try {
			while (dato == -1) {
				try {
					c2.await();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			temp = dato;
			dato = -1;
			c1.signal();
		} finally {lock.unlock();}
			return temp;
		}
}
