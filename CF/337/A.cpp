#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define LL long long
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()

int main() {
    int n;
    cin >> n;
    if(n & 1) puts("0");
    else {
        if(n % 4 == 0) n -= 2;
        printf("%d", n / 4);
    }
    return 0;
}
