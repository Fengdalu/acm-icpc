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
const LL MOD = 1000000009;
const LL INF = 0x3f3f3f3f;
#define Maxn 111111
#define Maxm 111111
char S[Maxn], T[Maxn], s1[Maxn], s2[Maxn];
int next[Maxn], B1[Maxn], B2[Maxn];
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
int H1[Maxn], H2[Maxn], need[Maxn];
int ls, lt;
void ready() {
    int i, j;
    H1[0] = s1[0] - 'a' + 1;
    H2[0] = s2[0] - 'a' + 1;
    for(i = 1; i < ls; i++) {
        H1[i] = (int)((31LL * H1[i - 1] + s1[i] - 'a' + 1) % MOD);
    }
    for(i = 1; i < lt; i++) {
        H2[i] = (int)((31LL * H2[i - 1] + s2[i] - 'a' + 1) % MOD);
    }
}
int geth1(int l, int r) {
    int k = r - l + 1;
    int p = (l == 0 ? 0 : H1[l - 1]);
    //printf("\tl=%d r=%d %d %d %d\t",l,r,H1[l-1],H1[r],need[k]);
    return ((LL)H1[r] - 1LL * p * need[k] % MOD + MOD) % MOD;
}
int geth2(int l, int r) {
    int k = r - l + 1;
    int p = (l == 0 ? 0 : H2[l - 1]);
    return ((LL)H2[r] - 1LL * p * need[k] % MOD + MOD) % MOD;
}
int main() {
    int i, j, u, v, w;
    int l, r, ll, rr;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    need[i] = 1;
    for(i = 1; i < Maxn; i++) {
        need[i] = (int)((31LL * need[i - 1])%MOD);
    }
    for(int ca = 1; ca <= te; ca++) {
        scanf("%s%s", s1, s2);
        ls = strlen(s1); lt = strlen(s2);
        ready();
//        for(i = 0; i < ls; i++) cout << H1[i] << " "; cout << endl;
//        for(i = 0; i < ls; i++) {
//            for(j = i; j < ls; j++){
//                cout << "(" << i << ", " << j << ") ";
//                for(u = i; u <= j; u++) cout << s1[u]; 
//                cout << " \t" << geth1(i, j) <<endl;
//            }
//        }
        exKmp(s1, ls, s2, lt, next, B1);
        reverse(s1, s1 + ls);
        reverse(s2, s2 + lt);
        exKmp(s1, ls, s2, lt, next, B2);
        reverse(B2, B2 + ls);
//        for(i = 0; i < ls; i++) cout << B1[i] << " "; cout << endl;
//        for(i = 0; i < ls; i++) cout << B2[i] << " "; cout << endl;
        int ans = -1;
        for(i = 0; i < ls; i++) {
            j = i + lt - 1;
            if(j >= ls) break;
            l = i + B1[i], r = j - B2[j];
            ll = 0 + B1[i] , rr = lt - 1 - B2[j];
//            printf("(%d, %d) (%d, %d) (%d, %d) \n", i, j, l, r, ll, rr);
            if(l >= r) {
                ans = i;
                break;
            }
            else {
                if(geth1(l + 1, r - 1) == geth2(ll + 1, rr - 1)){
                    ans = i;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}

/*
100
aaabcd
abee

aaaaaa
aaaaa

aaaaaa
aabbb

aaabaa
bbb
*/
