import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
			System.out));
	static int[] count = new int[101];

	public static void main(String args[]) throws NumberFormatException,
			IOException {
		String a = br.readLine().trim();
		String b = br.readLine().trim();
		bw.write((new BigInteger(a)).add(new BigInteger(b)).toString());
		bw.flush();
		bw.close();
	}
}
