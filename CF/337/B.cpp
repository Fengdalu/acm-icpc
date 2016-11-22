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

LL a[2000100];
vector<int>p;
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    LL ans = a[0];
    for(int i = 0; i < n; i++) ans = min(ans, a[i]);
    for(int i = 0; i < n; i++) a[i] -= ans;
    LL tot = ans * n;
    for(int i = 0; i < n; i++) if(a[i] == 0) p.PB(i);
    int m = 0;
    for(int i = 0; i < p.SZ - 1; i++) m = max(m, p[i + 1] - p[i]);
    m = max(m, p[0] + n - p[p.SZ - 1]);
    m--;
    cout << tot + m;
    return 0;
}
