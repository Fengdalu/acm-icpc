#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <numeric>      // std::accumulate

const int N = 10010;
const double INF = 1e17;
struct node {
    double s, t;
} f[N];

// t, good mood
// s, bad mood
double cal(double s1,  double t1, double s2, double t2, double L, double W) {
    if(s1 < s2) {
        std::swap(t1, t2);
        std::swap(s1, s2);
    }
    if(s1 * L <= W) return std::min(t1, t2) * L;
    if(s2 * L > W) return INF;
    if(s1 > s2 && t1 > t2) return t2 * L;
    double x = (W - s2 * L) / (s1 - s2);
    if(x < 0) return INF;
    return t1 * x + t2 * (L - x);
}

int cmp(node a, node b) {
    return a.s > b.s;
}

int cmp1(node a, node b) {
    return a.t < b.t;
}

void solve() {
    int n; double d, L, W;
    scanf("%d%lf%lf%lf", &n, &d, &L, &W);
    for(int i = 0; i < n; i++) scanf("%lf%lf",&f[i].s, &f[i].t);
    double sum = 0;
    for(int i = 0; i < n; i++) sum = sum + f[i].s;
    if(sum * d > W || d * n > L) {
        printf("No solution\n");
        return;
    }
    double add = 0;
    for(int i = 0; i < n; i++) add += d * f[i].t;
    L = L - d * n;
    W = W - sum * d;
    int split = -1;
    std::sort(f, f + n, cmp);
    for(int i = 0; i < n; i++) {
        if(f[i].s * L <= W) {
            split = i;
            break;
        }
    }
    if(split == -1) {
        printf("No solution\n");
        return;
    }
    std::sort(f, f + split, cmp1);
    std::sort(f + split, f + n, cmp1);
    double ans = INF;
    for(int i = 0; i < n; i++)
            ans = std::min(ans, cal(f[i].s, f[i].t, f[i].s, f[i].t, L, W));
    for(int i = 0; i < split; i++)
        for(int j = split; j < n && f[i].t < f[j].t; j++) {
            ans = std::min(ans, cal(f[i].s, f[i].t, f[j].s, f[j].t, L, W));
        }

    if(add + ans <= INF)
        printf("%.2f\n", add + ans);
    else printf("No solution\n");
}

int main() {
    int _t; scanf("%d", &_t);
    while(_t--) solve();
    return 0;
}
