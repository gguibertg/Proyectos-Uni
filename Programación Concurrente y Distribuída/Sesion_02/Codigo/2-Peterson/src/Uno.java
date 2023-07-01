
public class Uno extends Thread {
	volatile Flag flag1, flag2;
	Turno turno;
	Contador cont;
	
	public Uno (Contador _cont, Flag _flag1, Flag _flag2, Turno _turno) {
		flag1 = _flag1;
		flag2 = _flag2;
		turno = _turno;
		cont = _cont;
	}

	public void run () {
		for (int i=0;i<10000;i++) {
			flag1.valor = true;
			turno.valor = 2; 
			while (flag2.valor && turno.valor ==2) { 
				//System.out.print ("."); 
			}
			cont.cont++;
			/*System.out.println ("");
			System.out.print ('a');
			System.out.print ('a');
			System.out.print ('a');*/
			flag1.valor = false;
		}
	}
}
