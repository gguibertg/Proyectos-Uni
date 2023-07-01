
public class Uno extends Thread {
	Turno turno;
	
	public Uno (Turno _turno) {
		turno = _turno;
	}

	public void run () {
		for (int i=0;i<10;i++) {
			while (turno.valor != 1) {
				System.out.print ("."); // It allows us to see clearly the busy waiting problem
			}
			System.out.println ("");
			System.out.print ('a');
			System.out.print ('a');
			System.out.println ('a');
			turno.valor = 2;
		}
	}
}
