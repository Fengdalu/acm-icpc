#include <bits/stdc++.h>

int ask(int i, int j) {
    static int T;
    printf("? %d %d\n", i, j);
    fflush(stdout);
    scanf("%d", &T);
    return T;
}

int a[5010];
int main() {
    int n; scanf("%d", &n);
    int x = ask(1, 2);
    int y = ask(2, 3);
    int z = ask(1, 3);
    a[1] = x - (y - z + x) / 2;
    a[2] = (y - z + x) / 2;
    a[3] = y - (y - z + x) / 2;
    for(int i = 4; i <= n; i++) {
        a[i] = ask(1, i) - a[1];
    }
    printf("!");
    for(int i = 1; i <= n; i++) printf(" %d", a[i]);
    return 0;
}
