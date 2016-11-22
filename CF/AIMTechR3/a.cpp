#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[1000100];
int main() {
    ll cur = 0;
    ll waste = 0;
    int n, b, d;
    scanf("%d%d%d", &n, &b, &d);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) {
        if(a[i] > b) continue;
        cur += 1ll * a[i];
        if(cur > d) waste++, cur = 0;
    }
    cout << waste << endl;
    return 0;
}
