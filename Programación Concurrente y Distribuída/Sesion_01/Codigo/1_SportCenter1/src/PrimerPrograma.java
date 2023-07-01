import java.util.LinkedList;

public class PrimerPrograma {

	public static void main(String[] args) {
		int aforo = 5000;
		int numPuertas = 2;
		
		LinkedList <Puerta> pList = new LinkedList <Puerta>();
		for (int i=0; i<numPuertas;i++) {
			Puerta p = new Puerta(i, aforo);
			pList.add(p);
			p.start();
		}
		
		try {
			for (int i=0; i<numPuertas;i++) 
				pList.get(i).join();
		} catch (Exception e) {;}
	}
}
