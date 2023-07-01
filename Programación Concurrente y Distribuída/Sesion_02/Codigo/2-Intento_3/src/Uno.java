
public class Uno extends Thread {
	volatile Flag flag1, flag2;
	
	public Uno (Flag _flag1, Flag _flag2) {
		flag1 = _flag1;
		flag2 = _flag2;
	}

	public void run () {
		for (int i=0;i<10;i++) {
			flag1.valor = true;
			while (flag2.valor == true) { // the other process wants to enter
				System.out.print ("."); // It allows us to see clearly the busy waiting problem
			}
			System.out.println ("");
			System.out.print ('a');
			System.out.print ('a');
			System.out.print ('a');
			flag1.valor = false;
		}
	}
}
