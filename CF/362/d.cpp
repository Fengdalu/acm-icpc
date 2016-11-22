#include <bits/stdc++.h>

#define PB push_back
#define SZ size()
typedef std::vector<int> VI;

const int N = 1e5+10;
VI g[N];
int son[N];
double fact[N];
double ans[N];

void dfs(int x) {
  for(int i = 0; i < g[x].size(); i++) {
    dfs(g[x][i]);
    son[x] += son[g[x][i]];
  }
  son[x]++;
}

void cal(int x) {
  int sz = g[x].size();
  double sum = 0;
  double fa = ans[x];
  for(int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    sum += son[v];
  }
  // printf("%d : %lf\n", x, sum);
  for(int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    ans[v] = 1 + fa + (sum - son[v]) / 2;
    cal(v);
  }
}


int main() {
  fact[0] = 1;
  for(int i = 1; i < N; i++) fact[i] = fact[i - 1] * i;

  int n; scanf("%d", &n);
  for(int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    g[p].push_back(i);
  }
  ans[1] = 1;
  dfs(1);
  cal(1);
  for(int i = 1; i <= n; i++) printf("%.2f ", ans[i]);
  return 0;
}
