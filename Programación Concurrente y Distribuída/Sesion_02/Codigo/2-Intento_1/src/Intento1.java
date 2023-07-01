
public class Intento1 {
	// Attempt 1 for solving the mutual exclusion problem
	// Problem: Strict alternation

	public static void main(String[] args) {
		Turno turno = new Turno (1);
		
		Uno uno = new Uno (turno);
		Dos dos = new Dos (turno);
		uno.start();
		dos.start();
	}
}
