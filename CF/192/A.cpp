#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char s[100][100];
bool r[100], c[100];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    memset(r, 0, sizeof r);
    memset(c, 0, sizeof c);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        if(s[i][j] == 'S') r[i] = c[j] = true;
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        if(s[i][j] != 'S' && (!r[i] || !c[j])) ans++;
    cout << ans << endl;
    return 0;
}
