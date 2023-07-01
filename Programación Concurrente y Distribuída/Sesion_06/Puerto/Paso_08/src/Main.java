
import java.util.LinkedList;

public class Main {

	public Main() {

	}

	public static void main(String[] args) {

		int i;
		int numBarcos = 20;
		Puerta p = new Puerta();
		TorreDeControl tC = new TorreDeControl();

		LinkedList<Barco> bList = new LinkedList<Barco>();
		for (i = 0; i < numBarcos; i++) {
			if (i % 2 == 0) {
				Barco b = new Barco(0, i, p, tC);
				bList.add(b);
				b.start();
			} else {
				Barco b = new Barco(1, i, p, tC);
				bList.add(b);
				b.start();
			}

		}

		try {
			for (i = 0; i < numBarcos; i++) {
				bList.get(i).join();
			}
		} catch (Exception e) {
			;
		}

		LinkedList<Contenedor> cList = new LinkedList<Contenedor>();
		
		int cAzucar = 12;
		int cHarina = 20;
		int cSal = 5;
		
		for(i = 0; i < cAzucar; i++) {
			Contenedor cA = new Contenedor(1);
			cList.add(cA);
		}
		
		for(i = 0; i < cHarina; i++) {
			Contenedor cH = new Contenedor(2);
			cList.add(cH);
		}
		
		for(i = 0; i < cSal; i++) {
			Contenedor cS = new Contenedor(3);
			cList.add(cS);
		}
		
		Plataforma plataforma = new Plataforma();

		Mercante mercante = new Mercante(0, 42, p, tC, plataforma, cList);

		Grua gAzucar = new Grua(1, plataforma, 12);
		Grua gHarina = new Grua(2, plataforma, 20);
		Grua gSal = new Grua(3, plataforma, 5);

		mercante.start();
		
		gAzucar.start();
		gHarina.start();
		gSal.start();

		ZonaCarga zC = new ZonaCarga();

		Reponedor reponedor = new Reponedor(zC);
		
		reponedor.start();

		LinkedList<Petrolero> pList = new LinkedList<Petrolero>();

		for (i = 0; i < 5; i++) {
			Petrolero petrol = new Petrolero(0, i, p, tC, zC);
			pList.add(petrol);
			petrol.start();
		}

		try {
			for (i = 0; i < 5; i++) {
				pList.get(i).join();
			}
		} catch (Exception e) {
			;
		}

		

	}

}
