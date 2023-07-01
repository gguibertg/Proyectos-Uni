
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Random;
import java.util.concurrent.Executors;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.Future;
import java.util.concurrent.Callable;

public class BankMain {
	
	// Simple example in which we do several transfers in the Bank using the Executor framework

	public static void main(String[] args) {
		
		int bankSize = 1000;
		int initialAmount = 1000;
		int amount = 5; // amount money for the Gift

		// Obtaining and printing the number of cores of the machine in which the program is being executed
		int nproc = Runtime.getRuntime().availableProcessors();
		System.out.println("Number of cores: "+nproc);
		
		// Creating the executor with nproc threads. We fix the number of threads to be created.
		ThreadPoolExecutor executor = (ThreadPoolExecutor)Executors.newFixedThreadPool(nproc);
		
		// Creating a bank with bankSize accounts. Each one with initialAmount euros
		Bank b = new Bank (bankSize,initialAmount);
		
		// we obtain the current time		
		Long time = new Date().getTime();
		
		// performing transfers with the Executor framework
		System.out.println("Initial amount of money: "+b.audit(0,bankSize));
		for (int i=0;i<nproc;i++) {
			Transfers t = new Transfers (b,bankSize/nproc,bankSize); // Each thread performs nproc transfers
			executor.execute (t);
		}

		// waiting for all the threads to finish
		executor.shutdown();
		try {
			executor.awaitTermination(1, TimeUnit.DAYS); // waiting for all the transfers to finish
		} catch (Exception e) {e.printStackTrace();}

		System.out.println("Main: the amount of money at the end is: "+b.audit(0,bankSize));
	}
}
