
public class Dos extends Thread {
	volatile Flag flag1, flag2;
		
	public Dos (Flag _flag1, Flag _flag2) {
		flag1 = _flag1;
		flag2 = _flag2;
	}

	public void run () {
		for (int i=0;i<10;i++) {
			flag2.valor = true;
			while (flag1.valor == true) { 
				System.out.print (","); // It allows us to see clearly the busy waiting problem
				flag2.valor = false;
				flag2.valor = true;
			}
			System.out.println ("");
			System.out.print ('b');
			System.out.print ('b');
			System.out.print ('b');  
			flag2.valor =  false;
		}
	}
}
