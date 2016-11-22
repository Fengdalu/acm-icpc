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

int bit(int x)
{
    int cnt = 0;
    while(x) { cnt++; x /= 10; }
}

int main()
{
    LL n, t; cin >> n >> t;
    if(n == 1 && t == 10) { cout << -1 <<  endl; return 0; }
    if(t != 10)
    {
        cout << t;
        n--;
        while(n--) cout << 0;
        return 0;
    }
    cout << 1; n--;
    while(n--) cout << 0;
    return 0;
}
