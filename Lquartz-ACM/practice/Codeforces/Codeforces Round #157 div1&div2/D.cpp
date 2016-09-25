#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define LEN 13

LL dp1[LEN][LEN];
map<PII, LL> dp2;
map<PII, LL>::iterator IT;
LL e[30];
const LL MOD = 1000000007LL;
LL dp3[10][10][10][10][10][10];
int n;
int a[100];

LL dfs1(int L, int b) {
    LL &tp = dp1[L][b];
    if(tp != -1) return tp;
    if(b > 0) dfs1(L, b - 1);
    tp = 8 * dfs1(L - 1, b);
    if(b > 0) tp += 2 * dfs1(L - 1, b - 1);
    return tp; 
}
LL dfs2(int n, int L, int b, int dep) {
    //printf("dfs2 n %d L %d b %d dep %d\n", n, L, b, dep);
    int start = (dep == 0 ? 0 : 0);
    int i, j, k;
    IT = dp2.find(MP(n, b));
    if(IT != dp2.ED) {
        //printf("It %lld\n", (*IT).BB);
        return (*IT).BB;
    } 
    if(L == 1) {
        j = 0; k = 0;
        for(i = start; i <= n; i++) {
            if(i == 4 || i == 7) k++;
            else j++;
        }
        if(b == 0) {
            dp2[MP(n, b)] = j;
            //printf("b0 %d\n", j);
            return j;
        }
        else if(b == 1) {
            dp2[MP(n, b)] = k;
            //printf("b1 %d\n", k);
            return k;
        }
        else {
            dp2[MP(n, b)] = 0;
            //printf("bx %d\n", 0);
            return 0;
        }
    }
    LL tp = 0;
    int key = n / e[L - 1] % 10;
    for(i = start; i < key; i++) {
        if(i == 4 || i == 7) {
            if(b > 0)
            tp += dp1[L - 1][b - 1];
        }
        else {
            tp += dp1[L - 1][b];
        }
    }
    //printf("key %d %d %d\n", n, b, key);
    //printf("first %d %d %lld\n", n, b, tp);
    if((key == 4 || key == 7)) {
        if(b > 0)
        tp += dfs2(n - key * e[L - 1], L - 1, b - 1, dep + 1);
    }
    else {
        tp += dfs2(n - key * e[L - 1], L - 1, b, dep + 1);
    }
    //printf("second %d %d %lld\n", n, b, tp);
    dp2[MP(n, b)] = tp;
    //printf("dfs2 %d %d %lld\n", n, b, tp);
    return tp;
}
int b[100];
LL calc() {
    int i, j, k, u, v, w;
    LL ret = 1, x, y, z;
    //printf("calc ");
    for(i = 0; i < 6; i++) b[i] = a[i];
    sort(b, b + 6);
    //for(i = 0; i < 6; i++) printf("%d ", a[i]); printf("\n");
    for(i = 0; i < 6; ) {
        for(j = i, k = 0; j < 6 && b[j] == b[i]; j++, k++);
        x = dp2[MP(n, b[i])];
        if(x < k) return 0;
        while(k) {
            ret = (ret * x) % MOD;
            x--;
            k--;
        }
        i = j;
    }
    //printf("calc %lld\n", ret);
    return ret;
}
LL dfs3(int dep, int have) {
    //printf("dfs3 %d %d\n", dep, have);
    if(dep == 6) {
        LL & tp = dp3[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]];
        if(have == 0) {
            tp = 0;
            return tp;
        }
        if(tp != -1) return tp;
        LL ret = calc() % MOD;
        tp = ret;
        return ret;
    }
    int i, j;
    LL ret = 0;
    for(i = have; i >= 0; i--) {
        a[dep] = i;
        ret = (ret + dfs3(dep + 1, have - i)) % MOD;
    }
    return ret % MOD;
}

int main() {
    int i, j, k, u, v, w;
    e[0] = 1;
    for(i = 1; i < 15; i++) e[i] = e[i - 1] * 10;
    while(cin >> n) {
        memset(dp1, -1, sizeof(dp1));
        for(i = 0; i < LEN; i++) dp1[1][i] = 0;
        dp1[1][0] = 8;
        dp1[1][1] = 2;
        dfs1(12, 12);
        for(i = 0; i < 5; i++) {
            //for(j = 0; j < 5; j++) printf("%11lld ", dp1[i][j]);
            //printf("\n");
        }
        k = 0;
        w = n;
        while(w) {
            w /= 10;
            k++;
        }
        dp2.clear();
        for(i = 0; i <= k; i++) {
            dfs2(n, k, i, 0);
            if(i == 0) dp2[MP(n, i)]--;
            //printf("%d %d %lld\n", n, i, dp2[MP(n, i)]);
        }
        ///*
        memset(dp3, -1, sizeof(dp3));
        LL ans = 0;
        for(i = k; i > 0; i--) {
            memset(dp3, -1, sizeof(dp3));
            LL tp = dfs3(0, i);
            //printf("tp %lld dp2 %lld\n", tp, dp2[MP(n, i)]);
            ans = (ans + dp2[MP(n, i)] * tp % MOD) % MOD;
            //printf("ans %lld\n", ans);
        }
        cout << ans << endl;
        //*/

    }

    return 0;
}

/*

879893164
*/


