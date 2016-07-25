#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using std::sort;
using std::pair;
using std::map;
using std::cout;
using std::endl;
using std::__gcd;
using std::make_pair;
#define MP(x, y) make_pair(x, y)
#define AA first
#define BB second
typedef long long ll;
typedef pair<int, int> pii;
typedef map<pii, int>::iterator IT;
typedef pair<int, int> PII;

const ll mod = 1e9 + 7;
int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}
ll two[2000];
PII P[2000];

int main() {
    int T;
    scanf("%d", &T);
    two[0] = 1;
    for(int i = 1; i < 2000; i++) two[i] = (two[i - 1] * 2LL) % mod;
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &P[i].AA, &P[i].BB);
        }
        ll ans = 0;
        sort(P, P + n);
        ll tot = 0;
        for(int i = 0; i < n; i++) {
            map<PII, int>f;
            ll cnt = 0;
            for(int j = i + 1; j < n; j++) {
                if(P[i] == P[j]) { cnt++; continue; }
                int Y = P[j].BB - P[i].BB;
                int X = P[j].AA - P[i].AA;
                int cc = gcd(X, Y);
                f[MP(X / cc, Y / cc)]++;
            }
            tot += two[cnt] - 1;
            tot %= mod;
            for(IT it = f.begin(); it != f.end(); it++) {
                tot += 1LL * (ll)two[cnt] % mod * (two[it->BB] - 1) % mod;
                tot %= mod;
            }
        }
        cout << tot << endl;
    }
    return 0;
}
