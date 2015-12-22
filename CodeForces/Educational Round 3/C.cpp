#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define LL long long
#define ONES(x) __builtin_popcount(x)

LL sum;
LL a[100100];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++) sum += a[i];

    int c1, c2, v1, v2;
    if(sum % n == 0) {
        c1 = n; v1 = sum / n; c2 = 0;
    }
    else {
        c2 = sum % n;
        c1 = n - c2;
        v1 = sum / n;
        v2 = sum / n + 1;
    }
    LL ans = 0;
    for(int i = 0; i < n; i++) {
        if(c1) {
            ans += abs(a[i] - v1); c1--;
        } else {
            ans += abs(a[i] - v2); c2--;
        }
    }

    printf("%I64d\n", ans / 2);
}
