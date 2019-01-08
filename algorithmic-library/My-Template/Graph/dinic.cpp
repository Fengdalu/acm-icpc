/*
 * dinic 模板
 *
 */
#include <bits/stdc++.h>
namespace dinic {
    const int N = 1e3;
    const int M = 1e4;
    const int INF = 1e9+7;
    int f[N];
    int q[N];
    bool vis[N];
    int h[N];
    int ind[N];
    int t[M], c[M], nt[M], opp[M];
    int cnt;
    int n, m;
    int ST, ED;

    int add(int a, int b, int C) {
      t[cnt] = b;
      nt[cnt] = ind[a];
      ind[a] = cnt;
      c[cnt] = C;
      return cnt++;
    }

    void add1(int a, int b, int c) {
      static int x, y;
      x = add(a, b, c);
      y = add(b, a, 0);
      opp[x] = y; opp[y] = x;
    }

    bool bfs() {
      int l = 0, r = 0;
      q[l] = ST;
      memset(h, 0, sizeof h);
      h[ST] = 1;
      while(l <= r) {
        int x = q[l++];
        for(int k = ind[x]; k != -1; k = nt[k])
          if(!h[t[k]] && c[k] > 0) {
            h[t[k]] = h[x] + 1;
            q[++r] = t[k];
          }
      }
      return h[ED] != 0;
    }

    int dfs(int x, int p) {
      if(x == ED) return p;
      bool flg = false;
      int tot = 0;
      for(int k = ind[x]; k != -1; k = nt[k])
        if(h[t[k]] == h[x] + 1) {
          int d = dfs(t[k], min(p, c[k]));
          if(d) {
            p -= d;
            tot += d;
            c[k] -= d;
            flg = true;
            c[opp[k]] += d;
          }
        }
      return tot;
    }

    int dinic() {
      int ans = 0, tmp;
      while(bfs()) {
        while(true) {
          int fw = dfs(ST, INF);
          if(!fw) break;
          else ans += fw;
        }
      }
      return ans;
    }
}
