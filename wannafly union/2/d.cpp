#include <bits/stdc++.h>

using namespace std;
#define AA first
#define BB second
#define MP make_pair
#define SZ size()
#define PB push_back
#define PII pair<int, int>
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
typedef long long LL;

const int N = 2e5;
int n;
int a[N];
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  map<int, vector<int> > f;
  for(int i = 0; i < n - 1; i++) f[a[i + 1] - a[i]].PB(i);
  if(f.size() > 2) {
    puts("0");
  }
  else if(n == 1) {
    puts("-1");
  }
  else if(f.size() == 1) {
    int p = f.begin()->AA;
    if(p == 0) {
      printf("1\n");
      printf("%d\n", a[0]);
    } else if(n > 2) {
      printf("2\n");
      printf("%d %d\n", 2 * a[0] - a[1], 2 * a[n - 1] - a[n - 2]);
    }
    else {
      if(p % 2 == 0) {
        printf("3\n");
        printf("%d %d %d\n", 2 * a[0] - a[1], a[0] + p / 2, 2 * a[n - 1] - a[n - 2]);
      }
      else {
        printf("2\n");
        printf("%d %d\n", 2 * a[0] - a[1], 2 * a[n - 1] - a[n - 2]);
      }
    }
  }
  else {
    auto p = *f.begin(); f.erase(f.begin());
    auto q = *f.begin(); f.erase(f.begin());
    if(q.BB.SZ > 1 || q.AA != p.AA * 2) {
      puts("0");
    }
    else {
      printf("1\n");
      printf("%d\n", a[q.BB[0]] + p.AA);
    }
  }
  return 0;
}
