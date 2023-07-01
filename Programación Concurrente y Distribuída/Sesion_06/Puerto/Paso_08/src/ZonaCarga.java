
import java.util.concurrent.Semaphore;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.CountDownLatch;

public class ZonaCarga {

	private int[] contenedoresPetroleo = { 0, 0, 0, 0, 0, };

	private Semaphore mutex;

	private CyclicBarrier barrera;
	private CountDownLatch repostar;

	public ZonaCarga() {

		for (int i = 0; i < 5; i++) {
			contenedoresPetroleo[i] = 1000;
		}

		mutex = new Semaphore(1);

		barrera = new CyclicBarrier(5);

		repostar = new CountDownLatch(5);

	}

	public int[] getContenedoresPetroleo() {
		return contenedoresPetroleo;
	}

	public void setContenedoresPetroleo(int[] contenedoresPetroleo) {
		this.contenedoresPetroleo = contenedoresPetroleo;
	}

	public void llegar(Petrolero p) {

		try {
			barrera.await();
		} catch (InterruptedException e) {
			e.printStackTrace();
		} catch (BrokenBarrierException e) {
			e.printStackTrace();
		}

		System.out.println("El petrolero numero " + p.getIdentificador() + " ha llegado");

	}

	public void repostarPetroleo(Petrolero p) {

		p.setPetroleo(p.getPetroleo() + 1000);

		contenedoresPetroleo[p.getIdentificador()] = 0;

		System.out
				.println("El petrolero " + p.getIdentificador() + " lleva " + p.getPetroleo() + " litros de petroleo");

		repostar.countDown();

	}

	public void reponer() {

		try {
			repostar.await();
		} catch (InterruptedException e1) {
			e1.printStackTrace();
		}

		for (int i = 0; i < 5; i++) {
			contenedoresPetroleo[i] = 1000;
			System.out.println("Reponedor llenando tanque numero " + i);
		}
		repostar = new CountDownLatch(5);
	}

	public void repostarAgua(Petrolero p) {

		try {
			mutex.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		p.setAgua(p.getAgua() + 1000);

		System.out.println("El petrolero " + p.getIdentificador() + " lleva " + p.getAgua() + " litros de agua");

		mutex.release();

	}

}
