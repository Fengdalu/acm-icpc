#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define N 100010
#define AA first
#define BB second
#define LL long long

typedef pair< int, PII > PPP;
PPP e[N];
int cnt[N];
int f[N];

int find(int x)
{
    if(f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}

void un(int x, int y)
{
    int c = cnt[find(x)];
    f[find(x)] = find(y);
    cnt[find(y)] += c;
}

int n, m;
int c[N];
char buf[100];


int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        e[i] = MP(-min(c[x], c[y]), MP(x, y));
    }
    for(int i = 1; i <= n; i++) f[i] = i;
    memset(cnt, 0, sizeof cnt);
    for(int i = 1; i <= n; i++) cnt[i] = 1;
    sort(e, e + m);
    LL sum = 0;
    for(int i = 0; i < m; i++) e[i].AA = abs(e[i].AA);
    for(int i = 0; i < m; i++)
    if(find(e[i].BB.AA) != find(e[i].BB.BB))
    {
        sum += (LL)cnt[find(e[i].BB.AA)] * cnt[find(e[i].BB.BB)] * e[i].AA;
        un(e[i].BB.AA, e[i].BB.BB);
    }
    else
    {
        //sum += e[i].AA;
        //cout << sum << endl;
    }
//    cout << sum << endl;
    sum *= 2LL;
    sprintf(buf, "%.15f\n", (double)sum / n / (n - 1));
    cout << buf;
    return 0;

}

