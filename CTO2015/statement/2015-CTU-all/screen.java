import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
/**
 * CTU 2015: Numerical expressions
 * 
 * @author Martin Kacer
 */
public class screen {
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
	public static void main(String[] args) throws Exception {
		screen instance = new screen();
		while (instance.run()) {/*empty*/}
	}
 
	char[][] map;
 
	class Context {
		int row, pos, end;
		public Context(int row, int pos, int end) { this.row = row; this.pos = pos; this.end = end; }
		char nextChar() {
			while (pos < end && map[row][pos] == ' ') ++pos;
			if (pos == end) return 0;
			return map[row][pos++];
		}
		Context back() { if (pos < end) --pos; return this; }
	}
 
	boolean run() throws Exception {
		int r = nextInt(), c = nextInt();
		if (r == 0) return false;
		map = new char[r][];
		for (int i = 0; i < r; ++i)
			map[i] = input.readLine().toCharArray();
		System.out.println(evalExpr(new Context((r == 1) ? 0 : 1, 0, c)));
		return true;
	}
 
	int evalExpr(Context ctx) {
		int sum = evalTerm(ctx);
		for (;;) {
			char nxt = ctx.nextChar();
			if (nxt == '+') sum += evalTerm(ctx);
			else if (nxt == '-') sum -= evalTerm(ctx);
			else return sum;
		}
	}
 
	int evalTerm(Context ctx) {
		int sum = evalOne(ctx);
		while (ctx.nextChar() == '*')
			sum *= evalOne(ctx);
		ctx.back();
		return sum;
	}
 
	int evalOne(Context ctx) {
		char ch = ctx.nextChar();
		if (ch == '=') {
			int pos = ctx.pos-1;
			while (ctx.nextChar() == '=') {/*nothing*/}
			ctx.back();
			int num = evalExpr(new Context(ctx.row-1, pos, ctx.pos)), den = evalExpr(new Context(ctx.row+1, pos, ctx.pos));
			return num/den;
		} else if (ch == '\\') {
			int end = ++ctx.pos;
			while (end < ctx.end && map[ctx.row-1][end] == '_') ++end;
			int val = evalExpr(new Context(ctx.row, ctx.pos, end));
			ctx.pos = end;
			return (int) Math.round(Math.sqrt(val));
		} else {
			int num = 0;
			while (ch >= '0' && ch <= '9') {
				num = num * 10 + (ch - '0');
				ch = ctx.nextChar();
			}
			ctx.back();
			return num;
		}
	}
}
