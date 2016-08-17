#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <cmath>
using namespace std;

#define MP make_pair
#define AA first
#define BB second
#define gcd __gcd
typedef long long ll;
struct point {
    int x,y,z;
    double tht;
    point() {}
    point(double xx,double yy,double zz) {
        x=xx; y=yy; z=zz;
    }

    inline void output() {
        printf("(%d,%d,%d)\n",x,y,z);
    }
    inline void input() {
        scanf("%d%d%d",&x,&y,&z);
    }
    inline point operator -(const point &b) {
        return point(x - b.x, y - b.y, z-b.z);
    }
    inline point operator +(const point &b) {
        return point(x + b.x, y + b.y, z + b.z);
    }
    inline point operator ^(const point &b) {
        return point(y*b.z-b.y*z, b.x*z-x*b.z, x*b.y-b.x*y);
    }
    inline int operator *(const point &b) {
        return x*b.x + y*b.y + z*b.z;
    }
    inline void reverse() {
        x *= -1, y *= -1, z *= -1;
    }
    inline int operator < (const point &p) const{
        return MP(x, MP(y, z)) < MP(p.x, MP(y, z));
    }
    inline void mod() {
        int t = gcd(x, gcd(y, z));
        x /= t, y /= t, z /= t;
        if((x < 0) || (x == 0 && y < 0) || (x == 0 && y == 0 && z < 0)) reverse();
    }
    inline bool operator != (const point &p) const {
        return MP(x, MP(y, z)) == MP(p.x, MP(p.y, p.z));
    }
}p[500]; int n;
pair<int, point>t[500];

inline int SQR(int x) { return x * x; }
inline int dis2(point &a, point &b) {
    return SQR(a.x - b.x) + SQR(a.y - b.y) + SQR(a.z - b.z);
}

inline ll C2(ll x) { return x * (x - 1) / 2; }

int main() {
    int _T; scanf("%d", &_T); int cas = 1;
    while(_T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) p[i].input();
        ll ans = 0;
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
            printf("Point: %d %d: \n", i, j);
            int cnt = 0;
            for(int k = 0; k < n; k++) if(k != i && k != j) {
                point &a = p[i], &b = p[j], c = p[k];
                int d1 = dis2(a, c), d2 = dis2(b, c);
                if(d1 != d2) continue;
                t[cnt++] = MP(d1, (c - a) ^ (c - b));
            }
            sort(t, t + cnt);
            int l = 0;
            for(int k = 0; k < cnt; k++) printf("%d ", t[i].AA); printf("\n");
            for(int k = 0; k < cnt; k++) {
                if(k == cnt - 1 || t[k].AA != t[k + 1].AA) {
                    ans += C2(k - l + 1);
                    int cur = 0;
                    for(int p = l; p <= k; p++) {
                        if(p == k || t[p].BB != t[p].BB) {
                            ans -= C2(cur);
                            cur = 0;
                        }
                        ans++;
                    }
                    l = k + 1;
                    cout << ans << endl;
                }
            }
        }
        ans /= 2;
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) for(int k = j + 1; k < n; k++) {
            auto &a = p[i], &b = p[j], &c = p[k];
            int da = dis2(a, b), db = dis2(b, c);
            if(da == db) continue;
            for(int J = 0; J < n; J++) if(i != J && j != J && k != J) {
                auto &d = p[J];
                if(dis2(a, d) == dis2(b, d) && dis2(b, d) == dis2(c, d)) ans -= 2;
            }
        }
        printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}
