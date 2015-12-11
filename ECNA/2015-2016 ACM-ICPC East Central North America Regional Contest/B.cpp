#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
const int Maxn = 300;
int X[Maxn], Y[Maxn];
int cntx, cnty;
int n, m;
int r, c;
PII st[Maxn];
int s1[Maxn][Maxn];


int main() {
    scanf("%d%d%d%d", &r, &c, &n, &m);
    for(int i = 0; i < n; i++) scanf("%d%d", &st[i].AA, &st[i].BB);
    for(int i = n; i < n + m; i++) scanf("%d%d", &st[i].AA, &st[i].BB);

    cntx = cnty = 0;
    for(int i = 0; i < n + m; i++) {
        X[cntx++] = st[i].AA;
        X[cntx++] = st[i].AA + 9;
        Y[cnty++] = st[i].BB;
        Y[cnty++] = st[i].BB + 15;
    }
    sort(X, X + cntx);
    cntx = unique(X, X + cntx) - X;
    sort(Y, Y + cnty);
    cnty = unique(Y, Y + cnty) - Y;
    return 0;
}
