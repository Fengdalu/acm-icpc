#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define cmax(x, y) x = max(x, y)
int s[100100];
int n, k;
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> s[i];
    if(k >= n) { cout << s[n - 1] << endl; return 0; }
    int m = 2 * (n - k);

    for(int i = 0; i < m; i++)
    {
        cmax(ans, s[i] + s[m - i - 1]);
    }
    for(int i = m; i < n; i++) cmax(ans, s[i]);
    cout << ans << endl;
    return 0;
}
