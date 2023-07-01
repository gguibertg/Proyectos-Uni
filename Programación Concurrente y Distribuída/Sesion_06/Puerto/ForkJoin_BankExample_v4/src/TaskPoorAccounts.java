import java.util.concurrent.RecursiveTask;
import java.util.List;
import java.util.ArrayList;

public class TaskPoorAccounts extends RecursiveTask <List>{
	private static final long serialVersionUID = 1L;
	Bank b;
	int init, end;
	List <Integer> l;
	long limit;
	
	public TaskPoorAccounts (Bank _b, int _init, int _end, List <Integer> _l, long _limit) {
		b=_b;
		init = _init;
		end = _end;
		l = _l;
		limit = _limit;
	}
	
	public List compute () {
		if (end-init<10) { // trivial solution
			// For the given range of accounts, we obtain the list
			for (int i=init; i<end; i++) {
				Account a = b.getAccount(i);
				if(a.getbalance()<limit) {
					l.add(new Integer (i)); // store the index of the account
				}
			}
		}
		else {
			int middle = (init+end)/2;
			List <Integer> l1 = new ArrayList <>();
			List <Integer> l2 = new ArrayList <>();
			TaskPoorAccounts g1 = new TaskPoorAccounts (b,init,middle, l1, limit);
			TaskPoorAccounts g2 = new TaskPoorAccounts (b,middle,end, l2, limit);
			invokeAll (g1,g2);
			// merging the results
			l.addAll(l1);
			l.addAll(l2);
		}
		return l;
	}
}
