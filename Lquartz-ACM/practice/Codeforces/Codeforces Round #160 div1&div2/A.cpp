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

int n, k;


int main() {
    int i, j, k, u, v, w;
    while(scanf("%d%d", &n, &k)!= EOF) {
        w = 0;
        for(i = 0; i < n; i++) {
            scanf("%d", &u);
            v = 0;
            while(u) {
                j = u % 10;
                u /= 10;
                if(j == 4 || j == 7) v++;
            }
            if(v <= k) w++;
        }
        printf("%d\n", w);
    }

    return 0;
}
