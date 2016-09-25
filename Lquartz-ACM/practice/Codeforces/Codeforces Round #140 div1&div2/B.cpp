//#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define Maxn 111111
int n, m;
int a[Maxn];
int b1[Maxn], b2[Maxn];

int main() {
    int i, j, k, u, v, w;
    while(cin >> n) {
        for(i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(i = 1; i <= n; i++) {
            b1[a[i]] = i;
            b2[a[i]] = n - i + 1;
        }
        cin >> m;
        LL ans1 = 0, ans2 = 0;
        for(i = 0; i < m; i++) {
            cin >> w;
            ans1 += b1[w];
            ans2 += b2[w];
        }
        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}
