#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define cmin(x, y) x = min(x, y)
#define AA first
#define BB second
#define MP make_pair
#define SZ size
#define PB push_back
#define PII pair<int, int>

const int N = 1e5+1000;
int f[N];
PII a[N];
int cc[N+N];
int sz;
int n, m;

int main() {

  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) scanf("%d%d", &a[i].AA, &a[i].BB);
  int T = a[0].BB - a[0].AA + 1;
  for(int i = 0; i < m; i++) cmin(T, a[i].BB - a[i].AA + 1);

  sort(a, a + m);
  queue<int> q;
  memset(f, -1, sizeof f);
  for(int i = 0; i < T; i++) q.push(i);
  int pre = 0;
  for(int i = 0; i < m; i++) {
    pre = max(pre, a[i].AA);
    while(q.size()) {
      f[pre++] = q.front();
      q.pop();
    }
    if(i < m - 1) {
      for(int j = a[i].AA; j < a[i + 1].AA; j++) {
          if(f[j] != -1) q.push(f[j]);
      }
    }
  }
  printf("%d\n", T);
  for(int i = 1; i <= n; i++) printf("%d ", f[i] == -1 ? 0 : f[i]);
  return 0;
}
