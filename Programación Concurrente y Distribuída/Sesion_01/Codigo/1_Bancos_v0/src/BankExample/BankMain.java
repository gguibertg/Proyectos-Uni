package BankExample;
import java.util.*;
public class BankMain {
	// This is the sequential version of the Bank problem. 
	// The objective here is observing the performance of the solution.

	public static void main(String[] args) {
		int acc1,acc2;
		int bankSize = 1000;
		int initialAmount = 1000;
		
		Bank b = new Bank (bankSize,initialAmount);
		System.out.println ("Initial amount: "+initialAmount);
		
		// we obtain the current time
		Long t = new Date().getTime();

		// we perform bankSize transfers		
		Random r = new Random(t);
		System.out.println("Doing tranfers...");
		for (int i=0;i<bankSize;i++) {
			acc1 = r.nextInt(100);
			do acc2 = r.nextInt(100); while (acc1==acc2);
			int amount = r.nextInt(10);
			b.transfer (acc1, acc2, amount);
		}
		
		// we perform 10 audits. We should obtain always the same amount
		for (int i=0;i<10;i++)
			System.out.println ("Audit: "+b.audit(0,bankSize));
		
		// obtaining the time elapsed in milliseconds
		System.out.println("Time elapsed :"+ (new Date().getTime()-t));
		System.out.println ("Final amount of money: "+b.audit(0, bankSize));
	}
}
