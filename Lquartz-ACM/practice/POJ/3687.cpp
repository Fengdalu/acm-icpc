#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define Maxn 205
#define Maxm 41000
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define ED end()
int n, m;
struct node {
    int u, v, next;
}e[Maxm];
int tot, last[Maxn];
priority_queue<int > Q;
vector<int> ans, out;
int deg[Maxn];

void adde(int u, int v) {
    e[tot].u = u; e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
}

int main() {
    int i, j, u, v, te;
    scanf("%d", &te);
    while(te--) {
        scanf("%d%d", &n, &m);
        tot = 0;
        for(i = 1; i <= n; i++) {
            last[i] = -1;
            deg[i] = 0;
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            adde(v, u);
            deg[u]++;
        }
        while(!Q.empty()) Q.pop();
        for(i = 1; i <= n; i++) {
            if(deg[i] == 0) Q.push(i);
        }
        ans.clear();
        out.clear();
        while(!Q.empty()) {
            u = Q.top();
            Q.pop();
            ans.PB(u);
            for(j = last[u]; j != -1; j = e[j].next) {
                v = e[j].v;
                deg[v]--;
                if(deg[v] == 0) Q.push(v);
            }
        }
        if(ans.SZ < n) {
            printf("-1\n");
        }
        else {
            reverse(ans.BG, ans.ED);
            out = ans;
            for(i = 0; i < n; i++) {
                out[ans[i] - 1] = i + 1;
            }
            for(i = 0; i < n; i++) {
                if(i) printf(" ");
                printf("%d", out[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

/*
2

5 4
5 1
4 2
1 3
2 3

10 5
4 1
8 1
7 8
4 1
2 8
ans:
2 4 5 3 1        逆向建图
5 1 6 2 7 8 3 4 9 10  没有判重边的话就输出 -1

*/
