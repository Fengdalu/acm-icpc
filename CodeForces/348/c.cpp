#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
const int maxm =10010;
int f[110][110];
int op[maxm], x[maxm], y[maxm], v[maxm];
int buf[maxm];

int main() {
    int q;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 0; i < q; i++) {
        scanf("%d", &op[i]);
        if(op[i] <= 2) scanf("%d", &x[i]);
        else scanf("%d%d%d", &x[i], &y[i], &v[i]);
    }
    for(int k = q - 1; k > -1; k--) {
        x[k]--;
        y[k]--;
        if(op[k] == 3) f[x[k]][y[k]] = v[k];
        else if(op[k] == 1) {
            int last = f[x[k]][m - 1];
            for(int i = m; i > 0; i--) f[x[k]][i] = f[x[k]][i - 1];
            f[x[k]][0] = last;
        }
        else if(op[k] == 2) {
            int last = f[n - 1][x[k]];
            for(int i = n; i > 0; i--) f[i][x[k]] = f[i - 1][x[k]];
            f[0][x[k]] = last;
        }
    }
    for(int i = 0; i < n; i++) {
         for(int j = 0; j < m; j++)
             printf("%d ", f[i][j]);
        printf("\n");
    }
}
