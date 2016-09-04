#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
typedef long long ll;
#define AA first
#define BB second
#define MP make_pair
#define PII pair<int, int>

template <class T>
T SQR(T x) {
    return x * x;
}

int n;
ll m[60000];

ll check(ll p) {
    ll s1 = 0, s2 = 0, cnt = 0;
    ll tot = 0;
    queue< pair<ll, ll> >q;
    for(ll i = n - 1; i >= 0; i--) {
        while(q.size()) {
            ll t = q.front().first;
            if(p - SQR(t - i) <= 0) {
                ll cc = q.front().second;
                s1 -= cc * t;
                s2 -= cc * SQR(t);
                cnt -= cc;
                q.pop();
            }
            else break;
        }
        ll atk = cnt * p - s2 + 2ll * i * s1 - cnt * SQR(i);
        if(atk <= m[i]) {
            ll _cnt = (m[i] - atk) / p + 1;
            tot += _cnt;
            cnt += _cnt;
            s1 += _cnt * i;
            s2 += _cnt * SQR(i);
            q.push(MP(i, _cnt));
        }
    }
    return tot;
}

inline void run() {
    int k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        int _; scanf("%d", &_);
        m[i] = _;
    }
    ll l = 1, r = 1ll<<62;
    while(l < r) {
        ll mid = (l + r) >> 1;
        if(check(mid) > k) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--)  run();
    return 0;
}
