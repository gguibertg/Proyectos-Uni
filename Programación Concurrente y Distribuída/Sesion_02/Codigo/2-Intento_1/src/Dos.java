
public class Dos extends Thread {
	Turno turno ;
		
	public Dos (Turno _turno) {
		turno = _turno;
	}

	public void run () {
		for (int i=0;i<10;i++) {
			while (turno.valor != 2) { 
				 System.out.print ("."); // It allows us to see clearly the busy waiting problem
			}
			System.out.println ("");
			System.out.print ('b');
			System.out.print ('b');
			System.out.println ('b');  
			turno.valor =  1;
		}
	}
}
