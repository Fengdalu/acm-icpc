#include <bits/stdc++.h>

const int N = 200, M = 200, MAXT = 1e4+100;

double x[MAXT], y[MAXT];
int linker[N];
bool used[N];
std::vector<int> g[N];

bool dfs(int u) {
  for(int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if(!used[v]) {
      used[v] = true;
      if(linker[v] == -1 || dfs(linker[v])) {
        linker[v] = u;
        return true;
      }
    }
  }
  return false;
}

int hungary(int n) {
  int res = 0;
  memset(linker, -1, sizeof(linker));
  for(int u = 0; u < n; u++) {
    std::fill(used, used + n + 1, 0);
    if(dfs(u)) res++;
  }
  return res;
}

double sqr(double x) { return x * x; }

int main() {
  int T; 
  scanf("%d", &T);
  while(T--) {
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    for(int i = 0; i < t; i++) scanf("%lf%lf", x + i, y + i);
    for(int i = 0; i < t; i++) {
      y[i] = y[i] - sqrt(sqr(n / 2.0) - sqr(1.0 * n / 2.0 - x[i]));
    }
    int up = (int)*std::max_element(x, x + t);
    for(int i = 0; i < up + 1; i++) g[i].clear();
    for(int i = 0; i < t; i++) {
      int u = x[i];
      // g[u].push_back(ceil(y[i]));
      g[u].push_back(floor(y[i]));
    }
    printf("%d\n", hungary(up + 1));
  }
  return 0;
}
