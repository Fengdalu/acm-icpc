#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <array>
#define dbg(x) std::cout << ""

typedef std::pair<int, int> PII;
#define AA first
#define BB second
std::array<std::array<int, 22>, 1000000> f;
std::array<int, 1000000>mm;

template<class T>
T gcd(T a, T b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int init() {
    mm[0] = -1;
    for(int i = 1; i < mm.size(); i++) {
        if((i & (i - 1)) == 0) mm[i] = mm[i - 1] + 1;
        else mm[i] = mm[i - 1];
    }
    return 0;
}

void get(int n) {
    for(int j = 0; j < 22; j++)
        for(int i = 1; i <= n; i++)
            if(i + (1 << (j + 1)) <= n + 1) {
                f[i][j + 1] = gcd(f[i][j], f[i + (1 << j)][j]);
            }
}

int cal(int l, int r) {
    int k = mm[r - l + 1];
    return gcd(f[l][k], f[r - (1 << k) + 1][k]);
}

int cmp(std::pair<PII, int> a, std::pair<PII, int> b) {
    if(a.AA.BB == b.AA.BB) return a.AA.AA < b.AA.AA;
    return a.AA.BB < b.AA.BB;
}

struct BIT {
    std::array<int, 1000010>_;
    void init() {
        dbg(_.size());
        _.fill(0);
    }
    static int lowbit(int x)  {
        return (x & (-x));
    }

    void push(int x, int w) {
        while(x < _.size()) {
            _.at(x) += w;
            x += lowbit(x);
        }
    }

    int cal(int x) {
        int tot = 0;
        while(x) {
            tot += _[x];
            x -= lowbit(x);
        }
        return tot;
    }
} T;

std::array<std::pair<PII, int>, 1000000> inter;
std::array<int, 1000000>ans;
inline void solve() {
    static int ___ = init();
    int n, Q;
    if(scanf("%d%d", &n, &Q) != 2) exit(0);
    for(int i = 1; i <= n; i++) scanf("%d", &f[i][0]);
    get(n);
    for(int i = 0; i < Q; i++) scanf("%d%d", &inter[i].AA.AA, &inter[i].AA.BB);
    for(int i = 0; i < Q; i++) inter[i].BB = i;

    std::sort(inter.begin(), inter.begin() + Q, cmp);
    std::map<int, int> f;
    T.init();
    int J = 0;
    for(int i = 1; i <= n; i++) {
        int pos = i;
        dbg(i), dbg(": "), dbg('\n');
        while(true) {
            int w = cal(pos, i);
            dbg(pos), dbg(" value: "), dbg(w), dbg("\n");
            if(f[w] != 0 && pos > f[w]) {
                T.push(pos, 1);
                T.push(f[w], -1);
                f[w] = pos;
            }
            else if(f[w] == 0){
                T.push(pos, 1);
                f[w] = pos;
            }

            int l = 1, r = pos;
            while(l < r) {
                int mid = (l + r + 1) / 2;
                if(cal(mid, i) == cal(pos, i)) r = mid - 1;
                else l = mid;
            }
            if(cal(l, i) == cal(pos, i)) break;
            pos = l;
        }
        dbg('\n');
        while(J < Q && inter[J].AA.BB == i) {
            ans[inter[J].BB] = T.cal(inter[J].AA.BB) - T.cal(inter[J].AA.AA - 1);
            J++;
        }
    }
    for(int i = 0; i < Q; i++)
        printf("%d\n", ans[i]);
}

int main() {
    while(true) solve();
    return 0;
}
