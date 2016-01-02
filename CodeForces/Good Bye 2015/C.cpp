#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define LL long long
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()

int f1[600][600], f2[600][600];
int n, m;
char s[600][600];

int sub1(int x, int y, int a, int b) {
    return f1[x][y] - f1[x][b - 1] - f1[a - 1][y] + f1[a - 1][b - 1];
}

int sub2(int x, int y, int a, int b) {
    return f2[x][y] - f2[x][b - 1] - f2[a - 1][y] + f2[a - 1][b - 1];
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        if(s[i][j - 1] == '.' && s[i][j] == '.') f1[i][j]++;
        if(s[i - 1][j] == '.' && s[i][j] == '.') f2[i][j]++;
        f1[i][j] += f1[i - 1][j];
        f1[i][j] += f1[i][j - 1];
        f1[i][j] -= f1[i - 1][j - 1];

        f2[i][j] += f2[i - 1][j];
        f2[i][j] += f2[i][j - 1];
        f2[i][j] -= f2[i - 1][j - 1];
    }

    int Q; scanf("%d", &Q);
    while(Q--) {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        printf("%d\n", sub1(r2, c2, r1, c1 + 1) + sub2(r2, c2, r1 + 1, c1));
    }
    return 0;
}
