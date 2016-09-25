#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SQ(x) ((x)*(x))
#define Maxn 111
#define Maxm 11111
const int MOD = 1000000007;

struct node {
    int u, v, next;
    double w;
}e[Maxm];
int n, m;
int px[Maxn], py[Maxn];

/* 
 * 最小树形图（根固定）     O(VE)
 * 有向图最小生成树
 * 根不固定，添加一个根节点与所有点连无穷大的边！
 * 如果求出比2*MOD大, 则不连通; 求根, 则求和虚拟根相连的结点
 * 根据pre的信息能构造出这棵树！
 * 注意结点必须从0~n-1, 因为要考虑重新标号建图的统一
 * mytype 根据实际情况确定
 */
typedef double mytype;
int visit[Maxn], pre[Maxn], belong[Maxn];
mytype inv[Maxn]; 
mytype dirtree(int n, int m, int root) {
    mytype sum = 0;
    int i, j, k, u, v;
    while (1) {
        for (i = 0; i < n; i++) {
            inv[i] = MOD;
            pre[i] = -1;
            belong[i] = -1;
            visit[i] = -1;
        }
        inv[root] = 0;
        for (i = 0; i < m; i++) {//除原点外，找每个点的最小入边
            u = e[i].u; v = e[i].v;
            if (u != v) {
                if (e[i].w < inv[v]) {
                    inv[v] = e[i].w;
                    pre[v] = u;
                }
            }
        }
        for (i = 0; i < n; i++) {
            if (inv[i] == MOD) return -1;
        }
        int num = 0;
        for (i = 0; i < n; i++) { //找圈，收缩圈
            if (visit[i] == -1) {
                j = i;
                for(j = i; j != -1 && visit[j] == -1 && j != root; j = pre[j]) {
                    visit[j] = i;
                }
                if (j != -1 && visit[j] == i) {
                    for (k = pre[j]; k != j; k = pre[k]) {
                        belong[k] = num;
                    }
                    belong[j] = num ++ ;
                }
            }
            sum += inv[i];
        }
        if (num == 0) return sum;
        for (i = 0; i < n; i++){
            if (belong[i] == -1) {
                belong[i] = num ++ ;
            }
        }
        for (i = 0; i < m; i++) { //重新构图
            e[i].w = e[i].w - inv[e[i].v];
            e[i].v = belong[e[i].v];
            e[i].u = belong[e[i].u];
        }
        n = num;
        root = belong[root];
    }
}

int main() {
    int i, j, u, v, w;
    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 0; i < n; i++) {
            scanf("%d%d", &px[i], &py[i]);
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            u--; v--;
            e[i].u = u; e[i].v = v;
            e[i].w = sqrt(SQ(px[u] - px[v]) + SQ(py[u] - py[v]));
        }
        double res = dirtree(n, m, 0);
        if(res < 0) printf("poor snoopy\n");
        else printf("%.2f\n", res);
    }
    return 0;
}
