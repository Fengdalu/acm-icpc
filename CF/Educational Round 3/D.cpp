#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define LL long long
#define ONES(x) __builtin_popcount(x)
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

const int Maxn = 200010;
typedef pair<LL, LL> obj;
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
int n, m, k, S;
LL a[Maxn], b[Maxn];
obj s[Maxn];

bool check(int x) {
    LL d = -1;
    LL p = -1;
    for(int i = 0; i <= x; i++) cmax(d, a[i]);
    for(int i = 0; i <= x; i++) cmax(p, b[i]);

}

int main() {
    cin >> n >> m >> k >> S;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < m; i++) cin >> s[i].AA >> s[i].BB;

    int ans = n + 1;
    sort(s, s + m);
    int l = 0, r = n - 1;
    while(l < r) {
        int mid = (l + r) / 2;
        if(check1(mid)) r = mid;
        else l = mid + 1;
    }
    cmin(ans, l);
    for(int i = 0; i < m; i++) swap(s[i].AA, s[i].BB);
    sort(s, s + m);
    for(int i = 0; i < m; i++) swap(s[i].AA, s[i].BB);
    l = 0; r = n - 1;
    while(l < r) {
        int mid = (l + r) / 2;
        if(check2(mid)) r = mid;
        else l = mid + 1;
    }
    cmin(ans, l);
    cout << ans + 1 << endl;
    return 0;
}

