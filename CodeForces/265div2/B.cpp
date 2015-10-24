#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[2000];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    a[n] = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) ans += a[i];
    for(int i = 0; i < n; i++)
    if(a[i] && a[i + 1] == 0) ans++;
    ans--;
    ans = max(0, ans);
    cout << ans << endl;
    return 0;
}
