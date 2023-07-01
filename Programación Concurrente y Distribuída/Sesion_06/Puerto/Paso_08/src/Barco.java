
public class Barco extends Thread {

	private int direccion; // 0 = entrar 1 = salir
	private int identificador;
	private Puerta p;
	private TorreDeControl tC;

	public Barco(int direccion, int id, Puerta p, TorreDeControl tC) {

		this.direccion = direccion;
		this.identificador = id;
		this.p = p;
		this.tC = tC;

	}

	public int getDireccion() {
		return direccion;
	}

	public void setDireccion(int direccion) {
		this.direccion = direccion;
	}

	public int getIdentificador() {
		return identificador;
	}

	public void setIdentificador(int identificador) {
		this.identificador = identificador;
	}

	public Puerta getP() {
		return p;
	}

	public void setP(Puerta p) {
		this.p = p;
	}

	public TorreDeControl gettC() {
		return tC;
	}

	public void settC(TorreDeControl tC) {
		this.tC = tC;
	}

	public void run() {

		if (direccion == 0) {
			tC.permisoEntrada(this);
			p.entrar(this);
			tC.finEntrada(this);
		}

		if (direccion == 1) {
			tC.permisoSalida(this);
			p.salir(this);
			tC.finSalida(this);
		}

	}

}
