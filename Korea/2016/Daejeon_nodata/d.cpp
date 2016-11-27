#include <bits/stdc++.h>
using namespace std;

#define cmin(x, y) x = min(x, y)
const int N = 2000, M = 50000*3;
int c[N], last[N], to[M], nt[M], u[M], v[M], vis[N], vis1[N], match[N], cnt;

void add(int a, int b) {
  to[cnt] = b;
  nt[cnt] = last[a];
  last[a] = cnt++;
}

bool dfs(int x) {
  for(int k = last[x]; k != -1; k = nt[k]) {
    int v = to[k];
    if(vis[v]) continue;
    vis[v] = true;
    if(match[v] == -1 || dfs(match[v])) {
      match[v] = x;
      return true;
    }
  }
  return false;
}

int main() {
//  freopen("a.in", "r", stdin);
  int n, m;
  while(~scanf("%d%d", &n, &m)) {

    fill(c, c + n + 1, -1);
    fill(last, last + n + 1, -1);
    cnt = 0;

    for(int i = 0; i < m; i++) {
      int a, b; scanf("%d%d", &a, &b);
      u[i] = a; v[i] = b;
      add(a, b); add(b, a);
    }
    for(int i = 1; i <= n; i++) if(c[i] == -1) {
      queue<int> q;
      q.push(i);
      c[i] = 0;
      while(q.size()) {
        int x = q.front();  q.pop();
        for(int k = last[x]; k != -1; k = nt[k]) {
          int v = to[k];
          if(c[v] != -1) continue;
          c[v] = c[x] ^ 1;
          q.push(v);
        }
      }
    }

    fill(last, last + n + 1, -1);
    cnt = 0;
    fill(match, match + n + 1, -1);
    for(int i = 0; i < m; i++) {
      int a = c[u[i]], b = c[v[i]];
      if(a > b) swap(u[i], v[i]);
      add(u[i], v[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      fill(vis, vis+n+1, 0);
      if(dfs(i)) ans++;
    }
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++) {
      if(match[i] != -1) printf("%d %d\n", match[i], i);
    }
    printf("%d\n", n - ans);
    fill(vis, vis + n + 1, true);
    fill(vis1, vis1 + n + 1, false);
    cnt = 0;
    bool flag = false;
    for(int i = 1; i <= n; i++) if(match[i] != -1) {
      vis1[i] = vis1[match[i]] = true;
      u[cnt] = i; v[cnt] = match[i]; cnt++;
    }
    for(int i = 1; i <= n; i++) if(vis1[i] == false) {
      for(int k = last[i]; k != -1; k = nt[k]) {
        int v = to[k];
        vis[v] = false;
      }
      if(flag) printf(" ");
      printf("%d", i);
      flag = true;
    }

    for(int i = 0; i < cnt; i++) {
      int cur;
      if(vis[u[i]]) cur = u[i]; else cur = v[i];
      if(flag) printf(" ");
      printf("%d", cur);
      flag = true;
      for(int k = last[cur]; k != -1; k = nt[k])
        vis[to[k]] = false;
    }
    puts("");
  }
  return 0;
}

/*
8 12
1 2
2 8
8 7
7 1
3 4
4 6
6 5
5 3
1 3
2 4
5 7
6 8
9 11
4 2
4 5
4 7
4 8
9 2
9 5
9 6
9 7
9 8
3 2
2 1
6 5
1 2
1 3
1 4
5 4
6 4
*/
