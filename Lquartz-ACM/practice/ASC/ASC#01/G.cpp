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
#define Maxn 111111
vector<pair<PII, int> > g;
int pre[Maxn];
int gao[Maxn];
int now[Maxn];
int high;
int n;
stack<int> ans;
int getmid(int o) {
    int b = -g[o].AA.BB;
    int l = 0, r = high;
    while(l != r) {
        int mid = (l + r) >> 1;
        if(now[mid] > b) r = mid - 1;
        else if(now[mid] <= b && now[mid + 1] > b) return mid;
        else l = mid + 1;
    }
    return l;
}
int main() {
    int i, j, s, b;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int Test;
    scanf("%d", &Test);
    for(int Ca = 1; Ca <= Test; Ca++) {
        scanf("%d", &n);
        g.clear();
        g.PB(MP(MP(0, 0), 0));
        for(i = 1; i <= n; i++) {
            scanf("%d%d", &s, &b);
            g.PB(MP(MP(s, -b), i));
            pre[i] = -1;
        }
        sort(g.BG, g.ED);
        high = 0;
        now[high + 1] = -1;
        now[0] = 0;
        gao[0] = -1;
        for(i = 1; i <= n; i++) {
            int m = getmid(i);
//            cout << high << " ~ " << m << endl;
            if(-g[i].AA.BB > now[m]) {
                if(high == m) {
                    high++;
                    now[high] = -g[i].AA.BB;
                    now[high + 1] = -1;
                    gao[high] = g[i].BB;
                    pre[g[i].BB] = gao[high - 1];
                }
                else if(now[m + 1] > -g[i].AA.BB){
                    now[m + 1] = -g[i].AA.BB;
                    gao[m + 1] = g[i].BB;
                    pre[g[i].BB] = gao[m];
                }
            }
        }
        if(Ca > 1) printf("\n");
        printf("%d\n", high);
        while(!ans.empty()) ans.pop();
        s = gao[high];
        while(s != -1) {
//            cout << "~ " << s << endl;
            ans.push(s);
            s = pre[s];
        }
        for(i = 0; !ans.empty(); i++) {
            if(i) printf(" ");
            printf("%d", ans.top());
            ans.pop();
        }
        printf("\n");
        
    }
    return 0;
}

