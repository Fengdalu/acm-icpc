#include <bits/stdc++.h>

typedef long long ll;
const int N = 2000;
bool vis[N];
int op[N];
ll w[N];
ll f[N];

int main() {
  int n, r, k;
  scanf("%d%d%d", &r, &k, &n);
  std::queue<int> q;
  for(int i = 0; i < n; i++) {
    int x; 
    scanf("%I64d", &w[i]); q.push(i);
  }

  ll tot = 0;
  ll s = 0;
  do {
    ll sum = 0;
    std::queue<int>cur;
    op[q.front()] = s;
    vis[q.front()] = true;
    f[q.front()] = tot;
    while(q.size() && sum + w[q.front()] <= k) {
      sum += w[q.front()];
      cur.push(q.front());
      q.pop();
    }
    tot += sum;
    while(cur.size()) { q.push(cur.front()); cur.pop(); }
    s++;
  } while(!vis[q.front()]);

  ll p = q.front();
  ll Q = s - op[p];
  ll left = op[p];
  ll g = tot - f[p];
  ll ans = 0;
  if(r <= left) {
    for(int i = 0; i < r % s; i++) {
      ll sum = 0;
      std::queue<int>cur;
      while(q.size() && sum + w[q.front()] <= k) {
        sum += w[q.front()];
        cur.push(q.front());
        q.pop();
      }
      ans += sum;
      while(cur.size()) { q.push(cur.front()); cur.pop(); }
    }
  }
  else {
    ans = g * ((r - left) / Q) + f[p];
    while(q.front() != p) { q.push(q.front()); q.pop(); }
    for(int i = 0; i < (r - left) % Q; i++) {
      ll sum = 0;
      std::queue<int>cur;
      while(q.size() && sum + w[q.front()] <= k) {
        sum += w[q.front()];
        cur.push(q.front());
        q.pop();
      }
      ans += sum;
      while(cur.size()) { q.push(cur.front()); cur.pop(); }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
