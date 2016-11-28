#include <bits/stdc++.h>

using namespace std;
const int N = 4e3, M = 2e4;
int last[N], nt[M], to[M], cnt, u[M], v[M], in[N], vis[N];
double dis[N], c[M], w[M];
int n, m;

void add(int a, int b, double _c) {
  to[cnt] = b; 
  c[cnt] = _c;
  nt[cnt] = last[a]; 
  last[a] = cnt++;
}

bool check(double x) {
  fill(last, last + n + 1, -1);
  fill(dis, dis + n + 1, 0);
  fill(in, in + n + 1, 0);
  fill(vis, vis + n + 1, true);
  cnt = 0;
  for(int i = 0; i < m; i++) add(u[i], v[i], w[i] - x);
  stack<int>q;
  for(int i = 1; i <= n; i++) q.push(i);
  while(q.size()) {
    int x = q.top();
    q.pop();
    if(in[x] >= n) return true;
    vis[x] = false;
    for(int k = last[x]; k != -1; k = nt[k]) {
      int v = to[k];
      if(dis[x] + c[k] <= dis[v]) {
        dis[v] = dis[x] + c[k];
        if(!vis[v]) {
          in[v]++;
          q.push(v);
          vis[v] = true;
        }
      }
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) 
    scanf("%d%d%lf", u + i, v + i, w + i);
  double l = *min_element(w, w + m), r = *max_element(w, w + m);

  for(int i = 0; i < 100; i++) {
    double mid = (l + r) / 2.0;
    if(check(mid)) r = mid;
    else l = mid;
  }
  printf("%.8f\n", l);
  return 0; 
}