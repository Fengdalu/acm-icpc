#include <bits/stdc++.h>
using namespace std;

template <class T>
T gcd(T a, T b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

inline void run() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int t = gcd(a, b);
    int tot = (n / t) - (a % t == 0) - (b % t == 0);
    if(tot % 2 == 0)
        puts("Iaka");
    else puts("Yuwgna");
}

int main() {
    int _T;
    scanf("%d", &_T);
    int cas = 0;
    while(_T--) {
        printf("Case #%d: ", ++cas);
        run();
    }
    return 1;
}
