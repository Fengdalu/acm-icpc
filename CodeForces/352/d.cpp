#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

int a[1000000];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    if(n == 1) { cout << 0 << endl; return 0; }
    if(n == 2) {
        int x, y;
        x = a[0]; y = a[1];
        int p = abs(x - y);
        if(2 * k >= p) {
            if(p % 2 == 1) cout << 1;
            else cout << 0;
        }
        else cout << p - 2 * k;
        return 0;
    }
    map<long long, int>f;
    map<long long, int>::iterator op, ed;
    for(int i = 0; i < n; i++) f[a[i]]++;
    int K = k;
    while(k) {
        if(f.size() == 1 && f.begin()->first == 0) break;
        ed = f.end();
        ed--;
        pair<long long, int>x = *ed;
        f.erase(ed);
        long long tot = k / x.second;
        if(tot == 0) {
            f[x.first - 1] = k;
            f[x.first] = x.second - k;
            break;
        }
        else {
            if(f.size() == 0) {
                long long t = max(x.first, (long long)k / (long long)x.second);
                k -= t * x.second;
                f[x.first - t] = x.second;
            }
            else {
                ed = f.end(); ed--;
                long long w = x.first - ed->first;
                long long t = min(w, (long long)k / (long long)x.second);
                k -= t * x.second;
                f[x.first - t] = x.second;
            }
        }
    }
    k = K;
    while(k) {
        op = f.begin();
        pair<long long, int>x = *op;
        f.erase(f.begin());
        long long tot = k / x.second;
        if(tot == 0) {
            f[x.first + 1] = k;
            f[x.first] = x.second - k;
            break;
        }
        else {
            if(f.size() == 0) {
                long long t = k / (long long)x.second;
                k -= t * x.second;
                f[x.first + t] = x.second;
            }
            else {
                op = f.end();
                long long w = op->first - x.first;
                long long t = min(w, (long long)k / (long long)x.second);
                k -= t * x.second;
                f[x.first + t] = x.second;
            }
        }
    }
    cout << f.rbegin()->first - f.begin()->first << endl;
}
