#include <bits/stdc++.h>
const int N = 3003;
typedef long long ll;
int n;
template<typename T>
struct BIT {
    T _[2][2][N][N];
    int init() {
        memset(_, 0, sizeof _);
    }

    int lowbit(int x) { return x & (-x); }
    void update(int x, int y, T mk) {
        for(int i = x; i < N; i += lowbit(i))
            for(int j = y; j < N; j += lowbit(j))
                _[x&1][y&1][i][j] ^= mk;
    }
    T cal(int x, int y) {
        T tot = 0;
        for(int i = x; i != 0; i -= lowbit(i))
            for(int j = y; j != 0; j -= lowbit(j))
                tot ^= _[x&1][y&1][i][j];
        return tot;
    }
} ;
BIT<ll> T;

/*
 * 0: a[i][j]
 * 1: i * a[i][j]
 * 2: j * a[i][j]
 * 3: i * j * a[i][j]
 */


int main() {
    int m;
    static char op[10];
    while(~scanf("%d%d", &n, &m)) {
        memset(T._, 0, sizeof T._);
        for(int i = 0; i < m; i++) {
            ll x1, y1, x2, y2;
            scanf("%s", op);
            scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
           if(op[0] == 'Q') {
                x1--; y1--;
                ll mk =
                    T.cal(x2, y1)
                    ^T.cal(x1, y2)
                    ^T.cal(x2, y2)
                    ^T.cal(x1, y1);
                for(int j = 0; j < 50; j++)
                    printf("%c%c", "12"[mk>>j&1ll], "  "[j == 49]);
                puts("");
           }
           else {
               x2++; y2++;

               int K;
               scanf("%d", &K);
               ll add = 0;
               for(int i = 0; i < K; i++) {
                   ll a;
                   ll b;
                   scanf("%lld%lld", &a, &b);
                   add ^= ((ll)(b & 1ll)) << (a - 1);
               }
               T.update(x2, y2, add);
               T.update(x1, y2, add);
               T.update(x2, y1, add);
               T.update(x1, y1, add);
           }
        }
    }
    return 0;
}

