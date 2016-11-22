#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[10000];
int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    int cc = n / k;
    int ans = 0;
    for(int i = 1; i <= k; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        if(a[j] == i) cnt++;
        ans += abs(cnt - cc);
    }
    cout << ans / 2 << endl;
    return 0;
}
