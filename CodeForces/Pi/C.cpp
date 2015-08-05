#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define AA first
#define BB second
#define LL long long

map<LL, int>f;
map<LL, int>::iterator iter;
int c1[200010], c2[200010];
int x[200010];
int n, k;

int main()
{
    f.clear();
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &x[i]);
    LL ans = 0;
    memset(c1, 0, sizeof c1);
    memset(c2, 0, sizeof c2);
    for(int i = 0; i < n; i++)
    {

//        cout << (f.find(x / k) != f.end()) << " ";
//        cout << (f.find((x / k) / k) != f.end()) << endl;
        if(x[i] % k == 0 && f.find((LL)x[i] / k) != f.end())
        {
            c1[i] += f[(LL)x[i] / k];
        }
        f[x[i]]++;
    }
    f.clear();
    for(int i = n - 1; i > -1; i--)
    {

//        cout << (f.find(x / k) != f.end()) << " ";
//        cout << (f.find((x / k) / k) != f.end()) << endl;
        if(f.find((LL)x[i] * k) != f.end())
        {
            c2[i] = f[(LL)x[i] * k];
        }
        f[x[i]]++;
    }
    for(int i = 0; i < n; i++) ans += (LL)c1[i] * c2[i];
    printf("%I64d\n", ans);
    return 0;
}
