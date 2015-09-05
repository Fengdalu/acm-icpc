import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
			System.out));

	static BigDecimal a[] = new BigDecimal[101];
	static String buf[];

	public static void main(String args[]) throws NumberFormatException,
			IOException {
		int T;
		T = Integer.parseInt(br.readLine().trim());
		while (T != 0) {
			T--;
			int n;
			n = Integer.parseInt(br.readLine().trim());
			buf = br.readLine().trim().split(" ");
			for (int i = 0; i < n; i++)
				a[i] = new BigDecimal(buf[i]);

			boolean flg = true;
			int cnt = 0;
			for (int i = 0; i < n; i++)
				if (a[i].equals(BigDecimal.ZERO)) {
					flg = false;
					cnt++;
				}
			for (int i = 2; i < n; i++)
				if (!a[i].multiply(a[i - 2])
						.equals(a[i - 1].multiply(a[i - 1])) || !flg) {
					flg = false;
					break;
				}
			if (flg || cnt == n)
				bw.write("Yes\r\n");
			else
				bw.write("No\r\n");

		}
		bw.flush();
	}
}
