
public class Reponedor extends Thread {

	ZonaCarga zonaCarga;

	public Reponedor(ZonaCarga zC) {

		this.zonaCarga = zC;

	}

	public ZonaCarga getZonaCarga() {
		return zonaCarga;
	}

	public void setZonaCarga(ZonaCarga zonaCarga) {
		this.zonaCarga = zonaCarga;
	}

	public void run() {

		for(int i = 0; i < 3; i++) {
			zonaCarga.reponer();
		}
	}

}
