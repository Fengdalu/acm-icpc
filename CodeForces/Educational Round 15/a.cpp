#include <bits/stdc++.h>
using namespace std;

int a[100010];
int main() {
    int n;
    scanf("%d", &n);
    int ans = 1;
    int cur = 1;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 1; i < n; i++) {
        ans = max(ans, cur);
        if(a[i] > a[i - 1]) cur++;
        else cur = 1;
    }
    cout << max(ans, cur) << endl;
    return 0;
}
