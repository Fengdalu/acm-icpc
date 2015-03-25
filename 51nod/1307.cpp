#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int f[200000];
int a[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> f[i];
    memcpy(a, f, sizeof f);
    sort(f, f + n);
    int x = f[0];
    if(n >= 2 && f[1] == x) cout << "Still Rozdil" << endl;
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(a[i] == x)
            {
                cout << i + 1 <<endl;
                break;
            }
        }
    }
    return 0;
}
