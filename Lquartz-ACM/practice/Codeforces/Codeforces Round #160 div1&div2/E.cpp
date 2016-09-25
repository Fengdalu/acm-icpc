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

LL n, t;
int m;
LL g[100][100];

LL calc(LL n, int dep) {
    //printf("calc %lld %d\n", n, dep);
    if(n <= 0) return 0;
    int i, j, k;
    LL u, v, w;
    LL step = 0, L = 1, sum = 0;
    while(L < n) {
        step ++;
        L <<= 1;
    }
    if(L > n) {
        L >>= 1;
        step--;
    }
    LL ans = 0;
    k = m - dep;
    if(k < 0) return 0;
    ans = g[step][k];
    //printf("step %lld sum %lld ans %lld\n", step, sum, ans);
    return ans + calc(n - L, dep + 1);
}

LL Count(LL n) {
    if(n <= 0) return 0;
    int i, j, k;
    LL u, v, w;
    LL step = 0, L = 1, sum = 0;
    while(sum < n) {
        step++;
        sum += L;
        L <<= 1;
    }
    LL ans = 0;
    if(step == 1) {
        return ans = g[0][m];
    }
    if(sum > n) step--;
    sum = 0;
    for(i = 0, L = 1; i < step; i++) {
        ans += g[i][m];
        sum += L;
        L <<= 1;
    }
    //printf("Count ans %lld\n", ans);
    return ans + calc(n - sum, 0);
}

int main() {
    int i, j, k;
    LL u, v, w;
    while(cin >> n >> t) {
        LL step = 0, L = 1, sum = 0;
        memset(g, 0, sizeof(g));
        g[0][0] = 1;
        for(i = 1; i < 50; i++) {
            for(j = 0; j < i; j++) {
                g[i][j] = g[i - 1][j];
            }
            for(j = 0; j < i; j++) {
                g[i][j + 1] += g[i - 1][j];
            }
        }
        //for(i = 0; i < 10; i++) {
            //for(j = 0; j < 10; j++) printf("%lld ", g[i][j]); 
            //printf("\n");
        //}
        m = -1;
        for(i = 0, w = 1; w <= t; i++, w <<= 1) {
            if(w == t) {
                m = i;
                break;
            }
        }
        //printf("m %d\n", m);
        LL ans = 0;
        if(m == -1) ans = 0; 
        else {
            ans = Count(n + 1);
            if(m == 0) ans --;
        }
        cout << ans << endl;
    }
    return 0;
}
