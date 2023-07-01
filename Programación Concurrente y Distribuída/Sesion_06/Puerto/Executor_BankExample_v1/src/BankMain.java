
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
	// This version returns a result from the audits.
	// Now the results of the audits will be stored in a data structure.
	// Class Auditor changes since now it implements Callable

	public static void main(String[] args) {
		
		int bankSize = 1000;
		int initialAmount = 1000;
		int amount = 5; // amount money for the Gift

		// Obtaining and printing the number of cores of the machine in which the program is being executed
		int nproc = Runtime.getRuntime().availableProcessors();
		System.out.println("Number of cores: "+nproc);
		// Creating the executor with nproc threads
		ThreadPoolExecutor executor = (ThreadPoolExecutor)Executors.newFixedThreadPool(nproc);
		ThreadPoolExecutor executor2 = (ThreadPoolExecutor)Executors.newFixedThreadPool(nproc);
		
		// Creating a bank with bankSize accounts. Each one with initialAmount euros
		Bank b = new Bank (bankSize,initialAmount);

		List<Callable> auditorList = new ArrayList();

		// we obtain the current time		
		Long time = new Date().getTime();
		
		// performing transfers
		System.out.println("Initial amount of money: "+b.audit(0,bankSize));
		for (int i=0;i<nproc;i++) {
			Transfers t = new Transfers (b,bankSize/nproc,bankSize); // Each thread performs nproc transfers
			executor.execute (t);
		}
		
		// List for storing the results of the audits. Take a look at Auditor class implementing Callable.
		List <Future <Long>> resultList = new ArrayList();

		// performing audits
		for (int i=0;i<10;i++) {
			Auditor a = new Auditor (b);
			Future <Long> result = executor2.submit(a);
			auditorList.add(a);
			resultList.add (result);
		}

		// waiting for all the threads to finish
		executor.shutdown();
		executor2.shutdown();
		//pool.shutdown();
		try {
			executor.awaitTermination(1, TimeUnit.DAYS); // waiting for all the transfers to finish
			for (int i=0;i<resultList.size();i++) 
				System.out.println ("Audit: "+i+": "+resultList.get(i).get()); // waiting for all the audits to finish
		} catch (Exception e) {e.printStackTrace();}

		System.out.println("Main: the amount of money at the end is: "+b.audit(0,bankSize));
	}
}
