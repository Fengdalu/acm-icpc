#include <bits/stdc++.h>

#define MP std::make_pair
#define AA first
#define BB second
#define cmax(x, y) x = std::max(x, y)
const int N = 2e5+100;
typedef long long ll;
typedef std::pair<ll, int> sta;
ll a[N];
int main() {
    int n, K; ll x;  scanf("%d%d%I64d", &n, &K, &x);
    for(int i = 0; i < n; i++) scanf("%I64d", a + i);
    std::priority_queue<sta, std::vector<sta>,  std::greater<sta> >s1, s2, s0;
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) s2.push(MP(a[i], i));
        if(a[i] == 0) s0.push(MP(a[i], i));
        if(a[i] < 0) s1.push(MP(-a[i], i));
    }
    if(K < s0.size()) {
        for(int i = 0; i < n; i++)
            printf("%I64d ", a[i]);
        return 0;
    }
    if(s0.size()) {
        if(s1.size() % 2 == 0) {
            s1.push(MP(x, s0.top().second));
            s0.pop();
            K--;
        }
        while(s0.size()) {
            s2.push(MP(x, s0.top().second));
            s0.pop();
            K--;
        }
    }
    if(s1.size() % 2 == 0) {
        if(s1.size() && (s2.size() == 0 || s1.top() < s2.top())) {
            sta t = s1.top();
            s1.pop();
            while(K && t.first >= 0) {
                t.first -= x;
                K--;
            }
            if(t.first < 0) s2.push(MP(-t.first, t.second));
            else s1.push(t);
        }
        else {
            sta t = s2.top();
            s2.pop();
            while(K && t.first >= 0) {
                t.first -= x;
                K--;
            }
            if(t.first < 0) s1.push(MP(-t.first, t.second));
            else s2.push(t);
        }
    }
    while(K) {
        if(s1.size() && (s2.size() == 0 || s1.top() < s2.top())) {
            sta t = s1.top();
            s1.pop();
            t.first += x;
            s1.push(t);
        }
        else {
            sta t = s2.top();
            s2.pop();
            t.first += x;
            s2.push(t);
        }
        K--;
    }
    while(s1.size()) {
        a[s1.top().second] = -s1.top().first;
        s1.pop();
    }
    while(s2.size()) {
        a[s2.top().second] = s2.top().first;
        s2.pop();
    }
    for(int i = 0; i < n; i++) printf("%I64d ", a[i]);
    return 0;
}
