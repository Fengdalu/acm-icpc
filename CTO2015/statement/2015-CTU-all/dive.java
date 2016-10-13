import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
/**
 * CTU Open 2015: Screen
 * 
 * @author Martin Kacer
 */
public class dive {
	BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws Exception {
		dive instance = new dive();
		while (instance.run()) {/*empty*/}
	}
 
	class Picture {
		char[][] map;
		int pi, pj;
	}
 
	char x;
	int r, c;
 
	Picture read() throws Exception {
		Picture pic = new Picture();
		pic.map = new char[r][];
		pic.pj = -1;
		for (int i = 0; i < r; ++i) {
			String s = input.readLine();
			pic.map[i] = s.toCharArray();
			if (pic.pj < 0) {
				pic.pi = i; pic.pj = s.indexOf(x);
			}
		}
		input.readLine();
		return pic;
	}
 
	void paint(Picture pic, int i, int j) {
		if (i >= 0 && i < r && j >= 0 && j < c)
			pic.map[i][j] = x;
	}
 
	boolean run() throws Exception {
		String first = input.readLine();
		StringTokenizer tok = new StringTokenizer(first);
		r = Integer.parseInt(tok.nextToken()); c = Integer.parseInt(tok.nextToken());
		if (r == 0) return false;
		x = tok.nextToken().charAt(1);
		Picture p1 = read(), p2 = read(), p3 = new Picture();
		p3.map = new char[r][c];
		p3.pi = (p2.pi-p1.pi) << 1;
		p3.pj = (p2.pj-p1.pj) << 1;
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
			p3.map[i][j] = (p1.map[i][j] != x) ? p1.map[i][j] : p2.map[i][j];
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
			if (p1.map[i][j] == x)
				paint(p3, i + p3.pi, j + p3.pj);
		for (int i = 0; i < r; ++i)
			System.out.println(p3.map[i]);
		System.out.println();
		return true;
	}
}
