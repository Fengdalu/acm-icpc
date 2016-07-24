#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef map<pii, int>::iterator IT;
const ll mod = 1e9 + 7;
int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}
int x[2000], y[2000];
ll two[2000];

int main() {
    int T;
    scanf("%d", &T);
    two[0] = 1;
    for(int i = 1; i < 2000; i++) two[i] = (two[i - 1] * 2LL) % mod;
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            map<pii, int>f;
            for(int j = 0; j < n; j++)
                if(i != j) {
                    int aa = x[j] - x[i], bb = y[j] - y[i];
                    if(aa == 0 && bb == 0) {
                        f[mp(aa, bb)]++;
                    }
                    ll c = gcd(aa, bb);
                }
            for(IT it = f.begin(); it != f.end(); it++) {
                cout << "it "<< it->second << endl;
                ans = (ans + two[it->second]) % mod;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
