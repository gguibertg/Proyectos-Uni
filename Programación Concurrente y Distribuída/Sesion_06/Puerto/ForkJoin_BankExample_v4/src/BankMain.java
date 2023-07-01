
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
	// This example illustrates how to use ForkJoin pool to obtain a result
	// We create a new class TaskPoorAccounts for finding out those accounts with an amount below a given number.
	// Take a look at the new class TaskPoorAccounts. It implements RecursiveTask interface.
	public static void main(String[] args) {
		
		int bankSize = 1000;
		int initialAmount = 1000;
		int amount = 5; // amount of money for the Gift

		// Obtaining and printing the number of cores of the machine in which the program is being executed
		int nproc = Runtime.getRuntime().availableProcessors();
		System.out.println("Number of cores: "+nproc);
		
		// Creating the executors with nproc threads
		ThreadPoolExecutor executor = (ThreadPoolExecutor)Executors.newFixedThreadPool(nproc);
		ThreadPoolExecutor executor2 = (ThreadPoolExecutor)Executors.newFixedThreadPool(nproc);
		
		// Creating a bank with bankSize accounts. Each one with initialAmount euros
		Bank b = new Bank (bankSize,initialAmount);

		// Lists for storing threads
		List<Runnable> transferList = new ArrayList();
		List<Callable> auditorList = new ArrayList();
		
		// we obtain the current time		
		Long time = new Date().getTime();
		
		// performing transfers
		System.out.println("Initial amount of money: "+b.audit(0,bankSize));
		for (int i=0;i<nproc;i++) {
			Transfers t = new Transfers (b,bankSize/nproc,bankSize); // Each thread performs nproc transfers
			executor.execute (t);
			transferList.add(t);
		}
		
		List <Future <Long>> resultList = new ArrayList();

		// performing audits
		for (int i=0;i<10;i++) {
			Auditor a = new Auditor (b);
			Future <Long> result = executor2.submit(a);
			auditorList.add(a);
			resultList.add (result);
		}
		
		// performing gifts		
		Gift g = new Gift (b,0,b.bankSize(),amount);
		ForkJoinPool pool = new ForkJoinPool();
		pool.execute(g);
		System.out.println("Launched fork/join");
		
		// waiting for all the threads to finish
		executor.shutdown();
		executor2.shutdown();
		pool.shutdown();
		try {
			executor.awaitTermination(1, TimeUnit.DAYS); // waiting for all the transfers to finish
			for (int i=0;i<resultList.size();i++) 
				System.out.println ("Audit: "+i+": "+resultList.get(i).get()); // waiting for all the audits to finish
		} catch (Exception e) {e.printStackTrace();}
		
		// performing TaskPoorAccounts for finding accounts with a balance below a given amount
		ForkJoinPool pool2 = new ForkJoinPool();
		List <Integer> poorList = new ArrayList();
		long limit = 975;
		TaskPoorAccounts t = new TaskPoorAccounts (b,0,b.bankSize(),poorList,limit);
		pool2.execute (t);
		pool2.shutdown();
		try {
			pool2.awaitTermination(1, TimeUnit.DAYS);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		// Checking sequentially that the returned list is correct
		System.out.println(poorList);
		for (int i=0;i<bankSize;i++) {
			if (b.getAccount(i).getbalance()<limit) 
				System.out.print(i+" ");
		}
		
		System.out.println("\nMain: the amount of money at the end is: "+b.audit(0,bankSize));
	}
}
