/* El posible interbloqueo de este problema se evita haciendo uso de una variable
 * contador que solo permite 4 filósofos en la mesa.
 */
public class Filosofo extends Thread {
	
	int quienSoy = 0;
	Palillo palder, palizq;
	Contador cont;
	int numeroOperaciones = 20;
	
	public Filosofo (int quienSoy, Contador cont, Palillo palder, Palillo palizq) {
		this.quienSoy = quienSoy;
		this.palder = palder;
		this.palizq = palizq;
		this.cont = cont;
	}
	
	public void run () {
		
		for (int i = 0; i < numeroOperaciones; i++) {
			//System.out.println("Filosofo " + quienSoy + " pensando");
			cont.inc(quienSoy); 
			palder.coger();
			palizq.coger(); 
			System.out.println("- Filosofo " + quienSoy + " comiendo");
			System.out.println("-- Filosofo " + quienSoy + " comiendo");
			System.out.println("--- Filosofo " + quienSoy + " comiendo");
		//	try {Thread.sleep(1000);
		//	} catch (Exception e) {;}
			palder.soltar();
			palizq.soltar();
			cont.dec();
			//System.out.println("Filosofo " + quienSoy + " ha terminado de comer");
			
		}
	}
}