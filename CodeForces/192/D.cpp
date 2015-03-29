#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1010

struct obj
{
    int x, y;
}q[N * N];

char s[N][N];
bool f[N][N];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i] + 1;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++)
        if(i == 0 || i != n || j == 0 || j != m) s[i][j] = 'T';

}
