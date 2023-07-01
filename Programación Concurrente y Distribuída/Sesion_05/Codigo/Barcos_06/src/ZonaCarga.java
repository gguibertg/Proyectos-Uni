
import java.util.concurrent.Semaphore;

public class ZonaCarga {

	private int barcosDentro;

	private int[] contenedoresPetroleo = { 0, 0, 0, 0, 0, };

	private Semaphore[] semContenedores;
	private Semaphore[] semReponedor;
	private Semaphore[] semBarcos;
	private Semaphore mutex;

	public ZonaCarga() {

		barcosDentro = 0;

		for (int i = 0; i < 5; i++) {
			contenedoresPetroleo[i] = 1000;
		}

		semContenedores = new Semaphore[] { new Semaphore(0), new Semaphore(0), new Semaphore(0), new Semaphore(0),
				new Semaphore(0) };

		semReponedor = new Semaphore[] { new Semaphore(0), new Semaphore(0), new Semaphore(0), new Semaphore(0),
				new Semaphore(0) };

		semBarcos = new Semaphore[] { new Semaphore(0), new Semaphore(0), new Semaphore(0), new Semaphore(0),
				new Semaphore(0) };

		mutex = new Semaphore(1);

	}

	public int getBarcosDentro() {
		return barcosDentro;
	}

	public void setBarcosDentro(int barcosDentro) {
		this.barcosDentro = barcosDentro;
	}

	public int[] getContenedoresPetroleo() {
		return contenedoresPetroleo;
	}

	public void setContenedoresPetroleo(int[] contenedoresPetroleo) {
		this.contenedoresPetroleo = contenedoresPetroleo;
	}

	public void llegar(Petrolero p) {
		
		barcosDentro++;
		
		if(barcosDentro == 5) {
			for(int i = 0; i < 5; i++) {
				semBarcos[i].release();
			}
		}else {
			try {
				semBarcos[p.getIdentificador()].acquire();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

	}

	public void repostarPetroleo(Petrolero p) {
		
		contenedoresPetroleo[p.getIdentificador()] = 0;
		
		p.setPetroleo(p.getPetroleo() + 1000);

		semReponedor[p.getIdentificador()].release();
		
		try {
			semContenedores[p.getIdentificador()].acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		System.out.println("El petrolero " + p.getIdentificador() + " lleva " + p.getPetroleo() + " litros de petroleo");
		
	}

	public void reponer() {
		
		for(int i = 0; i < 5; i++) {
			try {
				semReponedor[i].acquire();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
		System.out.println("REPONEDOR DESPERTADO");
		
		for(int i = 0; i < 5; i++) {
			contenedoresPetroleo[i] = 1000;
			System.out.println("Reponedor llenando tanque numero " + i);
			semContenedores[i].release();
		}
		
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
