#include <bits/stdc++.h>

using namespace std;
#define AA first
#define BB second
#define MP make_pair
#define PII pair<int, int>

PII a[50];
int b[50];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i].AA);
    for(int i = 0; i < n; i++) a[i].BB = i;
    sort(a, a + n, greater<PII>());
    for(int i = 0; i < n; i++) b[i] = a[i].AA;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        int g = a[i].AA;
        for(int j = 1; j <= n && g; j++) {
            int k = (i + j) % n;
            if(k == i) flag = false;
            int t = min(g, b[k]);
            g -= t;
            b[k] -= t;
        }
    }
    if(flag) {
        for(int i = 0; i < n; i++) printf("%d ", a[i].BB + 1);
    }
    else puts("impossible");
    return 0;
}
