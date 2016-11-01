import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    new Main().run();
  }

  public void run() {
    InputReader reader = new InputReader(System.in);
    PrintWriter writer = new PrintWriter(System.out);
    try {
      int n = reader.nextInt();
      HashMap<String, Integer> names = new HashMap<String, Integer>();
      for(int i = 0; i < n; i++) {
        String name = reader.nextToken();
        if(names.get(name) == null) {
          writer.write("OK\n");
          names.put(name, 0);
        }
        else {
          int count = names.get(name);
          while(true) {
            String output = String.format("%s%d", name, count + 1);
            if(names.get(output) == null) {
              writer.write(output + "\n");
              names.put(output, 0);
              break;
            }
            count++;
          }
        }
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

    public long nextLong() throws IOException {
      return Long.parseLong(nextToken());
    }

    private BufferedReader  reader;
    private StringTokenizer tokenizer;
  }

  private void debug(Object...o) {
    System.err.println(Arrays.deepToString(o));
  }
}
