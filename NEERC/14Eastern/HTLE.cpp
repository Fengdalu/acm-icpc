#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
#define AA first
#define BB second
#define PII pair<int, int>
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define SZ size
#define OP begin()
#define ED end()

map<PII, bool>dp;
vector<int>Big[27];
vector<int>Small[27];
int f[10001];
char s[10010];
int c[10010];
int n;

inline bool Up(char s) { return 'A' <= s && s <= 'Z'; }
inline bool cmp(char a, char b) { return toupper(a) == toupper(b); }

bool dfs(int a, int b) {
    if((b - a + 1) & 1) return false;
    if( 2 * (c[b] - c[a - 1]) != b - a + 1 ) return false;
    //cout << a << " " << b << endl;
    if(b < a) return true;
    if(dp.find(PII(a, b)) != dp.end()) return dp[PII(a, b)];

    if(Up(s[a])) {
        vector<int> &Q = Small[s[a] - 'A'];
        int L = lower_bound(Q.OP, Q.ED, a + 1) - Q.OP;
        int R = upper_bound(Q.OP, Q.ED, b) - Q.OP;
        for(int i = L; i < R; i++) if( dfs(a + 1, Q[i] - 1) && dfs(Q[i] + 1, b) ) {
            f[a] = Q[i];
            f[Q[i]] = a;
            dp[PII(a, b)] = true;
            return true;
        }
    }
    else {
        vector<int> &Q = Big[s[a] - 'a'];
        int L = lower_bound(Q.OP, Q.ED, a + 1) - Q.OP;
        int R = upper_bound(Q.OP, Q.ED, b) - Q.OP;
        for(int i = L; i < R; i++) if( dfs(a + 1, Q[i] - 1) && dfs(Q[i] + 1, b) ) {
            f[a] = Q[i];
            f[Q[i]] = a;
            dp[PII(a, b)] = true;
            return true;
        }

    }
    dp[PII(a, b)] = false;
    return false;
}

int cnt[10010];

int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int cc = 1;
    dp.clear();
    for(int i = 1; i <= 2 * n; i++) if(!Up(s[i])){
        cnt[i] = cc++;
    }
    for(int i = 1; i <= 2 * n; i++)
        if(Up(s[i])) Big[s[i] - 'A'].PB(i);
        else Small[s[i] - 'a'].PB(i);

    memset(c, 0, sizeof c);
    for(int i = 1; i <= 2 * n; i++) c[i] = c[i - 1] + (int)(Up(s[i]));
    if(dfs(1, 2 * n)) {
        for(int i = 1; i <= 2 * n; i++) if(Up(s[i])) printf("%d ", cnt[f[i]]);
    } else {
        puts("Impossible");
    }
    return 0;
}
