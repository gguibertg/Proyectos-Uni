import java.util.concurrent.locks.*;

public class Mesa {
	int tenedores[] = { 2, 2, 2, 2, 2 };
	Condition okParaComer[] = new Condition[5];
	Lock m = new ReentrantLock();

	public Mesa() {
		for (int i = 0; i < 5; i++) {
			okParaComer[i] = m.newCondition();
		}
	}

	public void coger(int i) {
		try {
			m.lock();
			while (tenedores[i] != 2) { // Esta versión está bien gracias al while
				System.out.println("Filosofo " + i + " esperando");
				okParaComer[i].await();
			}
			tenedores[(i + 1) % 5] = tenedores[(i + 1) % 5] - 1;
			tenedores[(i + 4) % 5] = tenedores[(i + 4) % 5] - 1;
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			m.unlock();
		}
	}

	public void poner(int i) {
		try {
			m.lock();
			System.out.println("Filosofo " + i + " termina");
			tenedores[(i + 1) % 5] = tenedores[(i + 1) % 5] + 1;
			tenedores[(i + 4) % 5] = tenedores[(i + 4) % 5] + 1;
			if (tenedores[(i + 1) % 5] == 2)
				okParaComer[(i + 1) % 5].signal();
			if (tenedores[(i + 4) % 5] == 2)
				okParaComer[(i + 4) % 5].signal();
		} finally {
			m.unlock();
		}
	}
}
