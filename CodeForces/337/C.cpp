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

int ans[2000][2000];
int n;

void build(int n) {
    if(n == 0) ans[0][0] = 1;
    else {
        build(n - 1);
        for(int i = 0; i < (1 << (n - 1)); i++)
            for(int j = (1 << (n - 1)); j < (1 << (n)); j++)
                ans[i][j] = ans[i][j - (1 << (n - 1))];
        for(int i = (1 << (n - 1)); i < (1 << (n)); i++)
            for(int j = 0; j < (1 << (n - 1)); j++)
                ans[i][j] = ans[i - (1 << (n - 1))][j];
        for(int i = (1 << (n - 1)); i < (1 << (n)); i++)
            for(int j = (1 << (n - 1)); j < (1 << (n)); j++)
                ans[i][j] = 1 - ans[i - (1 << (n - 1))][j - (1 << (n - 1))];
    }
}

int main() {
    cin >> n;
    build(n);
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < (1 << n); j++)
            if(ans[i][j]) printf("+"); else printf("*");
        puts("");
    }
    return 0;
}
