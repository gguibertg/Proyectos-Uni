
public class Dos extends Thread {
	volatile Flag flag1, flag2;
	Turno turno;
	Contador cont;
		
	public Dos (Contador _cont, Flag _flag1, Flag _flag2, Turno _turno) {
		flag1 = _flag1;
		flag2 = _flag2;
		turno = _turno;
		cont = _cont;
		
	}

	public void run () {
		for (int i=0;i<10000;i++) {
			flag2.valor = true;
			turno.valor = 1; 
			while (flag1.valor && turno.valor == 1) { 
				//System.out.print (","); 
			}
			
			cont.cont++;
			/*System.out.println ("");
			System.out.print ('b');
			System.out.print ('b');
			System.out.print ('b');  */
			flag2.valor =  false;
		}
	}
}
