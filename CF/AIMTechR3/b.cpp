#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int x[100001];
int n, a;
int main() {
    scanf("%d%d", &n, &a);
    for(int i = 0; i < n; i++)
    scanf("%d", &x[i]);
    if(n == 0) { puts("0"); return 0; }
    x[n++] = a;
    sort(x, x + n);
    int p = lower_bound(x, x + n, a) - x;
    if(p == 0) {
        ll tot = 0;
        for(int i = 0; i < n - 2; i++) {
            tot += x[i + 1] - x[i];
        }
        cout << tot << endl;
    }
    else if(p == n - 1) {
        ll tot = 0;
        for(int i = n - 1; i >= 2; i--) {
            tot += x[i] - x[i - 1];
        }
        cout << tot << endl;
    }
    else {
        ll l1 = 0, l2 = 0, r1 = 0, r2 = 0;
        for(int i = p; i < n - 1; i++) r1 += x[i + 1] - x[i];
        for(int i = p; i < n - 2; i++) r2 += x[i + 1] - x[i];

        for(int i = p; i >= 1; i--) l1 += x[i] - x[i - 1];
        for(int i = p; i >= 2; i--) l2 += x[i] - x[i - 1];
        cout << min(min(l1, r2) + l1 + r2, min(l2, r1) + l2 + r1);
    }
    return 0;
}
