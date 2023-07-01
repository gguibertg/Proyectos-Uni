

import java.util.ArrayList;
import java.util.List;

public class Bank {
	List <Account> accounts;
	int size;
	
	public Bank (int _size, int _amount) {
		size = _size;
		accounts = new ArrayList<> ();
		for (int i=0;i<size;i++) {
			accounts.add (new Account(_amount));
		}
	}
	
	
	public synchronized long audit (int init, int end) {
		long total = 0;
		for (int i=init;i<end;i++) {
			total += accounts.get(i).getbalance();
		}
		return total;
		
	}
	
	public  synchronized void  transfer (int source, int target, int amount) {
		// We don't care whether the account has money or not
		accounts.get(source).withdraw(amount);
		try {
			// We intentionally sleep for a while between withdraw and deposit
			Thread.currentThread().sleep(1);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		accounts.get(target).deposit(amount);
	}
	
	public Account getAccount (int i) {
		return accounts.get(i);
	}
	
	public int bankSize () {
		return size;
	}
}