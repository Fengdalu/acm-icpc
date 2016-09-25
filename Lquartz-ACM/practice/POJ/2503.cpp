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
const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 1111
#define Maxm 111111
map<int, int> mp;
char g[100000 +10][11];
LL Hash(char str[]) {
    LL ret = 0;
    for(int i = 0; str[i]; i++) ret = (ret * 31 + str[i] - 'a' + 1) % MOD;
    return ret;
}
char ss[100], s1[20], s2[20];
int main() {
    int i, j, u, v, w, ca;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    mp.clear();
    ca = 1;
    while(true) {
        gets(ss);
        u = strlen(ss);
        if(u == 0) break;
        for(i = 0; ss[i] != ' '; i++) {
            s1[i] = ss[i];
        }
        s1[i] = '\0';
        for(j = 0, i++; ss[i]; i++, j++) {
            s2[j] = ss[i];
        }
        mp[Hash(s2)] = ca;
        s2[j] = '\0';
        strcpy(g[ca++], s1);
    }
    while(gets(ss) != NULL) {
        int i = Hash(ss);
        if(mp[i] == 0) printf("eh\n");
        else printf("%s\n", g[mp[i]]);
    }
    return 0;
}

