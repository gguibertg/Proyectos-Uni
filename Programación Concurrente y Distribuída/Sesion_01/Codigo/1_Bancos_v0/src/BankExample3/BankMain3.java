package BankExample3;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import BankExample.Bank;

public class BankMain3 {
	public static void main(String[] args) {
		
		int bankSize = 1000;
		int initialAmount = 1000;
		int amountToGift = 1000;
		
		// Printing the number of cores of the machine in which the program is being executed
		int nproc = Runtime.getRuntime().availableProcessors();
		System.out.println("Number of cores: "+nproc);
		
		// Creating a bank with bankSize accounts. Each one with initialAmount euros
		Bank b = new Bank (bankSize,initialAmount);

		List<Thread> threadList = new ArrayList<Thread>();
				
		// we obtain the current time		
		Long time = new Date().getTime();
		
		// we make a gift to all the accounts, sequentially
		for (int i=0;i<bankSize;i++) {
			b.getAccount(i).gift(amountToGift);
		}
		
		System.out.println("SEQUENTIAL VERSION - Time elapsed: "+(new Date().getTime()-time));
		
		// we do it concurrently with bankSize threads
		Long time2 = new Date().getTime();
		for (int i=0;i<bankSize;i++) {
			// we launch bankSize threads. Each thread performs a gift.
			threadList.add (new GiftThread (b.getAccount(i),amountToGift));
		}


		// waiting for all the threads to finish
		try {
			for (int i=0;i<bankSize;i++) 	
				threadList.get(i).join();
		} catch (Exception e) {e.printStackTrace();}
		
		// obtaining the time elapsed in milliseconds
		System.out.println("CONCURRENT VERSION - Time elapsed: "+(new Date().getTime()-time2));
	}
}

