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

#define Maxn 211111
const LL MOD = 1000000007;

int n;
LL c;
LL dp[Maxn], num[Maxn];
int next[Maxn];
stack<int> sta;
int L[Maxn], len;
int fa[Maxn];
int used[Maxn];

int getfa(int x) {
    if(x == fa[x]) return x;
    else return (fa[x] = getfa(fa[x]));
}

int main() {
    int i, j, k, u, v, w;
    //freopen("in.txt", "r", stdin);
    //freopen("wa.txt", "w", stdout);
    while(scanf("%d%lld", &n, &c) != EOF) {
        memset(next, 0, sizeof(next));
        next[0] = -1;
        next[1] = 0;
        memset(used, 0, sizeof(used));
        for(i = 2; i <= n; i++) scanf("%d", &next[i]);
        //for(i = 0; i <= n; i++) cout << "next " << i << " " << next[i] << endl;
        for(i = 0; i <= n + 1; i++) fa[i] = i;
        for(i = 2; i <= n; i++) {
            if(next[i] == 0) continue;
            fa[i] = getfa(next[i]);
        }
        memset(num, 0, sizeof(num));
        dp[1] = c;
        num[1] = 1;
        //for(i = 0; i <= n; i++) cout << "next " << i << " " << next[i] << endl;
        for(i = 2, j = 0; i <= n; i++) {
            while(!sta.empty()) sta.pop();
            while(j != -1 && next[i] != j + 1) {
                sta.push(j + 1);
                //cout << next[i] << " " << j << " " << next[j] << endl;
                j = next[j];
                //cout << i << " " << j << endl;
            }
            j = next[i];
            len = 0;
            while(!sta.empty()) {
                L[len++] = sta.top();
                sta.pop();
            }
            if(next[i] != 0 || len == 0) {
                dp[i] = dp[i - 1];
            }
            else {
                used[L[0]] = i;
                num[0] = 1;
                for(k = 1; k < len; k++) {
                    if(used[getfa(L[k])] != i) {
                        used[getfa(L[k])] = i;
                        num[k] = num[k - 1] + 1;
                    }
                    else {
                        num[k] = num[k - 1];
                    }
                }
                dp[i] = dp[i - 1] * (c - num[len - 1]) % MOD;
            }
            //cout << "dp " << i << " " << dp[i] << endl << endl;
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
