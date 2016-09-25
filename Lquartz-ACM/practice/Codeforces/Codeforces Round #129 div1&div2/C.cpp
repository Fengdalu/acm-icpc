#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define NAME ""

map<LL, LL> mp;
LL ee[100];

LL dfs(LL n, int bits, LL e, int first, int flag = -1) {
    //printf("dfs %lld %d %lld %d\n", n, bits, e, flag);
    map<LL, LL>::iterator IT = mp.find(n);
    if(IT != mp.ED) {
        //printf("end %lld %d %lld %d xx %lld\n", n, bits, e, flag, (*IT).BB);
        return (*IT).BB;
    }
    if(bits == 1) {
        if(first <= n) {
            if(flag == -1) {
            mp[n] = 1;
            }
            else {
                mp[n] = n + 1;
            }
        }
        else {
            if(flag == -1) {
                mp[n] = 0;
            }
            else {
                mp[n] = n + 1;
            }
        }
        //printf("end %lld %d %lld %d xx %lld\n", n, bits, e, flag, mp[n]);
        return mp[n];
    }
    LL tp = 0;
    int high = n / e;
    //printf("high %d\n", high);
    for(int i = (flag == -1 ? 0 : 1); i < high; i++) {
        tp += ee[bits - 2];
    }
    if(bits > 2) {
        LL ttp = 9LL * ee[bits - 3];
        tp += ttp;
    }
    if(bits == 2) {
        LL ttp = 10;
        tp += ttp;
    }
    tp += dfs(n % e, bits - 1, e / 10, first);
    //printf("end %lld %d %lld %d xx %lld\n", n, bits, e, flag, tp);
    return (mp[n] = tp);
}

LL calc(LL n) {
    int i, j, k;
    LL u, v, w;
    i = 1; w = 1; u = n;
    do {
        u /= 10;
        if(u == 0) break;
        i++; w *= 10;
    }while(u);
    mp.clear();
    return dfs(n, i, w, n / w, n / w);
}

int main() {
    int i, j, k, u, v, w;
    LL l, r;
    ee[0] = 1;
    for(i = 1; i < 20; i++) ee[i] = ee[i - 1] * 10;
    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    while(cin >> l >> r) {
        cout << calc(r) - calc(l - 1) << endl;
    }
    return 0;
}
