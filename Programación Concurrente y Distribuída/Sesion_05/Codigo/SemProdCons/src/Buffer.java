public class Buffer {
	int size, head, tail;
	int buffer[];
		
	public Buffer (int size) {
		buffer = new int[size];
		this.size = size;
		head = tail = 0;
	}
		
	public void insert (int elem) {
		System.out.print ("Inserting the element "+elem+" ...");
	    buffer[head] = elem;
	    head = (head + 1) % size;
	    System.out.println ("OK");
	}
	
	public int extract () {
		System.out.print ("Extracting an element .... ");
		int elem = buffer[tail];
		tail = (tail + 1) % size;
		System.out.println (elem);
		return elem;
	}
}
