
public class Intento3 {
	// Attempt 3 for solving the mutual exclusion problem 
	// Problem: Possible deadlock

	public static void main(String[] args) {
		Flag flag1 = new Flag (false);
		Flag flag2 = new Flag (false);
		Uno uno = new Uno (flag1, flag2);
		Dos dos = new Dos (flag1, flag2);
		uno.start();
		dos.start();
	}
}
