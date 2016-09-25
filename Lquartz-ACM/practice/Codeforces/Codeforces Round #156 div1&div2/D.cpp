//#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

LL n, c, x, y;

#define Maxn 11111111

LL A[Maxn], B[Maxn];

LL calc(LL l) {
    if(l < 1) return 0;
    LL ret = 0;
    ret = (1 + l) * l / 2;
    //cout << "calc " << l << " " << ret << endl;
    ret -= (1 + l / 2) * (l / 2);
    //cout << "calc " << l << " " << ret << endl;
    return ret;
}

LL calc1(LL l) {
    if(l < 1) return 0;
    LL ret = (1 + l) * l / 2;
    //cout << "calc1 " << l << " " << ret << endl;
    return ret;
}

int main() {
    int i, j, k;
    LL u, v, w, z;
    LL uu, vv, ww, zz;

    while(cin >> n >> x >> y >> c) {
        A[0] = 1; B[0] = 1;
        for(i = 1; ; i++) {
            B[i] = i * 2 + 1;
            A[i] = calc(B[i]) + calc(B[i] - 2);
            if(A[i] > c * 8) break;
        }
        for(i = 0; ; i++) {
            u = x - B[i] / 2;
            v = x + B[i] / 2;
            w = y - B[i] / 2;
            z = y + B[i] / 2;
            //printf("%lld %lld %lld %lld\n", u, v, w, z);
            //printf("%d A %lld B %lld\n", i, A[i], B[i]);
            if(u < 1) {
                A[i] -= calc((1LL - u) * 2 - 1);
            }
            if(v > n) {
                A[i] -= calc((v - n) * 2 - 1);
            }
            if(w < 1) {
                A[i] -= calc((1LL - w) * 2 - 1);
            }
            if(z > n) {
                A[i] -= calc((z - n) * 2 - 1);
            }
            //printf("%d A %lld B %lld\n", i, A[i], B[i]);
            if(u < 1 && z > n) {
                uu = y + ((1LL - u) * 2 - 1) / 2 - n;
                zz = 1 - (x - ((z - n) * 2 - 1) / 2);
                A[i] += calc1(min(uu, zz));
            }
            if(z > n && v > n) {
                zz = x + ((z - n) * 2 - 1) / 2 - n;
                vv = y + ((v - n) * 2 - 1) / 2 - n;
                A[i] += calc1(min(zz, vv));
            }
            if(v > n && w < 1) {
                vv = 1 - (y - ((v - n) * 2 - 1) / 2);
                ww = x + ((1LL - w) * 2 - 1) / 2 - n;
                A[i] += calc1(min(vv, ww));
            }
            if(w < 1 && u < 1) {
                ww = 1 - (x - ((1LL - w) * 2 - 1) / 2);
                uu = 1 - (y - ((1LL - u) * 2 - 1) / 2);
                A[i] += calc1(min(ww, uu));
            }
            
            //printf("%d A %lld B %lld\n", i, A[i], B[i]);
            if(A[i] >= c) {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}
