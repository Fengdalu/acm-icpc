#include <bits/stdc++.h>

using namespace std;

const int N = 200;
const double eps = 0.0;
double d[N][N], d1[N][N], d2[N][N];
double mx[N], v[N];

void update(double &a, double b) {
    if(a < 0) a = b;
    a = min(a, b);
}

void run() {
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%lf%lf", mx + i, v + i);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            scanf("%lf", &d[i][j]);
            d1[i][j] = d[i][j];
        }

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(d1[i][k] > 0 && d1[k][j] > 0)
                    update(d1[i][j], d1[i][k] + d1[k][j]);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if(d1[i][j] > 0 && (mx[i] - d1[i][j]) >= eps) d2[i][j] = d1[i][j] / v[i];
            else d2[i][j] = -1;
    }

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(d2[i][k] > 0 && d2[k][j] > 0)
                    update(d2[i][j], d2[i][k] + d2[k][j]);

    /*
    for(int i = 0; i < n; i++) {
        printf("%.2f:\t", mx[i]);
        for(int j = 0; j < n; j++)
            printf("%.2f\t", d1[i][j]);
        puts("");
    }
    */
    for(int i = 0; i < q; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        printf(" %.15f", d2[u][v]);
    }
    puts("");
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int ii = 0; ii < T; ii++) {
        printf("Case #%d:", ii + 1);
        run();
    }
    return 0;
}
