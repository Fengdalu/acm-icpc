#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define NAME ""

vector<PII> g;

int main() {
    int i, j;
    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    int n;
    while(cin >> n) {
        g.clear();
        for(i = 1; i <= n; i++) {
            cin >> j;
            g.PB(MP(j, i));
        }
        sort(g.BG, g.ED);
        i = 0;
        for(j = 1; j < g.SZ; j++) {
            if(g[j].AA == g[0].AA) i++;
        }
        if(i == 0) cout << g[0].BB << endl;
        else cout << "Still Rozdil" << endl;
    }
    return 0;
}
