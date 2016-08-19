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
typedef long long ll;
int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}

inline ll SQR(int x) { return 1ll*x*x; }
struct point {
    int x,y,z;
    double tht;
    point() {}
    point(double xx,double yy,double zz) {
        x=xx; y=yy; z=zz;
    }

    void output() {
        printf("(%d,%d,%d)\n",x,y,z);
    }

    ll val() {
        return 1ll * SQR(x) + 1ll * SQR(y) + 1ll * SQR(z);
    }

    void input() {
        scanf("%d%d%d",&x,&y,&z);
    }
    point operator -(const point &b) {
        return point(x - b.x, y - b.y, z-b.z);
    }
    point operator +(const point &b) {
        return point(x + b.x, y + b.y, z + b.z);
    }
    point operator ^(const point &b) {
        return point(y*b.z-b.y*z, b.x*z-x*b.z, x*b.y-b.x*y);
    }
    ll operator *(const point &b) {
        return 1ll*x*b.x + 1ll*y*b.y + 1ll*z*b.z;
    }
    void reverse() {
        x *= -1, y *= -1, z *= -1;
    }
    ll operator < (const point &p) const{
        return MP(x, MP(y, z)) < MP(p.x, MP(y, z));
    }
    point& mod() {
        int t = gcd(abs(x), gcd(abs(y), abs(z)));
        if(t != 0) { x /= t, y /= t, z /= t; }
        if((x < 0) || (x == 0 && y < 0) || (x == 0 && y == 0 && z < 0)) reverse();
        return *this;
    }
    bool operator == (const point &p) const {
        return MP(x, MP(y, z)) == MP(p.x, MP(p.y, p.z));
    }
}p[500]; int n;
ll t[500];

inline ll dis2(point &a, point &b) {
    return 1ll * SQR(a.x - b.x) + SQR(a.y - b.y) + SQR(a.z - b.z);
}

inline int C2(ll x) { return x * (x - 1) / 2; }

bool chk(point a, point b) {
    /*
    cout << "CHK: " << endl;
    a.output(); b.output();
    cout << a * b << endl;
    cout << a.val() << " " << b.val() << endl;
    */
    /* both ac */
    return 1ll * a.val() * b.val() == 1ll * SQR(a * b);
    /* both ac */
    return (1ll * a.x * b.y == 1ll * a.y * b.x) && (1ll * a.y * b.z == 1ll * a.z * b.y) && (1ll * a.x * b.z == 1ll * a.z * b.x);
}

int main() {
    int _T; scanf("%d", &_T); int cas = 1;
    while(_T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) p[i].input();
        int ans = 0;
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
            //printf("Point: %d %d: \n", i, j);
            int cnt = 0;
            for(int k = 0; k < n; k++) if(k != i && k != j) {
                point &a = p[i], &b = p[j], c = p[k];
                ll d1 = dis2(a, c), d2 = dis2(b, c);
                if(d1 != d2) continue;
                t[cnt++] = d1;
            }
            sort(t, t + cnt);
            int l = 0;
            //for(int k = 0; k < cnt; k++) printf("%d ", t[i].AA); printf("\n");
            for(int k = 0; k < cnt; k++) {
                if(k == cnt - 1 || t[k] != t[k + 1]) {
                    ans += C2(k - l + 1);
                    l = k + 1;
                }
            }
        }
        ans /= 2; //cout << ans << endl;
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) for(int k = j + 1; k < n; k++) {
            auto &a = p[i], &b = p[j], &c = p[k];
            ll da = dis2(a, c), db = dis2(b, c);
            if(da != db) continue;
            for(int J = k + 1; J < n; J++) {
                auto &d = p[J];
                if(dis2(a, d) == dis2(b, d) && dis2(b, d) == dis2(a, c) && dis2(a, b) == dis2(a, d) && dis2(a, b) == dis2(c, d)) ans -= 2;
            }
        }
        int tmp = 0;
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) for(int k = 0; k < n; k++) {
            auto &a = p[i], &b = p[j], &c = p[k];
            ll da = dis2(a, c), db = dis2(b, c);
            if(da != db) continue;
            for(int J = k + 1; J < n; J++) {
                auto &d = p[J];
                if(dis2(a, d) == dis2(b, d))
                if(dis2(a, d) == dis2(a, c))
                if(chk(((a - c) ^ (b - c)).mod(), ((a - d) ^ (b - d)).mod())) {
                    tmp++;
                }
            }
        }
        ans -= tmp / 2;
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}

