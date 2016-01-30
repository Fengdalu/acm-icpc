import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) {
        new Solution().run();
    }

    public void run() {
        InputReader reader = new InputReader(System.in);
        try {
            int n = reader.nextInt();
            List<List<Integer>> graph = new ArrayList<List<Integer>>();
            for (int i = 0; i < n; ++ i) {
                graph.add(new ArrayList<Integer>());
            }
            if (true) {
                int m = reader.nextInt();
                for (int i = 0; i < m; ++ i) {
                    int a = reader.nextInt() - 1;
                    int b = reader.nextInt() - 1;
                    graph.get(a).add(b);
                    graph.get(b).add(a);
                }
            }
            int[] color = new int[n];
            Arrays.fill(color, -1);
            for (int s = 0; s < n; ++ s) {
                if (color[s] == -1) {
                    color[s] = 0;
                    int[] count = new int[2];
                    List <Integer> queue = new ArrayList<Integer>();
                    queue.add(s);
                    for (int h = 0; h < queue.size(); ++ h) {
                        int u = queue.get(h);
                        count[color[u]] ++;
                        for (int v : graph.get(u)) {
                            if (color[v] == -1) {
                                color[v] = color[u] ^ 1;
                                queue.add(v);
                            }
                        }
                    }
                    if (count[0] > count[1]) {
                        for (int v : queue) {
                            color[v] ^= 1;
                        }
                    }
                }
            }
            int[] v0 = new int[n];
            int[] v1 = new int[n];
            int n0 = 0;
            int n1 = 0;
            for (int i = 0; i < n; ++ i) {
                if (color[i] == 0) {
                    v0[n0 ++] = i;
                } else {
                    v1[n1 ++] = i;
                }
            }
            v0 = Arrays.copyOf(v0, n0);
            v1 = Arrays.copyOf(v1, n1);
            int result = 0;
            for (int mask = 0; mask < 1 << n0; ++ mask) {
                int m = 0;
                int[] id = new int[n];
                Arrays.fill(id, -1);
                boolean[] dominated = new boolean[n];
                for (int i = 0; i < n0; ++ i) {
                    int u = v0[i];
                    if ((mask >> i & 1) == 1) {
                        dominated[u] = true;
                        for (int v : graph.get(u)) {
                            dominated[v] = true;
                        }
                    } else {
                        id[u] = m ++;
                    }
                }
                int[] ways = new int[1 << m];
                ways[0] = 1;
                for (int i = 0; i < n1; ++ i) {
                    int u = v1[i];
                    int cover = 0;
                    for (int v : graph.get(u)) {
                        if (id[v] != -1) {
                            cover |= 1 << id[v];
                        }
                    }
                    for (int newMask = (1 << m) - 1; newMask >= 0; -- newMask) {
                        int w = ways[newMask];
                        ways[newMask] = 0;
                        if (dominated[u]) {
                            ways[newMask] += w;
                        }
                        ways[newMask | cover] += w;
                    }
                }
                result += ways[(1 << m) - 1];
            }
            PrintWriter writer = new PrintWriter(System.out);
            writer.println(result);
            writer.close();
        } catch (IOException e) {
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
