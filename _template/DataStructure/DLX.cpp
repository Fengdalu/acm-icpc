#include <iostream>
#include <cstdio>
#include <cstring>

const int Maxm = 1000;
const int Maxn = 1200;
int ans[Maxn];
struct DLX{
    struct Node{
        Node *L, *R, *U, *D;
        int col, row;
    } *head, *row[Maxn], *col[Maxm], node[Maxn * Maxm];
    int colsum[Maxm], cnt;

    /* dancing link
     * 精确覆盖问题
     * 可以添加迭代加深优化：
     * 1）枚举深度 h
     * 2）若当前深度 +predeep > h return false；
     * 3) mat 下标 1 开始
     */
    /*
       int predeep() {
       bool vis[Maxm];
       memset(vis, 0, sizeof(vis));
       int ret = 0;
       for (Node *p = head->R; p != head; p = p->R)
       if (!vis[p->col]) {
       ret ++ ;
       vis[p->col] ++ ;
       for (Node *q = p->D; q != p; q = p->D)
       for (Node *r = q->R; r != q; r = r->R)
       vis[r->col] = true;
       }
       return ret;
       }
       */
    void init(int mat[][Maxm], int n, int m) {
        cnt = 0;
        memset(colsum, 0, sizeof (colsum) );
        head = &node[cnt ++ ];
        for(int i = 1; i <= n; i ++ )
            row[i] = &node[cnt ++ ];
        for(int j = 1; j <= m; j ++ )
            col[j] = &node[cnt ++ ];
        head->D = row[1], row[1]->U = head;
        head->R = col[1], col[1]->L = head;
        head->U = row[n], row[n]->D = head;
        head->L = col[m], col[m]->R = head;
        head->row = head->col = 0;
        for(int i = 1; i <= n; i ++ ) {
            if (i != n) row[i]->D = row[i + 1];
            if (i != 1) row[i]->U = row[i - 1];
            row[i]->L = row[i]->R = row[i];
            row[i]->row = i, row[i]->col = 0;
        }
        for(int i = 1; i <= m; i ++ ) {
            if (i != m) col[i]->R = col[i + 1];
            if (i != 1) col[i]->L = col[i - 1];
            col[i]->U = col[i]->D = col[i];
            col[i]->col = i, col[i]->row = 0;
        }
        for(int i = n; i > 0; i -- )
            for(int j = m; j > 0; j -- )
                if(mat[i][j]) {
                    Node *p = &node[cnt ++ ];
                    p->R = row[i]->R, row[i]->R->L = p;
                    p->L = row[i], row[i]->R = p;
                    p->D = col[j]->D, col[j]->D->U = p;
                    p->U = col[j], col[j]->D = p;
                    p->row = i;
                    p->col = j;
                    colsum[j] ++ ;
                }
    }
    void remove(Node *c) {
        c->L->R = c->R;
        c->R->L = c->L;
        for(Node *p = c->D; p != c; p = p->D) {
            for(Node *q = p->R; q != p; q = q->R) {
                q->U->D = q->D;
                q->D->U = q->U;
                colsum[q->col] -- ;
            }
        }
    }
    void resume(Node *c) {
        for(Node *p = c->U; p != c; p = p->U) {
            for(Node *q = p->L; q != p; q = q->L) {
                q->U->D = q;
                q->D->U = q;
                colsum[q->col] ++ ;
            }
        }
        col[c->col]->L->R = col[c->col];
        col[c->col]->R->L = col[c->col];
    }
    int dfs(int deep) {
        if(head->R == head) return deep;
        Node *p, *q = head->R;
        for(p = head->R; p != head; p = p->R)
            if(colsum[p->col] < colsum[q->col])
                q = p;
        remove(q);
        for(p = q->D; p != q; p = p->D) {
            for(Node* r = p->R; r != p; r = r->R)
                if (r->col != 0)
                    remove (col[r->col]);
            /*--------可修改区域-----------*/
            ans[deep] = p->row;
            /*-----------------------------*/
            int sta = dfs (deep + 1);
            if(sta) return sta;
            for(Node* r = p->L; r != p; r = r->L)
                if(r->col != 0)
                    resume (col[r->col]);
        }
        resume(q);
        return false;
    }
} dlx;
int mat[Maxn][Maxm];
int mem[Maxn][3];   // 记录每行代表哪一格填几
// col = 324
int n;
// 数独填充 (x, y) = v
void addline(int x, int y, int v) {
    int i, j;
    n++;
    mem[n][0] = x;
    mem[n][1] = y;
    mem[n][2] = v;
    for(i = 0; i < Maxm; i++) mat[n][i] = 0;
    mat[n][x * 9 + y + 1] = 1;
    mat[n][81 + x * 9 + v] = 1;
    mat[n][162 + y * 9 + v] = 1;
    mat[n][243 + (3 * (x / 3) + y / 3) * 9 + v] = 1;
}
