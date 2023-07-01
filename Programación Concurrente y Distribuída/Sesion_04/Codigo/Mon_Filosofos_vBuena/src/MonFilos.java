
public class MonFilos {
	public static void main (String args[]) {
		Mesa mesa = new Mesa();
		for (int i = 0;i<5;i++) {
			new Thread (new Filosofo (mesa,i)).start();
		}
	}
}