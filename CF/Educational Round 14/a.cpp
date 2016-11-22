#include <bits/stdc++.h>
using namespace std;

int a[1001];
int main() {
    int n;
    cin >> n;
    bool flag = false;
    for(int i = 0; i < n; i++) cin >> a[i];
    int t = 0;
    for(int i = 0; i < n; i++) t += a[i];
    if(t == n - 1) flag = true;
    if(n == 1) flag = (a[0] == 1);
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}
