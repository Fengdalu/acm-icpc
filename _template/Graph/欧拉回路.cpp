/*
* 存存在条件为奇数度的点 $ 0 $ 个
* 有向图所有点入度等于出度
* 求欧拉回路需要注意访问过的边需要删除
* 待验证
*/
const int N = 100000;
const int M = 2 * N;
int stk[N], ind[N], vis[N], chose[N];
int nt[M], t[M], opp[M];

void dfs(int x) {
    int l = -1;
    stk[++l] = x;
    while(l >= 0) {
        x = stk[l--];
        for(int k = ind[x]; ind[x] != -1; ind[x] = nt[k], k = ind[x])
            if(!vis[k]) {
                // 无向图加入下面这句
                vis[k] = vis[opp[k]] = true;
                // ==================
                chose[k] = true;
                stk[++l] = x;
                stk[++l] = t[k];
                break;
            }
    }
}
