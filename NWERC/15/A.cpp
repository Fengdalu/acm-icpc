#include <bits/stdc++.h>

#define PII std::pair<int, int>
#define AA first
#define BB second
#define MP std::make_pair
using std::pair;

const int N = 1000000;
PII a[N];

int main() {
  // freopen("A.in", "r", stdin);
  int n, m;
  while(~scanf("%d%d", &n, &m)) {
    for(int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
    std::priority_queue< PII > Q;
    for(int i = 0; i < n; i++) {
      Q.push(MP(-a[i].first, -a[i].second));
    }

    int cnt = 0;
    std::priority_queue<int> live;

    int ans = 0;
    while(Q.size()) {
      PII cur = Q.top(); Q.pop();
//      printf("add: %d %d %d %d ", cur.AA, cur.BB, live.size());
      while(live.size() && live.top() - cur.AA > m) {
//        printf("pop: %d\n", live.top());
        live.pop();
      }
      if(cur.BB < 0) {
        int m;
        if(live.size()) { live.pop(); }
        else { m = ++cnt; ans++; }
//        printf("add: %d %d\n", m, cur.first);
        Q.push(MP(cur.AA + cur.BB, 1));
      }
      else {
        live.push(cur.AA);
//        puts("");
      }
    }
    printf("%d\n", n - ans);
  }
  return 0;
}
/*
3 5
1 5
6 3
14 6

5 10
2 6
1 2
17 7
3 9
15 6

3 10
1 9
8 99
20 4


2 100
1 1
2 1

1 100
100 100



*/
