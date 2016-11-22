#include <bits/stdc++.h>
using namespace std;

#define AA first
#define BB second
#define MP make_pair
typedef pair<int, int> PII;

const int N = 1000010;
struct BIT {
    int _[N];
    int n;
    int lb(int x) { return x & (-x); }
    void update(int x, int p) {
        while(x < n) {
            _[x] ^= p;
            x += lb(x);
        }
    }
    int cal(int x) {
        int ans = 0;
        while(x) {
            ans ^= _[x];
            x -= lb(x);
        }
        return ans;
    }
}B;

pair<int, int>q;
int a[N], ans[N];
pair<PII, int> Q[N];
int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int m; scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        Q[i] = MP(MP(y, x), i);
    }
    sort(Q, Q + m);
    int J = 0;
    B.n = n + 1;
    map<int, int>p;
    map<int, int>cnt;
    int sum = 0;
    for(int i = 0; i < n; i++) if(J < m) {
        int y = a[i];
        if(p[y] != 0) {
            B.update(p[y], y);
        }
        p[y] = i + 1;
        if(cnt[y] >= 1) sum ^= y; cnt[y]++;
        while(J < m && Q[J].AA.AA == i + 1) {
            ans[Q[J].BB] = sum ^ B.cal(Q[J].AA.BB - 1);
            J++;
        }
    }
    for(int i = 0; i < m; i++) printf("%d\n", ans[i]);
    return 0;
}
