#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define SZ size()
#define OP begin()
#define ED end()
#define LL long long

int main() {
    int a, b, c, x, y, z;
    scanf("%d%d%d", &a, &b, &c);
    scanf("%d%d%d", &x, &y, &z);
    if(a >= x && b >= y && c >= z) { puts("Yes"); }
    else {
        int tot = 0;
        tot += max(0, a - x) / 2;
        tot += max(0, b - y) / 2;
        tot += max(0, c - z) / 2;

        tot -= max(0, x - a);
        tot -= max(0, y - b);
        tot -= max(0, z - c);
        if(tot >= 0 ) puts("Yes");
        else puts("No");
    }
    return 0;
}
