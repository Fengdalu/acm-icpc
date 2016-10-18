#include <bits/stdc++.h>

#define AA first
#define BB second
typedef std::pair<int, int> pii;
typedef std::map<pii, int>::iterator IT;

template <typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}

pii operator + (pii a, pii b) {
    if(a == pii(0, 0)) return b;
    if(b == pii(0, 0)) return a;
    pii r = std::make_pair(a.AA * b.BB + a.BB * b.AA, b.BB * a.BB);
    int c = gcd(r.AA, r.BB);
    r.AA /= c; r.BB /= c;
    return r;
}

const int N = 5000;
int a[N];
int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    std::sort(a, a + n);
    for(int mx = 1; mx <= n; mx++) {
        std::map<pii, int> f;
        f[pii(0, 0)] = 0;
        for(int i = 0; i < mx; i++) {
            int x = a[i];
            pii C(1, x);
            std::queue<pii> Q;
            std::queue<int> W;
            for(IT it = f.begin(); it != f.end(); it++) {
                pii R = it->first + C;
                if(R.first > R.second) continue;
                if(R == pii(1, 1)) {
                    printf("%d\n", it->second + 1);
                    return 0;
                }
                if(f.find(R) == f.end() || it->second + 1 < f[R]) {
                    Q.push(R);
                    W.push(it->second);
                }
            }
            while(Q.size()) {
                f[Q.front()] = W.front() + 1;
                Q.pop(); W.pop();
            }
        }
    }
    puts("No solution");
    return 0;
}
