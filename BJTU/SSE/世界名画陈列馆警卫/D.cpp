#include <bits/stdc++.h>
#define cmin(x, y) x = std::min(x, y)
const int Maxm = 1000;
const int Maxn = 1000;

int ans;
struct DLX{
    struct Node{
        Node *L, *R, *U, *D;
        int col, row;
    } *head, *row[Maxn], *col[Maxm], node[Maxn * Maxm];
    int colsum[Maxm], cnt;
    /* dancing link
     * 重复覆盖问题
     * 可以添加迭代加深优化：
     * 1)  枚举深度 h ；
     * 2) 若当前深度 +predeep > h return false
     * , 继续搜索 deep + predeep + 1 <= h
     *
     */
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
            return ;
        }
        if(deep + predeep() > ans) return ;
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
            int sta = 0;
            dfs(deep + 1);
            for(r = p->L; r != p; r = r->L) {
                if(r->col != 0) resume(r);
            }
            resume(p);
        }
        return ;
    }
} dlx;
int mat[Maxn][Maxm];
int cnt;
int n, m;
void add(int x, int y) {
    cnt++;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++) if(abs(i) + abs(j) < 2) {
            int tx = x + i, ty = y + j;
            if(tx >= 0 && tx < n)
                if(ty >= 0 && ty < m) {
                    mat[cnt][tx * m + ty + 1] = 1;
                }
        }
}


int doit(int nn, int mm, int bound=n*m) {
    n = nn; m = mm;
    memset(mat, 0, sizeof mat);
    cnt = 0;
    ans = bound;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            add(i, j);
    dlx.init(mat, cnt, n * m);
    dlx.dfs(0);
    return ans;
}


const int MX = 20;
int ANS [MX+5][MX+5];
const int limit[20][20] = {{1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7},{1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11},{1,2,4,4,6,6,7,9,9,11,11,12,14,14,16,16,17,19,19,21},{2,3,4,4,7,8,9,10,10,13,14,15,16,16,19,20,21,22,22,25},{2,3,6,7,9,10,11,13,14,16,17,18,20,21,23,24,25,27,28,30},{2,4,6,8,10,12,13,14,16,18,20,21,22,24,26,28,29,30,32,34},{3,4,7,9,11,13,15,16,18,20,22,24,25,27,29,31,33,34,36,38},{3,5,9,10,13,14,16,19,20,23,24,26,29,30,33,34,36,39,40,43},{3,5,9,10,14,16,18,20,21,25,27,29,31,32,36,38,40,42,43,47},{4,6,11,13,16,18,20,23,25,28,30,32,35,37,40,42,44,47,49,52},{4,6,11,14,17,20,22,24,27,30,33,35,37,40,43,46,48,50,53,56},{4,7,12,15,18,21,24,26,29,32,35,38,40,43,46,49,52,54,57,60},{5,7,14,16,20,22,25,29,31,35,37,40,44,46,50,52,55,59,61,65},{5,8,14,16,21,24,27,30,32,37,40,43,46,48,53,56,59,62,64,69},{5,8,16,19,23,26,29,33,36,40,43,46,50,53,57,60,63,67,70,74},{6,9,16,20,24,28,31,34,38,42,46,49,52,56,60,64,67,70,74,78},{6,9,17,21,25,29,33,36,40,44,48,52,55,59,63,67,71,74,78,82},{6,10,19,22,27,30,34,39,42,47,50,54,59,62,67,70,74,79,82,87},{7,10,19,22,28,32,36,40,43,49,53,57,61,64,70,74,78,82,85,91},{7,11,21,25,30,34,38,43,47,52,56,60,65,69,74,78,82,87,91,96}};
int main(int argc, char **argv) {
    assert(argc == 3);
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "a", stdout);
    while(~scanf("%d%d", &n, &m)) {
        printf("[%d, %d]: %d\n", n, m, doit(n, m, limit[n - 1][m - 1]));
        fflush(stdout);
    }
    fclose(stdout);
    return 0;
}
