import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) {
    new Main().run();
  }

  public void run() {
    InputReader reader = new InputReader(System.in);
    PrintWriter writer = new PrintWriter(System.out);
    try {
      int T = reader.nextInt();
      while(T != 0) {
        int n = reader.nextInt();
        if(n % 2 == 0 && n != 2) writer.write("YES\n");
        else writer.write("NO\n");
        T--;
      }
    } catch (Exception e) {
    } finally {
      writer.close();
    }
  }

  class InputReader {
    InputReader(InputStream in) {
      this.reader    = new BufferedReader(new InputStreamReader(in));
      this.tokenizer = new StringTokenizer("");
    }

    public String nextToken() throws IOException {
      while (!tokenizer.hasMoreTokens()) {
        tokenizer = new StringTokenizer(reader.readLine());
      }
      return tokenizer.nextToken();
    }

    public int nextInt() throws IOException {
      return Integer.parseInt(nextToken());
    }

    private BufferedReader  reader;
    private StringTokenizer tokenizer;
  }

  private void debug(Object...o) {
    System.err.println(Arrays.deepToString(o));
  }
}
