import java.util.concurrent.Callable;

public class Auditor implements Callable <Long> {
	Bank b;
	public Auditor (Bank _b) {
		b=_b;
	}
	
	public Long call () throws Exception {
		long result = b.audit(0,(b.bankSize()));
		return new Long (result);
	}

}
