#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int c[2000];

int main()
{
    ios::sync_with_stdio(false);
    memset(c, 0, sizeof c);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        c[a]++; c[b]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(c[i] == 0)
        {
            cout << n - 1 << endl;
            for(int j = 1; j <= n; j++)
            if(i != j)
                cout << i << " " << j << endl;
            return 0;
        }
    }
}
