package BankExample;

public class Account {
	private int balance;
	public Account (int _balance) {
		balance = _balance;
	}
	public void deposit (int amount) {
		balance +=amount;
	}
	public void withdraw (int amount) {
		balance -=amount;
	}
	public long getbalance () {
		return balance;
	}
	public void setbalance (int _balance) {
		balance = _balance;
	}
	
	public void gift (int amount) {
		// we are adding amount to balance, but giving a round intentionally
		for (int i=0;i<amount;i++)
			balance += 1;
	}
}