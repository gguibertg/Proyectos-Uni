

public class Peterson {
	// Peterson's algorithm for the mutual exclusion problem

	public static void main(String[] args) {
		Flag flag1 = new Flag (false);
		Flag flag2 = new Flag (false);
		Turno turno = new Turno (1);
		Contador cont = new Contador ();
		Uno uno = new Uno (cont,flag1, flag2, turno);
		Dos dos = new Dos (cont,flag1, flag2, turno);
		uno.start();
		dos.start();
		try {
			uno.join();
			dos.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println("Contador is: "+cont.cont);
		
	}
}
