#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


int c[2000];

int main()
{
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> c[i];
    int s = 0;
    for(int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        s += min(c[x], c[y]);
    }
    cout << s << endl;
    return 0;
}
