
public class Letra extends Thread {
	static Object o = new Object();
	static char anterior = 'C';
	char letra;
	
	public Letra (char _letra) {
		letra = _letra;
	}

    public void run () {
	  for (int i=0;i<10;i++)
			synchronized (o) {
				while (((letra=='A')&&anterior!='C') ||
					   ((letra=='B')&&anterior!='A')||
					   ((letra=='C')&&(anterior!='B')))
						try {
							o.wait();
						}
						catch (Exception e) {e.printStackTrace();}
				System.out.println(letra);
				anterior = letra;
			    o.notifyAll();
			}
     }
}
