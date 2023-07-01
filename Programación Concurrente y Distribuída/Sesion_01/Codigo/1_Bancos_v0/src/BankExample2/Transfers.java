package BankExample2;

import java.util.*;
import BankExample.Bank;

public class Transfers extends Thread {
	Bank b;
	int times;
	int bankSize;
	
	public Transfers (Bank _b, int _times, int _bankSize) {
		b = _b;
		times = _times;
		bankSize = _bankSize;
	}
	
	public void run () {
		int acc1, acc2 = 0;
		for (int i=0;i<times;i++) {
		    //System.out.print (".");
			Random r = new Random();
			acc1 = r.nextInt(bankSize);
			do acc2 = r.nextInt(bankSize); while (acc1==acc2);
			int amount = r.nextInt(10);
			b.transfer (acc1, acc2, amount);
		}
	}
}
