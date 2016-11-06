#include <bits/stdc++.h>

int main() {
  int n, r, k;
  scanf("%d%d%d", &r, &k, &n);
  std::queue<int> q;
  for(int i = 0; i < n; i++) {
    int x; 
    scanf("%d", &x); q.push(x);
  }
  
  int ans = 0;
  for(int i = 0; i < r; i++) {
    int sum = 0;
    std::queue<int>cur;
    while(q.size() && sum + q.front() <= k) {
      sum += q.front();
      cur.push(q.front());
      q.pop();
    }
    ans += sum;
    while(cur.size()) { q.push(cur.front()); cur.pop(); }
  }
  printf("%d\n", ans);
  return 0;
}
