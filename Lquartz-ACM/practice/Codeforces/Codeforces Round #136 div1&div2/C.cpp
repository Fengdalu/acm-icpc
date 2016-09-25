//#include <bits/stdc++.h>
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
#define Maxn 101111
int g[Maxn], f[Maxn];
int n;

int main() {
    int i, j, k, u, v, w;
    while(cin >> n) {
        //cin >> n;
        for(i = 0; i < n; i++) {
            cin >> g[i];
            f[i] = g[i];
        }
        sort(f, f + n);
        w = 0;
        for(i = 0; i < n; i++) if(f[i] != g[i]) w++;
        if(w > 2) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }

    return 0;
}
