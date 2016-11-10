/*
 * 存存在条件为奇数度的点 $ 0 $ 个
 * 有向图所有点入度等于出度
 * 求欧拉回路需要注意访问过的边需要删除
 * 2016 NEERC Moscow G.
 */
#include <stack>
const int N = 1000;
const int M = N * N;
struct Graph {
  int ind[N], vis[N];
  int nt[M], t[M], opp[M], chose[M];
  std::stack<int> stk;

  void dfs(int x) {
    stk.push(x);
    while(stk.size()) {
      x = stk.top(); stk.pop();
      for(int k = ind[x]; ind[x] != -1; ind[x] = nt[k], k = ind[x])
        if(!vis[k]) {
          // 无向图加入下面这句
          vis[k] = vis[opp[k]] = true;
          // ==================
          chose[k] = true;
          stk.push(x);
          stk.push(t[k]);
          break;
        }
    }
    if(ind[x] == -1) {
      // 这里记录 答案
    }
  }
};
