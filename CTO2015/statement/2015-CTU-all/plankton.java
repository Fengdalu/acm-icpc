import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
/**
 * CTU Open 2015: Plankton
 * 
 * @author Martin Kacer
 */
public class plankton {
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
	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}
	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}
	public static void main(String[] args) throws Exception {
		plankton instance = new plankton();
		while (instance.run()) {/*empty*/}
	}
 
	static final double EPS = 1E-10;
 
	boolean[] neg, vis;
	double[] best;
	int[] fr, fg;
	double[] u;
	int[] q; int qb, qe;
 
	/** One pass of B-F, mark all changed nodes into "flag" (if not null). */
	void onePass(boolean[] flag) {
		for (int i = 0; i < u.length; ++i)
			if (best[fr[i]] + u[i] > best[fg[i]] + EPS) {
				if (flag != null) flag[fg[i]] = true;
				best[fg[i]] = best[fr[i]] + u[i];
			}
	}
 
	/** Run B-F from the TARGET node to check whether it is reachable. */
	boolean check(int fn) {
		if (neg[fn]) return true;
		vis = new boolean[neg.length];
		vis[fn] = true;
		for (int pass = 1; pass < neg.length; ++pass)
			for (int i = 0; i < u.length; ++i) {
				if (vis[fg[i]] && !vis[fr[i]]) {
					if (neg[fr[i]])
						return true;
					vis[fr[i]] = true;
				}
			}
		return false;
	}
 
	boolean run() throws Exception {
		int t = nextInt(), f = nextInt(), fu = nextInt()-1, fn = nextInt()-1;
		if (f == 0) return false;
		u = new double[t]; fr = new int[t]; fg = new int[t];
		for (int i = 0; i < t; ++i) {
			fr[i] = nextInt()-1; fg[i] = nextInt()-1; u[i] = nextDouble();
		}
		best = new double[f];
		for (int i = 0; i < f; ++i) best[i] = Double.NEGATIVE_INFINITY;
		best[fu] = 1.0;
		for (int i = 1; i < f; ++i) onePass(null);
		neg = new boolean[f];
		for (int i = 1; i < f; ++i) onePass(neg);
		System.out.println(check(fn) ? "TRUE" : "FALSE");
		return true;
	}
}
