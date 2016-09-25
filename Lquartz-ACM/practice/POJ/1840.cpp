#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
 
#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 100000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 25000007
#define Maxm 12500001
char cnt[Maxn];
int san[1000];
int a1, a2, a3, a4, a5;
int main() {
//    cout << sizeof(short) << endl;
    int i, j, k, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    for(i = -50; i <= 50; i++) san[i + 100] = i * i * i;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
    for(i = -50; i <= 50; i++) {
        if(i == 0) continue;
        for(j = -50; j <= 50; j++) {
            if(j == 0) continue;
            u = a4 * san[i + 100] + a5 * san[j + 100];
            cnt[u + Maxm]++;
        }
    }
    int ans = 0;
    for(i = -50; i <= 50; i++) {
        if(i == 0) continue;
        for(j = -50; j <= 50; j++) {
            if(j == 0) continue;
            for(k = -50; k <= 50; k++) {
                if(k == 0) continue;
                u = a1 * san[i + 100] + a2 * san[j + 100] + a3 * san[k + 100];
                if(u < Maxm && u > -Maxm){ans += cnt[-u + Maxm];}
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
