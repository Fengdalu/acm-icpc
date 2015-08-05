#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define AA first
#define BB second
#define LL long long

int vis[200020];
int n, K, a, h;
int p[200020];
set<int>s;
set<int>::iterator iter;

bool chk(int x)
{
//    cout << "CHK " << x << endl;
    for(int i = 1; i <= n; i++) vis[i] = false;
    for(int i = 0; i <= x; i++) vis[p[i]] = true;
    int k = 1;
    int c = K;
    while(c && k <= n)
    {
        int p = 0;
        while(k <= n && !vis[k]) { k++; p++; }
//        cout << k << " " << p + 1 << endl;
        c -= (p + 1) / (a + 1);
        k++;
    }
   // cout << "C " << c << endl;
    if(c <= 0) return false;
    return true;
}

int main()
{
    scanf("%d%d%d", &n, &K  , &a);
    scanf("%d", &h);
    for(int i = 0; i < h; i++)
    {
        scanf("%d", &p[i]);
    }
    int l = 0, r = h - 1;
    while(l < r - 1)
    {
        int mid = (l + r) / 2;
        if(chk(mid)) r = mid;
        else l = mid + 1;
    }
    if(chk(l)) printf("%d\n", l + 1);
    else if(chk(r)) printf("%d\n", r + 1);
    else printf("-1\n");
    return 0;
}
