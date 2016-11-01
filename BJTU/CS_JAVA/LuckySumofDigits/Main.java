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
        int sum = reader.nextInt();
        int a = -1, b = -1;
        for(int i = 0; i * 4 <= sum; i++) if((sum - i * 4) % 7 == 0) {
          int x = i, y = (sum - x * 4) / 7;
          if(a == -1 || (a + b) > x + y || (a + b == x + y && x > a)) {
            a = x;
            b = y;
          }
        }
        if(a == -1) {
          writer.write("-1");
        }
        else {
          for(int i = 0; i < a; i++) writer.write('4');
          for(int i = 0; i < b; i++) writer.write('7');
        }
        writer.write("\n");
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