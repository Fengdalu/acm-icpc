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
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;
vector <int> g[30];
int lowbit(int x) {
    for(int i = 0; i < 30; i++) {
        if(x & (1 << i)) {
            return i;
        }
    }
    return -1;
}

int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int n, limit;
    while(cin >> n >>limit) {
        for(i = 0; i < 30; i++) g[i].clear();
        for(i = 1; i <= limit; i++) g[lowbit(i)].PB(i);
        int flag;
        vector<int> ans;
        int now = 0;
        for(i = 20; i >= 0; i--) {
            int t = 1 << i;
            for(j = 0; j < g[i].SZ; j++) {
                if(now + t > n ) break;
                else {
                    now += t;
                    ans.PB(g[i][j]);
                }
            }
        }
        if(now == n) {
            printf("%d\n", ans.SZ);
            for(i = 0; i < ans.SZ; i++) {
                if(i) printf(" ");
                printf("%d", ans[i]);
            }
        } 
        else {
            printf("-1\n");
        }
    }
    return 0;
}
