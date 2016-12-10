#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 3e5;
int a[N], n;
LL f[N];

LL sub(int l, int r) {
    return f[r + 1] - f[l];
}

double cc(int l, int x) {
    return 1.0 * (sub(l - x , l) + sub(n - x, n - 1) - 1LL * a[l] * (2 * x + 1)) / (2 * x + 1);
}

pair<double, int> cal(int pos) {
    int l = 1, r = min(pos, n - 1 - pos);
    while(l < r - 3) {
        int mid = (l + r) >> 1;
        int midmid = (l + mid) >> 1;
        if(cc(pos, midmid) < cc(pos, mid)) l = midmid;
        else r = mid;
    }
    pair<double, int> p = make_pair(cc(pos, l), l);
    for(int i = l; i <= r; i++) p = max(p, make_pair(cc(pos, i), i));
    return p;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    if(n <= 2) {
        printf("%d\n", n);
        for(int i = 0; i < n; i++) printf("%d ", a[i]);
        return 0;
    }
    for(int i = 0; i < n; i++) f[i + 1] = 1LL * a[i] + f[i];

    pair<double, int> ans(0, -1);
    int pos;
    for(int i = 1; i < n - 1; i++) {
        pair<double, int> t = cal(i);
        if(t > ans) {
            pos = i;
            ans = t;
        }
    }
    if(ans.first == 0.0) {
        puts("1");
        printf("%d\n", a[0]);
    }
    else {
        int x = ans.second;
        printf("%d\n", 2 * ans.second + 1);
        for(int i = pos - x; i <= pos; i++) printf("%d ", a[i]);
        for(int i = n - x; i < n; i++) printf("%d ", a[i]);
    }
    return 0;
}

