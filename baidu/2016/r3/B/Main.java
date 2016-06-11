import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int n, m, k;
    public static int maxn = 15;
    long two[] = new long[1000];
    long f[] = new long[1 << 20];
    long g[] = new long[1 << 20];
    long dp[][] = new long[1 << 20][maxn];
    long mod = 1000000009;

    public int ones(int x) {
        int tot = 0;
        while(x != 0) {
            if((x & 1) != 0) tot++;
            x /= 2;
        }
        return tot;
    }

    long dfs(int mask, int cnt) {
        if(cnt == -1) return 0;
        if(ones(mask) == cnt) return 1;
        if(ones(mask) < cnt) return 0;
        if(dp[mask][cnt] != -1) return dp[mask][cnt];
        dp[mask][cnt] = 0;
        ArrayList<Integer>q = new ArrayList<Integer>();
        for(int i = 0; i < n; i++)
            if((1 << i & mask) != 0) q.add(i);
        for(int mk = 0; mk < (1 << q.size()); mk++)
            if((1 & mk) != 0) {
                int now = 0;
                for(int j = 0; j < q.size(); j++)
                    if((1 << j & mk) != 0)
                        now |= 1 << q.get(j);
                if(f[now] != 0)
                    dp[mask][cnt] = (dp[mask][cnt] + f[now] * dfs(mask ^ now, cnt - 1) % mod) % mod;
            }
        return dp[mask][cnt];
    }

    public void run() throws Exception{
        two[0] = 1;
        for(int i = 1; i < 1000; i++) two[i] = two[i - 1] * (long)2 % mod;
        int nnn = Integer.parseInt(br.readLine());
        for(int nn = 1; nn <= nnn; nn++) {

            String args[] = br.readLine().trim().split(" ");
            n = Integer.parseInt(args[0]);
            m = Integer.parseInt(args[1]);
            k = Integer.parseInt(args[2]);
            for(int i = 0; i < 1 << n; i++) f[i] = g[i] = 0;
            long loop = 0;
            for(int i = 0; i < m; i++) {
                int x, y;
                args = br.readLine().trim().split(" ");
                x = Integer.parseInt(args[0]);
                y = Integer.parseInt(args[1]);
                x--; y--;
                if(x == y) {  loop++; continue; }
                int mk = ((1 << n) - 1) ^ (1 << x) ^ (1 << y);
                int sub = mk;
                do {
                    g[sub | (1 << x) | (1 << y)]++;
                    sub = (sub - 1) & mk;
                }while(sub != mk);
            }
            for(int mk = 1; mk < (1 << n); mk++) {
                f[mk] = two[(int)g[mk]];
                int id;
                for(id = 0; ; id++) if((1 << id & mk) != 0) break;
                int sub = mk ^ (1 << id);
                int msub = sub;
                do {
                    int now = sub | (1 << id);
                    if(now != mk) {
                        f[mk] = ((f[mk] - f[now] * two[(int)g[mk ^ now]]) % mod + mod) % mod;
                    }
                    sub = (sub - 1) & msub;
                } while(sub != msub);
            }
            for(int i = 0; i < (1 << n); i++) for(int j = 0; j <= n; j++) assert(j < maxn);
            for(int i = 0; i < (1 << n); i++) for(int j = 0; j <= n; j++) dp[i][j] = -1;
            int mask = (1 << n); mask --;
            bw.write(String.format("Case #%d:\n", nn));
            bw.write(String.format("%d", dfs(mask, k) * two[(int)loop] % mod));
            bw.flush();
        }
    }

    public static void main(String[] args) throws Exception {
	// write your code here
        new Main().run();
    }
}
