#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <map>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()
#define LL long long
#define PB(x) push_back(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define u32 unsigned int
#define N 1000025

bool vis[N];
vector<int>f;

bool init()
{
    memset(vis, 0, sizeof vis);
    for(int i = 2; i < N; i++)
    {
        if(!vis[i]) f.PB(i);
        FOR(j, f.SZ)
        {
            if(f[j] * i >= N) break;
            vis[f[j] * i] = true;
            if(i % f[j] == 0) break;
        }
    }
}


bool chk(int x)
{
    if(x == 1) return false;
    if(x == 2 || x == 3) return true;
    for(int i = 2; i * i <= x; i++)
    if(x % i == 0) return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    if(n == 2) cout << 1 << endl << 2;
    else if(n == 3) cout << 1 << endl << 3 << endl;
    else if(n == 4) cout << 2 << endl << 2 << " " << 2 << endl;
    else if(n == 5) cout << 2 << endl << 2 << " " << 3 << endl;
    else if(n == 6) cout << 2 << endl << 3 << " " << 3 << endl;
    else if(n == 7) cout << 2 << endl << 5 << " " << 2 << endl;
    else
    {
        init();
        cout << 3 << endl << 3 << " "; n -= 3;
        FOR(i, f.SZ) if(chk(n - f[i]))  { cout << f[i] << " " << n - f[i] << endl; break; }
    }
    return 0;
}

