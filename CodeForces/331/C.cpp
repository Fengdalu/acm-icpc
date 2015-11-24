#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define SZ size()
#define OP begin()
#define ED end()
#define PB(x) push_back(x)

const int N = 1000100;
map< int, vector< PII > >f;
map< int, vector< PII > >::iterator it;
PII ans[N];
int n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        f[y - x].PB(MP(x, y));
    }
    for(it = f.OP; it != f.ED; it++) {
        sort(it->BB.OP, it->BB.ED);
    }

    for(int i = 0; i < n; i++) {
        int m; scanf("%d", &m);
        if(!f[m].SZ) { puts("NO"); return 0; }
        ans[i] = *f[m].OP;
        f[m].erase(f[m].OP);
    }
    for(int i = 0; i < n - 1; i++) {
        if(ans[i].AA >= ans[i + 1].AA && ans[i].BB >= ans[i + 1].BB) { puts("NO"); return 0; }
    }
    puts("YES");
    for(int i = 0; i < n; i++) {
        printf("%d %d\n", ans[i].AA, ans[i].BB);
    }
    return 0;
}

