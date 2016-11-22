#include <bits/stdc++.h>

const int N = 2000;
double x[N], y[N];
double fa[N];
double w;
int n;

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

template <class T> T SQR(T x) { return x * x; }

double dis(double a, double b, double x, double y) {
    return sqrt(SQR(a - x) + SQR(b - y));
}

std::pair<bool, std::pair<double, double> > check(double v) {
    for(int i = 0; i <= n + 1; i++) fa[i] = i;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) if(dis(x[i], y[i], x[j], y[j]) <= v) {
            if(find(j) != find(i)) fa[find(i)] = find(j);
        }
    for(int i = 1; i <= n; i++) {
        if(x[i] <= v) {
            if(find(0) != find(i)) fa[find(0)] = find(i);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(x[i] >= w - v) {
            if(find(n + 1) != find(i)) fa[find(n + 1)] = find(i);
        }
    }
    if(find(0) == find(n + 1)) {
        return std::make_pair(true, std::make_pair(x[0], y[0]));
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            if(find(i) == find(0) && find(j) == find(n + 1)) {
                if(dis(x[i], y[i], x[j], y[j]) <= 2 * v) {
                    return std::make_pair(true, std::make_pair((x[i] + x[j]) / 2.0, (y[i] + y[j]) / 2.0));
                }
            }
        }
    for(int i = 1; i <= n; i++) {
        if(find(i) == find(0) && (w - x[i]) <= 2 * v) {
            return std::make_pair(true, std::make_pair((x[i] + w) / 2.0, y[i]));
        }
    }
    for(int i = 1; i <= n; i++) {
        if(find(i) == find(n + 1) && (x[i]) <= 2 * v) {
            return std::make_pair(true, std::make_pair((x[i]) / 2.0, y[i]));
        }
    }
    return std::make_pair(false, std::make_pair(-1, -1));
}

inline void solve() {
    scanf("%lf%d", &w, &n);
    if(n == 0) {
        printf("%.15f 0\n", w / 2);
        return;
    }
    for(int i = 1; i <= n; i++) scanf("%lf%lf", x + i, y + i);
    double l = 0, r = w;
    std::pair<double, double>t;
    for(int i = 0; i < 50; i++) {
        double mid = (l + r) / 2.0;
        std::pair<bool, std::pair<double, double> > tmp = check(mid);
        t = tmp.second;
        if(tmp.first)  {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    t = check(r).second;
    printf("%.15f %.15f", t.first, t.second);
}

int main() {
    freopen("froggy.in", "r", stdin);
    freopen("froggy.out", "w", stdout);
    solve();
    return 0;
}
