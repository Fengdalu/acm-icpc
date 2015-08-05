package test;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class Main {
	static BigInteger f[] = new BigInteger[2200];

	static void init() {
		f[1] = BigInteger.valueOf(1);
		f[2] = BigInteger.valueOf(1);
		for (int i = 3; i <= 2000; i++) {
			f[i] = f[i - 1].add(f[i - 2]);
		}
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));

	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
			System.out));
	static String buf[];
	static String s;

	static BigInteger dfs(int n, BigInteger m) {
		for (int i = 1; true; i++) {
			if (m.add(BigInteger.valueOf(1)).compareTo(f[i]) == -1)
				return m.subtract(f[i - 2]);
		}
	}

	public static void main(String args[]) throws Exception {
		init();
		int n;
		BigInteger m;
		int T;
		T = Integer.parseInt(br.readLine());
		while (T != 0) {
			T--;
			buf = br.readLine().trim().split(" ");
			n = Integer.parseInt(buf[0]);
			m = new BigInteger(buf[1]);

			bw.write(dfs(n, m).mod(new BigInteger("258280327")).toString());
			bw.write(new String("\r\n"));
			bw.flush();
		}
		bw.flush();
	}
}