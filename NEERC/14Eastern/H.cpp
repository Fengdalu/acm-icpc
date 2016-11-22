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
int cnt[10010];
int n;

inline bool Up(char s) { return 'A' <= s && s <= 'Z'; }
inline bool cmp(char a, char b) { return toupper(a) == toupper(b); }

int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int cc = 1;
    dp.clear();
    for(int i = 1; i <= 2 * n; i++) if(!Up(s[i])){
        cnt[i] = cc++;
    }

    memset(f, 0, sizeof f);
    for(int i = 1; i <= 2 * n; i++) {
        int p = -1;
        for(int j = 1; j <= 2 * n; j++) if(!f[j]) {
            if(p == -1) { p = j; }
            else{
                if( cmp(s[j], s[p]) && ( Up(s[j]) ^ Up(s[p]) ) ) {
                    f[p] = j;
                    f[j] = p;
                    p = -1;
                } else {
                    p = j;
                }
            }
        }
    }

    bool flg = false;
    for(int i = 1; i <= 2 * n; i++) if(f[i] == 0) flg = true;

    if(!flg) {
        for(int i = 1; i <= 2 * n; i++) if(Up(s[i])) printf("%d ", cnt[f[i]]);
    } else {
        puts("Impossible");
    }
    return 0;
}
