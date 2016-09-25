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
#define Maxn 1111111
#define Maxm 1111111
char S[Maxn], T[Maxn];
int next[Maxn], B[Maxn];
void preExKmp(char T[], int LT, int next[]) {
    int i, ind = 0, k = 1;
    next[0] = LT;
    while(ind + 1 < LT && T[ind + 1] == T[ind]) ind++;
    next[1] = ind;
    for(i = 2; i < LT; i++) {
        if(i <= k + next[k] - 1 && next[i - k] + i < k + next[k])
            next[i] = next[i - k];
        else {
            ind = max(0, k + next[k] - i);
            while(ind + i < LT && T[ind + i] == T[ind]) ind++;
            next[i] = ind; k = i;
        }
    }
}

void exKmp(char S[], int LS, char T[], int LT, int next[], int B[]) {
    int i, ind = 0, k = 0;
    preExKmp(T, LT, next);
    while(ind < LS && ind < LT && T[ind] == S[ind]) ind++;
    B[0] = ind;
    for(i = 1; i < LS; i++) {
        int p = k + B[k] - 1, L = next[i - k];
        if((i - 1) + L < p)
            B[i] = L;
        else {
            ind = max(0, p - i + 1);
            while(ind + i < LS && ind < LT && S[ind + i] == T[ind]) ind++;
            B[i] = ind;
            k = i;
        }
    }
}

int main() {
    int i, j, u, v, w;
    int lt, ls;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    while(te--) {
        scanf("%s%s", T, S);
        exKmp(S, ls = strlen(S), T, lt = strlen(T), next, B);
//        for(i = 0; i < ls; i++) cout << B[i] << " "; cout << endl;
//        for(i = 0; i < lt; i++) cout << next[i] << " "; cout << endl;
        int ans = 0;
        for(i = 0; i < ls; i++) if(B[i] == lt) ans++;
        printf("%d\n", ans);
    }
    return 0;
}

