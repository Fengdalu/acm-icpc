#include <bits/stdc++.h>

const int N = 100000;
const int M = 2000000;
int ind[N];
int to[M], nt[M];
double p[N], cc[N];
double c[M];
double f[N];
int in[N];
int cnt;
double arr[N * 3];

void add(int a, int b, double w) {
    //std::cout << "add " << a << " " << b << " " << w << std::endl;
    to[cnt] = b;
    nt[cnt] = ind[a];
    c[cnt] = w;
    ind[a] = cnt++;
    in[b]++;
}

void solve() {
    int n, m;
    scanf("%d", &n);
    if(n == 0) exit(0);
    std::fill(ind, ind + n + 10, -1);
    std::fill(in, in + n + 10, 0);
    cnt = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%lf%lf", p + i, cc + i);
        f[i] = log(p[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int K; scanf("%d", &K);
        for(int j = 0; j < 2 * K - 1; j++) scanf("%lf", arr + j);
        for(int i = 0; i < 2 * K - 3; i += 2) {
            add(arr[i + 2], arr[i], log(arr[i + 1]));
        }
    }
    std::queue<int>q;
    for(int i = 1; i <= n; i++) if(in[i] == 0) q.push(i);
    while(q.size()) {
        int t = q.front();
        q.pop();
        for(int k = ind[t]; k != -1; k = nt[k]) {
            int v = to[k];
            f[v] = std::max(f[v], f[t] + c[k]);
            in[v]--;
            if(in[v] == 0) q.push(v);
        }
    }
    double ans = 0;
    for(int i = 1; i <= n; i++) ans += cc[i] * exp(f[i]);
    //for(int i = 1; i <= n; i++) std::cout << p[i] << " " << cc[i] << " " << f[i] << std::endl;
    printf("%.2f\n", ans);
}

int main() {
    while(true) solve();
    return 0;
}
