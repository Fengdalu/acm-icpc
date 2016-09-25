#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;
set <int> S, SS;
void _n3(int x, int g[]) {
    for(int i = 0; i < 11; i++) {
        int j = x % 2;
        g[i] = j;
        x /= 2;
    }
}
int _3n(int g[]) {
    int ret = 0;
    for(int i = 11 - 1; i >= 0; i--) {
        ret = (ret * 2) + g[i];
    }
    return ret;
}

void pre() {
    S.clear();
    for(int i = 0; i < (1<<11); i++) {
        S.insert(i);
    }
}

void out(int x) {
    int g[17];
    _n3(x, g);
    for(int i = 0; i < 11; i++) {
        if(g[i] == 0) {
            printf("bad ");
        }
        else if(g[i] == 1) {
            printf("good ");
        }
    }
    printf("\n");
}

void del(int cnt) {
    SS.clear();
    int a[17], b[17];
    _n3(*(S.begin()), a);
    for(set <int>::iterator it = S.begin(); it != S.end(); it++) {
        int n = *it;
        _n3(n, b);
        int t = 0;
        for(int i = 0; i < 11; i++) if(a[i] == b[i]) t++;
        if(t == cnt) SS.insert(n);
    }
    S = SS;
}

int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    pre();
    while(1) {
        printf("size: %d\n", S.size());
        out(*S.begin());
        scanf("%d", &i);
        del(i);
    }
    return 0;
}
