/* MON_Atomos v1.0
 * 
 * Se crean una serie de �tomos de Oxigeno y de Hidrogeno que se van a combinar para formar
 * agua. Estos �tomos est�n en el aire e indican su intenci�n de combinarse.
 * El aire es un monitor que combina H-O-H y provoca lluvia creando mol�culas de agua.
 */
public class Principal {

	static final int MAX_MOLECULAS = 50;
	
	public static void main(String[] args) {

		Aire aire = new Aire();
		
		for (int i = 0; i < MAX_MOLECULAS; i++){
			new Thread(new Oxigeno(aire,i)).start();
			new Thread(new Hidrogeno(aire,i)).start();
			new Thread(new Hidrogeno(aire,i+100)).start();
		}
	}

}
