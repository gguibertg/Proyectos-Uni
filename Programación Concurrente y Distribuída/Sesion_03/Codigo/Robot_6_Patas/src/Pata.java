
public class Pata extends Thread {
	int id;
	Control control;
	
	public Pata (int _id, Control _control){
		id =_id;
		control = _control;
	}
	public void run () {
		for (int i=0;i<5;i++){
			control.puedoMover(id);
			System.out.println ("\n*****Moviendo pata" +id);
			// Se pueden mezclar estos  mensajes entre diferentes patas
			try {Thread.sleep (1000);
			} catch (Exception e) {;}
			System.out.println ("*****Moviendo pata" +id);
			try {Thread.sleep (1000);
			} catch (Exception e) {;}
			System.out.println ("*****Moviendo pata" +id);
			control.finMover (id);
		}
	}
}
