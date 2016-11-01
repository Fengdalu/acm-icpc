import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) {
    new Main().run();
  }

  int tri(int a, int b, int c) {
    if(a + b > c && b + c > a && a + c > b) return 3;
    return -1;
  }

  int seg(int a, int b, int c) {
    if(a + b == c || b + c == a || a + c == b) return 2;
    return -1;
  }

  public void run() {
    InputReader reader = new InputReader(System.in);
    PrintWriter writer = new PrintWriter(System.out);
    try {
      int T = reader.nextInt();
      int n = 4;
      while(T != 0) {
        T--;
        int[] a = new int[n];
        int ans = -1;
        for (int i = 0; i < n; i++) a[i] = reader.nextInt();
        for (int i = 0; i < n; i++)
          for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
              ans = Math.max(ans, Math.max(tri(a[i], a[j], a[k]), seg(a[i], a[j], a[k])));
        if (ans == -1) writer.write("IMPOSSIBLE");
        else if (ans == 2) writer.write("SEGMENT");
        else writer.write("TRIANGLE");
        writer.write("\n");
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
