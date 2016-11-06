#include <bits/stdc++.h>
#include <unordered_map>

const int inf = 1e9+7;
int main() {
  // freopen("B.in", "r", stdin);
  int m, c, n;
  while(~scanf("%d%d%d", &m, &c, &n)) {
    if(m == 0 && c == 0 && n == 0) break;
    std::vector< std::queue<int> > q(n);
    for(int i = 0; i < n; i++) {
      int nn; scanf("%d", &nn);
      for(int j = 0; j < nn; j++) {
        int x; scanf("%d", &x);
        q[i].push(x);
      }
    }
    std::queue<int> job;
    for(int i = 0; i < n; i++) {
      job.push(i);
    }
    std::vector< std::map<int, int>  > desk(m + 1);
    std::vector<int> cost(m + 1);
    std::vector<int> order(m + 1);
    for(int i = 1; i <= m; i++) order[i - 1] = i;
    order[m] = 0;
    for(int i = 1; i <= m; i++) cost[i] = i;
    cost[0] = m + 1;
    std::unordered_map<int, int> pos;
    std::unordered_map<int, int> last;

    int ans = 0;
    int TL = 0;
    int cur = 1;
    while(job.size()) {
      int cur = q[job.front()].front(); q[job.front()].pop(); 
      if(q[job.front()].size()) job.push(job.front()); job.pop();


      ans += cost[pos[cur]];
      desk[pos[cur]].erase(last[cur]);
      if(desk[1].size() == c) {
        for(auto &j: order)
        if(j != 1 && (desk[j].size() < c || j == 0)) {
          pos[cur] = j;
          last[cur] = inf;
          ans += cost[j];
          desk[j][last[cur]] = cur;
          break;
        }

        int q = desk[1].begin()->second;
        desk[1].erase(desk[1].begin());
        ans += cost[1];

        for(auto &j: order)
        if(j != 1 && (j == 0 || desk[j].size() < c)) {
          ans += cost[j];
          pos[q] = j;
          desk[j][last[q]] = q;
          break;
        }
        q = pos[cur];
        ans += cost[q];
        desk[q].erase(last[cur]);
        desk[1][++TL] = cur;
        ans += cost[1];
        last[cur] = TL;
        pos[cur] = 1;
      }
      else {
        desk[1][++TL] = cur;
        pos[cur] = 1;
        ans += cost[1];
        last[cur] = TL;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
