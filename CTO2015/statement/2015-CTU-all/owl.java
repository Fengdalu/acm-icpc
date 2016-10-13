import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


/**
 * CTU Open 2015: Owl
 * 
 * @author Martin Kacer
 */
public class owl {
	StringTokenizer st = new StringTokenizer("");
	BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
	boolean hasNextToken() throws Exception {
		while (!st.hasMoreTokens()) {
			String line = input.readLine();
			if (line == null) return false;
			st = new StringTokenizer(line);
		}
		return true;
	}
	String nextToken() throws Exception {
		return (!hasNextToken()) ? null : st.nextToken();
	}
	public static void main(String[] args) throws Exception {
		owl instance = new owl();
		while (instance.run()) {/*empty*/}
	}
	
	int digsum(int x) {
		int sum = 0;
		while (x != 0) {
			sum += (x%10);
			x /= 10;
		}
		return sum;
	}

	boolean run() throws Exception {
		String s = nextToken();
		if ("END".equals(s)) return false;
		int num = Integer.parseInt(s);
		int ds = digsum(num) - 1;
		for (;;--num)
			if (digsum(num) == ds) {
				System.out.println(num);
				return true;
			}
	}
}
