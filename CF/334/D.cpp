#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define LL long long
#define cmax(x, y) x = max(x, y)
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define LEN(Q) (Q.BB - Q.AA + 1)

const LL MOD = 1000000007LL;
bool vis[1000100];
LL p, k;

LL qpow(LL x, LL p) {
    LL ans = 1;
    while(p){
        if(p & 1) ans *= x;
        x *= x; p /= 2;
        ans %= MOD;
        x %= MOD;
    }
    return ans;
}

int main() {
    cin >> p >> k;
    if(k == 1) { cout << qpow(p, p) % MOD <<endl;  return 0; }
    for(LL i = 0; i < p; i++) {
        if(i * k % p == i) vis[i] = true;
    }
    LL cnt = 0;
    for(LL i = 0; i < p; i++) if(!vis[i]) {
        LL x = i;
        cnt++;
        while(!vis[x]) {
            vis[x] = true;
            x *= k;
            x %= p;
        }
    }
    cout << qpow(p, cnt) % MOD <<endl;
}
