
public class Principal {

	    public Principal () {}
	    
		public static void main(String[] args) {
			Imprime i = new Imprime();
			Letra a = new Letra ('A',i);
			Letra b = new Letra ('B',i);
			Letra c = new Letra ('C',i);
			a.start();
			b.start();
			c.start();
		}
}
