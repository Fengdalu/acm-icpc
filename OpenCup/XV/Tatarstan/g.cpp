#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100010;
long long f[maxn];
long long pre[maxn], suc[maxn];
const long long tot = (long long)12e12;
int n;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int h, m, s;
        scanf("%d%d%d", &h, &m, &s);
        f[i] = (long long)s + (long long)m * 1e6 + (long long)h * 1e12;
    }
    sort(f + 1, f + 1 + n);
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + f[i];
    for(int i = n; i >= 1; i--)
        suc[i] = suc[i + 1] + f[i];
    long long p = f[1];
    long long s = (long long)(n - 1) * (tot + f[1]) - suc[2];
    for(long long i = 1; i <= n; i++) {
        long long t = (i - 1) * (f[i]) - pre[i - 1] + (n - i) * (f[i] + tot) - suc[i + 1];
        if(t < s) {
            p = f[i];
            s = t;
        }
    }
    long long h = 0, m = 0;
    s = 0;
    for(int i = 1; i <= n; i++) {
        long long t;
        if(f[i] <= p) t = p - f[i];
        else t = p + tot - f[i];
        h += t / (long long)1e12;
        t %= (long long)1e12;
        m += t / (long long)1e6;
        t %= (long long)1e6;
        s += t;
    }
    m += s / (long long)1e6;
    s %= (long long) 1e6;
    h += m / (long long)1e6;
    m %= (long long)1e6;
    cout << h << " " << m << " " << s << endl;
    return 0;
}
