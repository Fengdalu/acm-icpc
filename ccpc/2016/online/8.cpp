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
}p[500]; int n;
pair<int, point>t[500];

inline int SQR(int x) { return x * x; }
inline int dis2(point &a, point &b) {
    return SQR(a.x - b.x) + SQR(a.y - b.y) + SQR(a.z - b.z);
}

int main() {
    int _T; scanf("%d", &_T); int cas = 1;
    while(_T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) p[i].input();
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
            int cnt = 0;
            for(int k = 0; k < n; k++) if(k != i && k != j) {
                point &a = p[i], &b = p[j], c = p[k];
                int d1 = dis2(a, c), d2 = dis2(b, c);
                if(d1 != d2) continue;
                t[cnt++] = MP(d1, (c - a) ^ (c - b));
            }
            sort(t, t + cnt);
            for(int i = 0; i < cnt; i++) {

            }
        }
    }
    return 0;
}
