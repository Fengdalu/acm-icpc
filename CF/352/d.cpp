#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

long long a[1000000];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%I64d", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);
    if(a[0] == a[n - 1]) {cout << 0; return 0;}
    if(k == 0) { cout << a[0] - a[n - 1]; return 0; }
    long long tot = 0;
    for(int i = 0; i < n; i++) tot += (long long) a[i];
    long long p = tot / n;
    long long sum1 = 0;
    for(int i = 0; i < tot % n; i++) if(a[i] > p + 1) sum1 += a[i] - p - 1;
    for(int i = tot % n; i < n; i++) if(a[i] > p) sum1 += abs(a[i] - p);
    if(k >= sum1) {
        if(tot % (long long)n == 0) cout << 0;
        else cout << 1;
        return 0;
    }
    long long sum = a[0];
    long long L(0), R(0);
    for(int i = 1; i < n; i++) {
        long long change = sum - (long long)(a[i] * i);
        if(change >= k) {
            long long per = (sum - k) / i;
            long long mod = (sum - k) % i;
            if(mod) R = per + 1;
            else R = per;
            break;
        }
        sum += a[i];
    }
    sort(a, a + n);
    sum = a[0];
    for(int i = 1; i < n; i++) {
        long long change = (a[i] * i)  - sum;
        if(change >= k) {
            long long per = (sum + k) / i;
            long long mod = (sum + k) % i;
            L = per;
            break;
        }
        sum += a[i];
    }
    sort(a, a + n);
    cout << R - L << endl;
}
