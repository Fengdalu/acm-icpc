#include <bits/stdc++.h>

using namespace std;
#define SZ size()
#define OP begin()
#define MP make_pair
#define AA first
#define BB second
#define PII pair<int, int>

const int N = 100;
char s[N][N];
int n, m, vis[N][N];

bool dfs(PII cur, PII fa) {
  const int V[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vis[cur.AA][cur.BB] = true;
  for(int i = 0; i < 4; i++) {
    int x = cur.AA + V[i][0], y = cur.BB + V[i][1];
    if(MP(x, y) == fa) continue;
    if(x < 0 || x > n - 1 || y < 0 || y > m - 1) continue;
    if(s[x][y] != s[cur.AA][cur.BB]) continue;
    if(vis[x][y] || dfs(MP(x, y), cur)) return true;
  }
  return false;
}


int main() {
//  freopen("a.in", "r", stdin);
  while(~scanf("%d%d", &n, &m)) {
    for(int i = 0; i < n; i++) scanf("%s", s[i]);
    memset(vis, 0, sizeof vis);
    bool flag = false;
    for(int i = 0; i < n; i++)
    if(!flag)
      for(int j = 0; j < m; j++)
      if(!flag && !vis[i][j]) {
          flag |= dfs(MP(i, j), MP(i, j));
          puts("");
      }
    if(flag) puts("Yes");
    else puts("No");
  }
  return 0;
}

