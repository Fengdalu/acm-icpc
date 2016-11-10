/*
 * 增广路版费用流，复杂度$ O(n^{2}m) $
 * 调用之前需要清空ind并令$ cnt = 1 $
 */
#include <bits/stdc++.h>
#define N 3000
#define M 100000
#define INF 0x7fffffff
typedef long long ll;

int ind[N], pre[N], f[N];
bool vis[N];
int bg[M], t[M], nt[M], c[M], op[M], v[M];
int cnt;
int S, T;

int add(int a, int b, int C, int V) { //  不要直接调用
  bg[cnt] = a;
  t[cnt] = b;
  v[cnt] = V;
  c[cnt] = C;
  nt[cnt] = ind[a];
  ind[a] = cnt;
  return cnt++;
}

int ADD(int a, int b, int c, int v) {
  int x = add(a, b, c, v);
  int y = add(b, a, 0, -v);
  op[x] = y; op[y] = x;
  return x;
}

int h[N], q[N];

bool spfa() {
  memset(vis, 0, sizeof vis);
  for(int i = S; i <= T; i++) f[i] = INF;
  for(int i = S; i <= T; i++) pre[i] = -1;
  pre[S] = -1;
  f[S] = 0;
  int l = 0, r = 0; q[l] = S; vis[S] = true;
  while(l <= r)
  {
    int x = q[l % N];
    l++; vis[x] = false;
    for(int k = ind[x]; k != -1; k = nt[k])
      if(c[k] > 0 && f[t[k]] > f[x] + v[k])
      {
        f[t[k]] = f[x] + v[k];
        pre[t[k]] = k;
        if(!vis[t[k]])
        {
          r++;
          q[r % N] = t[k];
          vis[t[k]] = true;
        }
      }
  }
  return pre[T] != -1;
}

int dfs()
{
  int ans = INF;
  int k = pre[T];
  while(k != -1)
  {
    ans = std::min(ans, c[k]);
    k = pre[bg[k]];
  }
  k = pre[T];
  while(k != -1)
  {
    c[k] -= ans;
    c[op[k]] += ans;
    k = pre[bg[k]];
  }
  return ans;
}

ll dinic() {// 程序入口
  ll ans = 0, tmp;
  while(spfa())
  {
    ans += (ll)f[T] * dfs();
  }
  return ans;
}
