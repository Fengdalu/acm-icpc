#include <bits/stdc++.h>
#define cmin(x, y) x = std::min(x, y)
const int Maxm = 58;
const int Maxn = 58;
int ans = 0;
struct DLX{
    struct Node{
        Node *L, *R, *U, *D;
        int col, row;
    } *head, *row[Maxn], *col[Maxm], node[Maxn * Maxm];
    int colsum[Maxm], cnt;
    /* dancing link
     * 重复覆盖问题
     * 可以添加迭代加深优化：
     * 1) 枚举深度h；
     * 2) 若当前深度+predeep > h return false
     * , 继续搜索 deep + predeep + 1 <= h
     *
     */
    ///*
    int predeep(){
        bool vis[Maxm];
        Node * p, *q, *r;
        memset(vis, 0, sizeof(vis));
        int ret = 0;
        for(p = head->R; p != head; p = p->R) {
            if(!vis[p->col]) {
                ret++;
                vis[p->col]++;
                for(q = p->D; q != p; q = q->D) {
                    for(r = q->R; r != q; r = r->R) {
                        vis[r->col] = true;
                    }
                }
            }
        }
        return ret;
    }
    //*/
    void init(int mat[][Maxm], int n, int m) {
        cnt = 0;
        int i, j;
        Node * p;
        memset(colsum, 0, sizeof(colsum));
        head = &node[cnt++];
        for(i = 1; i <= n; i++) row[i] = &node[cnt++];
        for(j = 1; j <= m; j++) col[j] = &node[cnt++];
        head->D = row[1], row[1]->U = head;
        head->R = col[1], col[1]->L = head;
        head->U = row[n], row[n]->D = head;
        head->L = col[m], col[m]->R = head;
        head->row = head->col = 0;
        for(i = 1; i <= n; i++) {
            if(i != n) row[i]->D = row[i + 1];
            if(i != 1) row[i]->U = row[i - 1];
            row[i]->L = row[i]->R = row[i];
            row[i]->row = i; row[i]->col = 0;
        }
        for(i = 1; i <= m; i++) {
            if(i != m) col[i]->R = col[i + 1];
            if(i != 1) col[i]->L = col[i - 1];
            col[i]->U = col[i]->D = col[i];
            col[i]->col = i; col[i]->row = 0;
        }
        for(i = n; i > 0; i--) {
            for(j = m; j > 0; j--) {
                if(mat[i][j]) {
                    p = &node[cnt++];
                    p->R = row[i]->R, row[i]->R->L = p;
                    p->L = row[i], row[i]->R = p;
                    p->D = col[j]->D, col[j]->D->U = p;
                    p->U = col[j], col[j]->D = p;
                    p->row = i;
                    p->col = j;
                    colsum[j]++;
                }
            }
        }
    }
    void remove(Node *c) {
        Node * p;
        for(p = c->D; row[p->row] != row[c->row]; p = p->D) {
            p->R->L = p->L; p->L->R = p->R;
        }
    }
    void resume(Node *c) {
        Node * p;
        for(p = c->U; row[p->row] != row[c->row]; p = p->U) {
            p->L->R = p->R->L = p;
        }
    }

    void dfs(int deep) {
        if(head->R == head) {
            cmin(ans, deep);
            return;
        }
        Node *p, *q = head->R, *r;
        for(p = head->R; p != head; p = p->R) {
            if(colsum[p->col] < colsum[q->col]) q = p;
        }
        for(p = q->D; p != q; p = p->D) {
            remove(p);
            for(r = p->R; r != p; r = r->R) {
                if(r->col != 0) remove(r);
            }
            /*--------可修改区域-----------*/
    //       ans[deep] = p->row;
            /*-----------------------------*/
            if(deep + predeep() + 1 < ans) dfs(deep + 1);
            // if(sta) return sta;
            for(r = p->L; r != p; r = r->L) {
                if(r->col != 0) resume(r);
            }
            resume(p);
        }
        return;
    }
} dlx;
int mat[Maxn][Maxn];

int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        memset(mat, 0, sizeof mat);
        for(int i = 1; i <= n; i++) mat[i][i] = 1;
        ans = n;
        while(m--){
            int x, y; scanf("%d%d", &x, &y);
            mat[x][y] = mat[y][x] = 1;
        }
        dlx.init(mat, n, n);
        dlx.dfs(0);
        printf("%d\n", ans);
    }
}
