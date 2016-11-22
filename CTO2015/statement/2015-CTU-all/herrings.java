import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
/**
 * CTU Open 2015: Feeding Herrings
 * There are (intentionally) several inefficiencies. Still should be within the time limit.
 * @author Martin Kacer
 */
public class herrings {
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
		herrings instance = new herrings();
		while (instance.run()) {/*empty*/}
	}
 
	static final int MODULE = 12345647;
	char[] number, limit;
	int[][][] res;
 
	int compute(int limask, int carry, int pos) {
		if (pos < 0) return (limask == 0 && carry == 0) ? 1 : 0;
		if (res[limask][carry][pos] > 0)
			return res[limask][carry][pos] - 1;
		int lim = limit[pos] - '0', dig = number[pos] - '0' - carry; // -2 to 9
		int sum = 0;
		for (int d1 = 0; d1 < 10; ++d1)
			for (int d2 = 0; d2 < 10; ++d2) {
				int dr = 20 + dig - d1 - d2; // (18 to 29) - (0 to 18) = (0 to 29)
				int d3 = dr%10, c = 2 - dr/10;
				if (c < 0 || d1 == 3 || d2 == 3 || d3 == 3) continue;
				int msk = ((d1>lim || (d1==lim)&&((limask&1)==0)) ? 0 : 1)
						| ((d2>lim || (d2==lim)&&((limask&2)==0)) ? 0 : 2)
						| ((d3>lim || (d3==lim)&&((limask&4)==0)) ? 0 : 4);
				sum += compute(msk, c, pos-1);
			}
		//System.out.println("" + limask + carry + " " + pos + ": " + sum);
		res[limask][carry][pos] = (sum % MODULE) + 1;
		return sum % MODULE;
	}
 
	boolean run() throws Exception {
		String N = nextToken(), L = nextToken();
		if ("0".equals(N)) return false;
		number = N.toCharArray();
		StringBuilder sb = new StringBuilder();
		for (int i = L.length(); i < N.length(); ++i) sb.append('0');
		sb.append(L);
		limit = sb.toString().toCharArray();
		res = new int[8][3][number.length];
		System.out.println(compute(0, 0, number.length-1));
		return true;
	}
}
