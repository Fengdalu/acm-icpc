import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }

    class Pair implements Comparable {
        public int x, y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
        @Override
        public int compareTo(Object p) {
            Pair o = (Pair)p;
            if(x == o.x && y == o.y) return 0;
            if(x == o.x) {
                return new Integer(y).compareTo(o.y);
            }
            return new Integer(x).compareTo(o.x);
        }
    }
    public void run() {
        InputReader reader = new InputReader(System.in);
        PrintWriter writer = new PrintWriter(System.out);
        try {
            while(true) {
                int n = reader.nextInt();
                int cur = 0;
                ArrayList<Pair>f = new ArrayList<Pair>();
                for(int i = 0; i < n; i++) {
                    int x = reader.nextInt(), y = reader.nextInt();
                    f.add(new Pair(x, y));
                }
                Collections.sort(f);
                cur = f.get(0).x;
                int ans = 0;
                for(Pair p: f) {
                    ans += (cur - p.x);
                    cur += p.y;
                }
                writer.println(String.format("%.4f", 1.0 * ans / n));
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
