import java.util.concurrent.RecursiveAction;

public class Gift extends RecursiveAction {
	private static final long serialVersionUID = 1L;
	Bank b;
	int init, end, amount;
	
	public Gift (Bank _b, int _init, int _end, int _amount) {
		b=_b;
		init = _init;
		end = _end;
		amount = _amount;
	}
	
	public void compute () {
		if (end-init<10) { // trivial solution
			// For the given range of accounts, we add an extra amount of money
			for (int i=init; i<end; i++) {
				b.getAccount(i).gift(amount);
			}
		}
		else {
			int middle = (init+end)/2;
			Gift g1 = new Gift (b,init,middle,amount);
			Gift g2 = new Gift (b,middle,end,amount);
			invokeAll (g1,g2);
		}
	}
}
