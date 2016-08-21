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
            while(true) {
                int n = reader.nextInt();
                int m = reader.nextInt();
                boolean[] in = new boolean[201];
                Arrays.fill(in, false);
                Queue<Integer>q = new LinkedList<Integer>();
                int ans = 0;
                while(m != 0) {
                    m--;
                    int x = reader.nextInt();
                    x--;
                    if(in[x]) continue;
                    in[x] = true;
                    ans ++;
                    q.offer(x);
                    while(q.size() > n) in[q.poll()] = false;
                }
                writer.println(String.format("%d", ans));
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
