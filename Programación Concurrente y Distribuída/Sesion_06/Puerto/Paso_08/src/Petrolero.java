
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class Petrolero extends Barco {

	private int agua;
	private int petroleo;
	private ZonaCarga zonaCarga;
	private ThreadPoolExecutor executor;

	public Petrolero(int direccion, int id, Puerta p, TorreDeControl tC, ZonaCarga zC) {

		super(direccion, id, p, tC);

		agua = 0;
		petroleo = 0;
		this.zonaCarga = zC;
		executor = (ThreadPoolExecutor) Executors.newCachedThreadPool();

	}

	public int getAgua() {
		return agua;
	}

	public void setAgua(int agua) {
		this.agua = agua;
	}

	public int getPetroleo() {
		return petroleo;
	}

	public void setPetroleo(int petroleo) {
		this.petroleo = petroleo;
	}

	public ZonaCarga getZonaCarga() {
		return zonaCarga;
	}

	public void setZonaCarga(ZonaCarga zonaCarga) {
		this.zonaCarga = zonaCarga;
	}

	public void run() {

		gettC().permisoEntrada(this);
		getP().entrar(this);
		gettC().finEntrada(this);

		zonaCarga.llegar(this);

		for (int i = 0; i < 3; i++) {
			executor.execute(new LlenadoPetroleo(this));
		}

		for (int i = 0; i < 5; i++) {
			executor.execute(new LlenadoAgua(this));
		}

		executor.shutdown();

		gettC().permisoSalida(this);
		getP().salir(this);
		gettC().finSalida(this);

	}

}
