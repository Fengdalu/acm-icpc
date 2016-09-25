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
#define Maxn 411111
#define Maxm 411111
char S[Maxn], T[Maxn];
int next[Maxn], is[Maxn];
int LT, LS;
void getnext() {
    int i, j;
    next[0]=-1; next[1] = 0;
    for (i = 1, j = 0; i < LT; ) {
        while (j != -1 && T[i] != T[j]) j = next[j];
        i++; j++;
        next[i] = j;
    }
}
void kmp() {
    int i, j;
    for(i = 0; i < LS; i++) is[i] = 0;
    for (i = 0, j = 0; i < LS; i++) {
        while (j != -1 && S[i] != T[j]) j = next[j];
        j++;
        if (j == LT) {
            is[i - LT + 1] = 1;
            j = next[j];
        }
    }
}

int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    vector<int> ans;
    while(scanf("%s", T) != EOF) {
        LT = strlen(T);
        getnext();
        ans.clear();
        for(i = LT; next[i] != -1; i = next[i]) {
            ans.PB(i);
        }
        reverse(ans.BG, ans.ED);
        printf("%d", ans[0]);
        for(i = 1; i < ans.SZ; i++) {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

