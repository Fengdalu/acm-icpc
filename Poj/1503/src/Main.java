import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class Main {
	public BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	public BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	public void run() throws IOException {
		BigInteger result = BigInteger.ZERO;
		String line;
		while ((line = reader.readLine()) != null) {
			if (line.equals("0"))
				break;
			result = result.add(new BigInteger(line));
		}
		writer.write(result.toString());
		writer.flush();
	}

	public static void main(String args[]) throws IOException {
		new Main().run();
	}
}
