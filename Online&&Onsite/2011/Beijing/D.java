import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class Main {

	/**
	 * @param args
	 */
	static BigInteger gcd(BigInteger a, BigInteger b) {
		if (b.equals(BigInteger.ZERO))
			return a;
		return gcd(b, a.mod(b));
	}

	static BigInteger dp[] = new BigInteger[505];

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub


		BigInteger fz[] = new BigInteger[505];
		BigInteger fm[] = new BigInteger[505];
		
		fz[1] = BigInteger.ONE;
		fm[1] = BigInteger.valueOf(2);
		
		for(int i=2;i<=500;i++)
		{
			fz[i]=fz[i-1].multiply(BigInteger.valueOf(2*i-1));
			fm[i]=fm[i-1].multiply(BigInteger.valueOf(2*i));
		}


		for (int i = 1; i <= 500; i++) {
			BigInteger gd = gcd(fm[i], fz[i]);
			fz[i] = fz[i].divide(gd);
			fm[i] = fm[i].divide(gd);
		}

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				System.out));

		int T = Integer.parseInt(br.readLine());
		for (int CAS = 0; CAS < T; CAS++) {
			int x = Integer.parseInt(br.readLine());
			bw.write(String.format("%s/%s\r\n", fz[x], fm[x]));
		}
		bw.flush();
		bw.close();

	}

}