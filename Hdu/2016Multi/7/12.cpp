#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

#define PII pair<int, int>
#define AA first
#define BB second
#define MP make_pair
const int _n = 50010;

int cmp(pair<PII, int> a, pair<PII, int>b) {
    return a.BB < b.BB;
}

struct BIT {
    int _[50020];
    int lb(int x) { return x & (-x); }
    void init() {
        memset(_, 0, sizeof _);
    }
    void insert(int a, int x) {
        assert(a > 0);
        while(a <= _n) {
            _[a] += x;
            a += lb(a);
        }
    }
    int cal(int a) {
        int _tot = 0;
        while(a) {
            _tot += _[a];
            a -= lb(a);
        }
        return _tot;
    }
}B;

int n;
int lft[500010];
int down[500010];
pair<PII, int>p[500010];
pair<PII, PII>s[500010 * 3];
int check() {
    sort(p, p + n);
    for(int i = 0; i < n; i++) lft[i] = down[i] = -1;
    for(int i = 0; i < n - 1; i++) {
        int a = p[i].BB, b = p[i + 1].BB;
        if(p[i].AA.AA == p[i + 1].AA.AA) {
            down[b] = a;
        }
    }
    for(int i = 0; i < n; i++) swap(p[i].AA.AA, p[i].AA.BB);
    sort(p, p + n);
    for(int i = 0; i < n - 1; i++) {
        int a = p[i].BB, b = p[i + 1].BB;
        if(p[i].AA.AA == p[i + 1].AA.AA) lft[b] = a;
    }
    for(int i = 0; i < n; i++) swap(p[i].AA.AA, p[i].AA.BB);
    int cnt = 0;
    sort(p, p + n, cmp);

   for(int i = 0; i < n; i++) {
        int l = 1, r = p[i].AA.AA - 1;
        int up = p[i].AA.BB, d = 1;
        int id = p[i].BB;
        if(lft[id] != -1) l = p[lft[id]].AA.AA + 1;
        if(down[id] != -1) d = p[down[id]].AA.BB + 1;
        if(l > r || up <= d) continue;
        s[cnt++] = MP(MP(d, -1), MP(l, r));
        s[cnt++] = MP(MP(up, +1), MP(l, r));
        //cout << "POINT: " << " " << p[i].AA.AA << " " << p[i].AA.BB << endl;
        //cout << l << " " << r << endl;
        //cout << up << " " << d << endl;
        //cout << "=====" << endl;
    }
    sort(s, s + cnt);
    B.init();
    for(int i = 0; i < n; i++) swap(p[i].AA.AA, p[i].AA.BB);
    sort(p, p + n);
    int J = 0;
    //cout << "JUDGE" << endl;
    for(int i = 0; i < n; i++) {
        while(J < cnt && s[J].AA.AA <= p[i].AA.AA) {
            int tmp = s[J].AA.BB;
            B.insert(s[J].BB.AA, -tmp);
            B.insert(s[J].BB.BB, tmp);
            //cout << s[J].BB.AA << " " << s[J].BB.BB << ' ' << " " << s[J].AA.AA << " " << tmp << endl;
            J++;
        }
        if(B.cal(p[i].AA.BB)) {
            //cout << B.cal(p[i].AA.BB) << endl;
            //cout << p[i].AA.AA << " " << p[i].AA.BB << endl;
            //p
            for(int i = 0; i < n; i++) swap(p[i].AA.AA, p[i].AA.BB);
            return false;
        }
    }
    for(int i = 0; i < n; i++) swap(p[i].AA.AA, p[i].AA.BB);
    return true;
}

int main() {
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = 0; i < n; i++) scanf("%d%d", &p[i].AA.AA, &p[i].AA.BB);
        for(int i = 0; i < n; i++) p[i].AA.AA++, p[i].AA.BB++;
        for(int i = 0; i < n; i++) p[i].BB = i;
        bool flag = check();
        for(int i = 0; i < n; i++) p[i].AA.BB = 50010 - p[i].AA.BB;
        flag &= check();
        if(flag) puts("YES"); else puts("NO");
    }
    return 0;
}
