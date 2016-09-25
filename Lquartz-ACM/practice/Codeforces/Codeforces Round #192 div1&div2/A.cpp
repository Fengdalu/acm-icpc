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

#define NAME ""

#define Maxn 20
char str[Maxn][Maxn];
int used[Maxn][Maxn];
int n, m;

int check(int x, int y) {
    if(str[x][y] == 'S') return 0;
    int flag = 1;
    int i, j;
    for(i = 0; i < n; i++) {
        if(str[i][y] == 'S') {
            flag = 0;
        }
    }
    if(flag) return 1;
    flag = 1;
    for(j = 0; j < m; j++) {
        if(str[x][j] == 'S') {
            flag = 0;
        }
    }
    return flag;
}

int main() {
    int i, j, k, u, v, w;

    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 0; i < n; i++) {
            scanf("%s", str[i]);
        }
        memset(used, 0, sizeof(used));
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(check(i, j)) used[i][j] = 1;
            }
        }
        int ans = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                ans += used[i][j];
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
