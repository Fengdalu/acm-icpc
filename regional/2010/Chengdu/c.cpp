#include <iostream>
#include <cstdio>
#include <iostream>
using namespace std;
#define ONES(x) __builtin_popcount(x)

const int N = 10000;
int a[N], b[N];

inline int cal(int a, int b) {
    return ONES(a ^ b);
}

inline void run() {
    int n, m;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    for(int i = 0; i < n; i++) {
        int x = b[i];
        int y = 0;
        for(int j = 0; j < m; j++) {
            int g = cal(x, a[j]);
            if(g < cal(x, a[y]) || (g == cal(x, a[y]) && a[j] < a[y]))  y = j;
        }
        printf("%d\n", a[y]);
    }
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) run();
    return 0;
}
