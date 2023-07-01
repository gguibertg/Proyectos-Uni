package BankExample3;

import BankExample.Account;

public class GiftThread extends Thread {
	int amount;
	Account ac;
	public GiftThread (Account _ac, int _amount) {
		amount = _amount;
		ac = _ac;
	}
	public void run () {
		ac.gift(amount);
	}
}
