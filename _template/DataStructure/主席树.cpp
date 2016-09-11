#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>

typedef std::pair<int, int> PII;
#define PB(x) push_back(x)
#define SZ size()
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
namespace ST {
    /*
     * e: 线段树节点数组
     *    l, r: 左右节点指针
     *    sum: 区间和
     * rt: 主席树根节点
     * tot: 总节点个数
     */
    struct E {
        int l, r;
        int sum;
    }e[10000000];
    int rt[100010];
    int tot;

    /*
     * 建树，初始化调用，建立一颗空树
     */
    void build(int &rt, int l, int r) {
        rt = tot++;
        e[rt].sum = 0;
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(e[rt].l, l, mid);
        build(e[rt].r, mid + 1, r);
    }

    /*
     * 插入新节点，向$w$位置插入节点，主席书中父亲结点为$fa$
     */
    void update(int &rt, int l, int r, int w, int fa) {
        rt = tot++;
        e[rt].l = e[fa].l;
        e[rt].r = e[fa].r;
        e[rt].sum = e[fa].sum + 1;
        if(l == r) return ;
        int mid = (l + r) >> 1;
        if(w <= mid) update(e[rt].l, l, mid, w, e[fa].l);
        else update(e[rt].r, mid + 1, r, w, e[fa].r);
    }

    /*
     * 查询，查询原图中$(a, b)$点对的信息，其中$c = lca(a, b)$
     * 计算时候加入$c$信息
     */
    int query(int a, int b, int c, int l, int r, int k, int nd) {
        int mid = (l + r) >> 1;
        int sum = e[e[a].l].sum + e[e[b].l].sum - e[e[c].l].sum * 2 + (int)(nd <= mid);
        if(l == r) return l;
        if(k <= sum) return query(e[a].l, e[b].l, e[c].l, l, mid, k, nd);
        else return query(e[a].r, e[b].r, e[c].r, mid + 1, r, k - sum, (nd <= mid ? 1e9 : nd));
    }
};
