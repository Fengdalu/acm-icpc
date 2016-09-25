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

#define Maxn 111111
int n, q;
vector<int> c;
vector<int> need;
int ans;

int main() {
    int i, j, k, u, v, w;
    while(scanf("%d", &n) != EOF) {
        c.clear();
        for(i = 0; i < n; i++) {
            scanf("%d", &w);
            c.PB(w);
        }
        scanf("%d", &q);
        need.clear();
        for(i = 0; i < q; i++) {
            scanf("%d", &w);
            need.PB(w);
        }
        sort(c.BG, c.ED);
        sort(need.BG, need.ED);
        ans = 0;
        for(i = q - 1; i >= 0; ) {
            for(j = 0; j < c[0] && i >= 0; j++, i--) {
                ans += need[i];
            }
            for(j = 0; j < 2 && i >= 0; j++, i--);
        }
        printf("%d\n", ans);
    }

    return 0;
}
