import java.util.concurrent.Semaphore;

public class Pot {
	public int misionariesNumber = 0;
	Semaphore full, empty;
	
	public Pot (Semaphore _full, Semaphore _empty) {
		misionariesNumber = 0;
		full = _full;
		empty = _empty;
	}
	
	public void fill (){
		try {
			empty.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println("Chef filling the pot");
		misionariesNumber = 10;
		full.release();
	}
	
	public void get (int id) {
		try {
			full.acquire();
		} catch (InterruptedException e) {e.printStackTrace();}
		misionariesNumber --;
		System.out.println("Cannibal "+id+" has got a missionaire from the pot");
		if (this.empty()) {
			System.out.println("I'm cannibal "+id+" and I'm going to wake up the chef");
			empty.release();
		}
		else full.release();
	}
	
	public boolean empty () {
		return (misionariesNumber == 0);
	}

}
