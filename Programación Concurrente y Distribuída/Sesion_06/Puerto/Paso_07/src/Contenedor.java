
public class Contenedor {
	
	private int mercancia;	// 1 = Azucar 2 = Harina 3 = Sal
	private String nombre;
	
	public Contenedor(int mercancia) {
		
		this.mercancia = mercancia;
		
		if(mercancia == 1) {
			nombre = "Azucar";
		}else {
			if(mercancia == 2) {
				nombre = "Harina";
			}else {
				
			}if(mercancia == 3) {
				nombre = "Sal";
			}
		}
		
	}

	public int getMercancia() {
		return mercancia;
	}

	public void setMercancia(int mercancia) {
		this.mercancia = mercancia;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

}
