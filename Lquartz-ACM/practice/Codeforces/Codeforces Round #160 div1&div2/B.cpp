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

#define Maxn 101000
int g[Maxn];
vector<int> g1, g2;
int n, k;
int sum;

int main() {
    int i, j, u, v, w;
    while(scanf("%d%d", &n, &k) != EOF) {
        g1.clear();
        g2.clear();
        sum = 0;
        for(i = 0; i < n; i++) {
            scanf("%d", &w);
            if(w < 0) g1.PB(w);
            else g2.PB(w);
        }
        sort(g1.BG, g1.ED);
        sort(g2.BG, g2.ED);
        for(i = 0; i < g1.SZ && k > 0; i++, k--) {
            g1[i] *= -1;
        }
        w = Maxn;
        for(i = 0; i < g1.SZ; i++) sum += g1[i];
        for(i = 0; i < g2.SZ; i++) sum += g2[i]; 
        if(k > 0) {
            if(g1.SZ > 0) w = g1[g1.SZ - 1];
            if(g2.SZ > 0) w = min(w, g2[0]);
            sum -= w;
            while(k) {
               w *= -1; k--;
            }
           sum += w;
        }
       printf("%d\n", sum); 
    }

    return 0;
}
