#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long

int a[100010];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    LL ans = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] < a[i - 1]) ans += (LL)a[i - 1] - (LL)a[i];
    }
    cout << ans << endl;
    return 0;
}
