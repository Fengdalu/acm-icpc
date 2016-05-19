import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static boolean vis[] = new boolean[40000];
	public static ArrayList<Integer> f;

	public static void make() {
		for (int i = 0; i < 40000; i++)
			vis[i] = true;
		f = new ArrayList<Integer>(1);
		for (int i = 2; i < 40000; i++) {
			if (vis[i])
				f.add(i);
			for (int t : f) {
				if (t * i >= 40000)
					break;
				vis[t * i] = false;
				if (i % t == 0)
					break;
			}
		}
	}

	public static void main(String args[]) {
		make();

		String s;
		String buf[];
		Scanner in = new Scanner(System.in);

		while (true) {
			s = in.nextLine();
			if (s.equals("0"))
				break;
			buf = s.split(" ");
			long x = 1L;
			for (int i = 0; 2 * i + 1 < buf.length; i++) {
				long a = Long.parseLong(buf[2 * i]);
				long b = Long.parseLong(buf[2 * i + 1]);
				x *= Math.pow(a, b);
			}
			x -= 1;
			boolean flg = false;
			for (int i = f.size() - 1; i >= 0; i--) {
				int tmp = 0;
				if (x % (long) f.get(i) == 0) {
					while (x % (long) f.get(i) == 0) {
						x /= (long) f.get(i);
						tmp++;
					}
					if (flg)
						System.out.print(" " + f.get(i) + " " + tmp);
					else {
						flg = true;
						System.out.print(f.get(i) + " " + tmp);
					}
				}
			}
			System.out.println();
		}
		System.out.flush();
	}
}
