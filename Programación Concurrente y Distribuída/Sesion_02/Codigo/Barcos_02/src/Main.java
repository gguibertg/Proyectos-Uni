
import java.util.LinkedList;

public class Main {

	public Main() {

	}

	public static void main(String[] args) {

		int i;
		int numBarcos = 20;
		Puerta p = new Puerta();

		LinkedList<Barco> bList = new LinkedList<Barco>();
		for (i = 0; i < numBarcos; i++) {
			if (i % 2 == 0) {
				Barco b = new Barco(0, i, p);
				bList.add(b);
				b.start();
			} else {
				Barco b = new Barco(1, i, p);
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

	}

}
