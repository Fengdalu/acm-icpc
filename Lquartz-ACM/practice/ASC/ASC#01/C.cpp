#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
#define PB push_back
#define MP make_pair
#define BG begin()
#define ED end()
#define SZ size()
#define N 500100
#define M 500100
typedef vector<int> VI;
struct node {
    int v, next;
}E[M];
int tot, last[N];
int n, m;
int dp[N][3];
VI ans;

void addedge(int u, int v) {
    E[tot].v = v; E[tot].next = last[u]; last[u] = tot++;
}

void gao(int u) {
    if(dp[u][2] != -1) return;
//    printf("gao %d\n", u);
    dp[u][2] = 0;
    int j, v, sum0 = 0;
    dp[u][0] = 0;
    for(j = last[u]; j != -1; j = E[j].next) {
        v = E[j].v;
        gao(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        sum0 += max(dp[v][0], dp[v][1]);
    }
    dp[u][1] = 0;
    for(j = last[u]; j != -1; j = E[j].next) {
        v = E[j].v;
        if(dp[u][1] < sum0 - max(dp[v][0], dp[v][1]) + dp[v][0] + 1) {
            dp[u][1] = sum0 - max(dp[v][0], dp[v][1]) + dp[v][0] + 1;
            dp[u][2] = v;
//            printf("gai %d %d %d\n", u, v, dp[u][1]);
        }
    }
}

void getans(int u, int p) {
    if(dp[u][2] == -1) return;
//    printf("getans %d %d\n", u, p);
    int j, v, x, sum0 = 0;
    if(p == 0) {
        for(j = last[u]; j != -1; j = E[j].next) {
            v = E[j].v;
            if(dp[v][0] >= dp[v][1]) getans(v, 0);
            else getans(v, 1);
        }
    }
    else if(p == 1) {
        if(dp[u][2] > 0)
            ans.PB(dp[u][2]);
        x = -1;
        sum0 = 0;
        for(j = last[u]; j != -1; j = E[j].next) {
            v = E[j].v;
            sum0 += max(dp[v][0], dp[v][1]);
        }
        for(j = last[u]; j != -1; j = E[j].next) {
            v = E[j].v;
            if(dp[u][1] == sum0 - max(dp[v][0], dp[v][1]) + dp[v][0] + 1) {
                x = v;
            }
        }
        for(j = last[u]; j != -1; j = E[j].next) {
            v = E[j].v;
            if(v != x) {
                if(dp[v][0] >= dp[v][1]) getans(v, 0);
                else getans(v, 1);
            }
            else getans(v, 0);
        }
    }
}

int main() {
//    cout << sizeof(E) + sizeof(last) * 3 << endl;
    int i, j;
    int T;
    scanf("%d", &T);
    for(int Ca = 1; Ca <= T; Ca++) {
        scanf("%d", &n);
        for(i = 0; i <= n; i++) {
            dp[i][0] = dp[i][1] = dp[i][2] = -1;
            last[i] = -1;
        }
        tot = 0;
        for(i = 2; i <= n; i++) {
            scanf("%d", &j);
            addedge(j, i);
        }
        gao(1);
//        for(i = 0; i <= n; i++) { printf("dp[%d] 0: %d 1: %d 2: %d\n", i, dp[i][0], dp[i][1], dp[i][2]);}
        int temp = dp[1][0], pp = 0;
        if(dp[1][1] > temp) {
            temp = dp[1][1], pp = 1;
        }
        if(Ca > 1) cout << endl;
        cout << temp * 1000 << endl;
        ans.clear();
        getans(1, pp);
        sort(ans.BG, ans.ED);
        for(i = 0; i < ans.SZ; i++) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}

/*
10

4
1 1 2

8
1 1 1 2 3 3 4

8
1 1 1 2 3 4 6

9
1 1 1 2 3 3 4 6

5
1 2 3 4

9
1 1 1 2 3 4 6 7
*/
