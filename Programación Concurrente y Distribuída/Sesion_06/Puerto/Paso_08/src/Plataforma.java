
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.SynchronousQueue;

public class Plataforma {

	private int container; // 0 = vacio 1 = Azucar 2 = Harina 3 = Sal

	private BlockingQueue<Contenedor> colaAzucar; // 1
	private BlockingQueue<Contenedor> colaHarina; // 2
	private BlockingQueue<Contenedor> colaSal; // 3

	public Plataforma() {

		container = 0;

		colaAzucar = new SynchronousQueue<Contenedor>();
		colaHarina = new SynchronousQueue<Contenedor>();
		colaSal = new SynchronousQueue<Contenedor>();

	}

	public void dejar(Contenedor c) {

		container = c.getMercancia();

		if (c.getMercancia() == 1) {
			System.out.println("El mercante deja un contenedor de " + c.getNombre());
			try {
				colaAzucar.put(c);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		} else {
			if (c.getMercancia() == 2) {
				System.out.println("El mercante deja un contenedor de " + c.getNombre());
				try {
					colaHarina.put(c);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			} else {
				if (c.getMercancia() == 3) {
					System.out.println("El mercante deja un contenedor de " + c.getNombre());
					try {
						colaSal.put(c);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}
		}
	}

	public void coger(Grua g) {

		if (g.getTipo() == 1) {
			try {
				System.out.println(
						"La grua de " + g.getNombre() + " coge un contenedor de " + colaAzucar.take().getNombre());
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		} else {
			if (g.getTipo() == 2) {
				try {
					System.out.println(
							"La grua de " + g.getNombre() + " coge un contenedor de " + colaHarina.take().getNombre());
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			} else {
				if (g.getTipo() == 3) {
					try {
						System.out.println(
								"La grua de " + g.getNombre() + " coge un contenedor de " + colaSal.take().getNombre());
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}
		}
	}

}
