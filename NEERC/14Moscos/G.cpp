#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
#define MOD 1000000009
typedef long long LL;
typedef pair<LL, string> obj;
map<LL, int>H;
pair<LL, string> s[100010];
char buf[10000];
int ind[100010];
char name1[100010], name2[100010];
int last[100010];
int c[100010];
int cc;
int nt[200010], t[200010];
int n;
int tot;

LL conv(char x){
    if('a' <= x && x <= 'z') return x - 'a';
    else return x - 'A' + 26;
}

LL Hash(string s) {
    LL ans = 0;
    for(int i = 0; i < s.length(); i++) {
        ans *= 61;
        ans += conv(s[i]);
    }
    return ans;
}

int cmp(int i, int j){
    if(s[i].AA == s[j].AA) return s[i].BB.length() < s[j].BB.length();
    return s[i].AA < s[j].AA;
}

int get(const string &s){
    if(H.find(Hash(s)) == H.end()) H[Hash(s)] = ++cc;
    return H[Hash(s)];
}

void add(int a, int b)
{
    cout << a << " " << b << endl;
    t[tot] = b;
    nt[tot] = last[a];
    last[a] = tot++;
    c[b]++;
}

int dfs(int x) {
    int ans = 0;
    for(int k = last[x]; k != -1; k = nt[k]) cmax(ans, dfs(t[k]));
    return ans + 1;
}


int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    gets(buf);
    for(int i = 0; i < n; i++) {
        ind[i] = i;
        gets(buf);
        s[i].BB = string(buf);
        for(int j = 0; j < s[i].BB.length(); j++) {
            if(s[i].BB[j] == ' ') {
                s[i].AA = Hash(s[i].BB.substr(0, j + 1));
                s[i].BB = s[i].BB.substr(j + 1);
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) ind[i] = i;
    sort(ind, ind + n, cmp);
    cc = 0;
    H.clear();
    int ans = 0;
    memset(last, -1, sizeof last);
    tot = 0;
    int pre = 0;
    memset(c, 0, sizeof c);
    for(int p = 0; p < n; p++) {
        if(s[ind[p]].AA != s[ind[p - 1]].AA) {
            for(int j = 1; j <= cc; j++) if(c[j] == 0) {
                add(0, j);
            }
            cmax(ans, dfs(0) - 2);
            for(int j = 0; j <= cc; j++) last[j] = -1;
            tot = 0;
            for(int j = 0; j <= cc; j++) c[j] = 0;
            cc = 0;
            cout << endl;
            H.clear();
        }
        sscanf(s[ind[p]].BB.c_str(), "%s son of %s", name1, name2);
        add(get(string(name2)), get(string(name1)));
    }
    for(int j = 1; j <= cc; j++) if(c[j] == 0) {
        add(0, j);
    }
    cmax(ans, dfs(0) - 2);
    printf("%d\n", ans);
}
