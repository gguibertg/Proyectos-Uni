package simpleSynchroSample2;

public class Client implements Runnable {
	Example e;
	
	public Client (Example _e){
		e=_e;
	}
	
	public void run () {
		for (int i=0;i<5;i++) {
			e.m1(Thread.currentThread());
			e.m2(Thread.currentThread());
			e.m3(Thread.currentThread());
		}
	}

}
