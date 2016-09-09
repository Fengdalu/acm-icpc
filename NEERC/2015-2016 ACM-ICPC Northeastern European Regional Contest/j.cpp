#include <bits/stdc++.h>

const int N = 2000;
int a[N];
int b[N];
inline void solve() {
    srand(4);
    int n;
    scanf("%d", &n);
    while(true) {
        for(int i = 0; i < n; i++)  {
            a[i] = rand() & 1;
        }
        for(int i = 0; i < n; i++) printf("%d", a[i]); printf("\n"); fflush(stdout);
        int tmp = 0;
        scanf("%d", &tmp);
        if(tmp == n) {
            return;
        }
        if(tmp == n / 2) break;
    }
    for(int i = 1; i < n; i++) {
        a[0] ^= 1; a[i] ^= 1;
        for(int i = 0; i < n; i++) printf("%d", a[i]); printf("\n"); fflush(stdout);
        int tmp = 0;
        scanf("%d", &tmp);
        if(tmp == n) {
            return;
        }
        if(tmp) b[i] = 1; else b[i] = 0;
        a[0] ^= 1; a[i] ^= 1;
    }
    for(int i = 1; i < n; i++) a[i] = a[i] ^ b[i];
    for(int i = 0; i < n; i++) printf("%d", a[i]); printf("\n"); fflush(stdout);
    int tmp = 0;
    scanf("%d", &tmp);
    if(tmp) {
        return;
    }
    else {
        for(int i = 0; i < n; i++) printf("%d", a[i] ^ 1); printf("\n"); fflush(stdout);
        scanf("%d", &tmp);
    }
}


int main() {
    solve();
    return 0;
}
