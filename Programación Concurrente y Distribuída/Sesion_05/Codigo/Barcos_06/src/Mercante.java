
import java.util.LinkedList;

public class Mercante extends Barco {

	private Plataforma plataforma;
	private LinkedList<Contenedor> cList; 
	
	public Mercante(int direccion, int id, Puerta p, TorreDeControl tC, Plataforma plataforma, LinkedList<Contenedor> cList) {
		
		super(direccion, id, p, tC);
		this.plataforma = plataforma;
		this.cList = cList;
		
	}

	public Plataforma getPlataforma() {
		return plataforma;
	}

	public void setPlataforma(Plataforma plataforma) {
		this.plataforma = plataforma;
	}

	public LinkedList<Contenedor> getcList() {
		return cList;
	}

	public void setcList(LinkedList<Contenedor> cList) {
		this.cList = cList;
	}
	
	public void run() {
		
		gettC().permisoEntrada(this);
		getP().entrar(this);
		gettC().finEntrada(this);
		
		for(int i = 0; i < cList.size(); i++) {
			plataforma.dejar(cList.get(i).getMercancia());
		}
		
		gettC().permisoSalida(this);
		getP().salir(this);
		gettC().finSalida(this);
		
	}
	
}
