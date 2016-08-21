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
                int[][] pre = new int[27][2];
                for(int i = 0; i < 27; i++) {
                    pre[i] = new int[2];
                    Arrays.fill(pre[i], 0);
                }
                for(int i = 0; i < n; i++) {
                    String word = reader.nextToken();
                    int len = word.length();
                    pre[word.charAt(0) - 'a'][0]++;
                    pre[word.charAt(len - 1) - 'a'][1]++;
                }
                int count = 0;
                for(int i = 0; i < 27; i++) {
                    if((pre[i][0] + pre[i][1]) % 2 == 1) count++;
                }
                if(count <= 2) writer.println("Yes");
                else writer.println("No");
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
