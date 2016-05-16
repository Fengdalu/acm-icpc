#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long a[100010];
int n;
int main() {
    int ans = 1e9;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    long long tot = 0;
    int s = 0;
    int st = 0;
    for(int i = 0; i < n; i++)
        if(a[i] == 0) {
            st = i;
            break;
        }
    for(int i = 0; i < n; i++) {
        if(tot) s++;
        tot += a[(i + st) % n];
    }
    ans = s;
    cout << ans << endl;
}
