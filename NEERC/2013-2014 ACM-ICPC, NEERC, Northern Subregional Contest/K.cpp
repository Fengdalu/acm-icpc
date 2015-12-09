#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define PII pair<int, int>
#define OP begin()
#define ED end()

int a, b, c, d;
int v1, v2;
set<PII>s;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void build(int b, int n, int m) {
    if(m % 2 == 0) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m / 2; j++) {
                int v = i + j;
                if(v > n) v -= n;
                printf("%d %d\n", b + i, b + v);
            }
        }
    }
    else {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= (m - 1) / 2; j++) {
                int v = i + j;
                if(v > n) v -= n;
                printf("%d %d\n", i + b, b + v);
            }
        }
        for(int i = 1; i <= n / 2; i++) {
            printf("%d %d\n", i + b, b + i + n / 2);
        }
    }
}

int main() {
    freopen("kids.in", "r", stdin);
    freopen("kids.out", "w", stdout);
    while(cin >> a >> b >> c >> d) {
    int k = 1;
    while(true) {
        if(k * c / gcd(b, c) > a && k * c / gcd(b, c) >= c
           && k * b / gcd(b, c) >= b && k * b / gcd(b, c) > d) {
            v1 = k * c / gcd(b, c);
            v2 = k * b / gcd(b, c);
            if(v1 * a % 2 == 0 && v2 * d % 2 == 0) break;
        }k++;
    }
    printf("%d %d\n", v1, v2);
    build(0, v1, a);
    build(v1, v2, d);
    int t = v1 + 1;
    for(int i = 1; i <= v1; i++) {
        for(int j = 0; j < b; j++) {
            printf("%d %d\n", i, t);
            t++;
            if(t > v1 + v2) t = v1 + 1;
        }
    }
    }
    return 0;
}
