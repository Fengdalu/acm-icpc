#include <bits/stdc++.h>

using namespace std;
const int M = 500;
int f[M][M];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        f[x1][y1] = f[x2][y2] = i + 1;
        for(int x = x1 + 1; x <= x2; x++) {
            int y = (y2 - y1) * (x - x1);
            if(y % (x2 - x1) != 0) continue;
            y = y / (x2 - x1) + y1;
            f[x][y] = i + 1;
        }
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", f[x][y]);
    }
}
