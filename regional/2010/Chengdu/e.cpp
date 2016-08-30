#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP make_pair
typedef pair<PII, PII> state;
int s[10][10];
int g[10][10];
int dp[10][10][10][10];
char pre[10][10][10][10];
state pp[10][10][10][10];
const int VX[] = {0, -1, 1,  0};
const int VY[] = {1,  0, 0, -1};
const char D[] = {'D', 'L', 'R', 'U'};
const pair<PII, PII> ep = MP(PII(-1, -1), PII(-1, -1));
inline int get(state t) {
    return dp[t.AA.AA][t.AA.BB][t.BB.AA][t.BB.BB];
}

inline char getp(state t) {
    return pre[t.AA.AA][t.AA.BB][t.BB.AA][t.BB.BB];
}

inline void use(state t, int v) {
    dp[t.AA.AA][t.AA.BB][t.BB.AA][t.BB.BB] = v;
}

inline bool bl(int x, int y, int f[10][10]) {
    if(f[x][y] & 1) return true;
    else return false;
}

inline bool br(int x, int y, int f[10][10]) {
    if(1 << 2 & f[x][y]) return true;
    else return false;
}

inline bool bu(int x, int y, int f[10][10]) {
    if(1 << 3 & f[x][y]) return true;
    else return false;
}

inline bool bd(int x, int y, int f[10][10]) {
    if(1 << 1 & f[x][y]) return true;
    else return false;
}

inline bool hl(int x, int y, int f[10][10]) {
    if(x < 0 || x > 5 || y < 0 || y > 5) return true;
    if(1 << 4 & f[x][y]) return false;
    else return true;
}

inline state check(pair<PII, PII>t, int i) {
    int x = t.AA.AA, y = t.AA.BB, a = t.BB.AA, b = t.BB.BB;
    if(i == 0) {
        if(!bd(x, y, s)) x++;
        if(!bd(a, b, g)) a++;
    }
    if(i == 1) {
        if(!bl(x, y, s)) y--;
        if(!bl(a, b, g)) b--;
    }
    if(i == 2) {
        if(!br(x, y, s)) y++;
        if(!br(a, b, g)) b++;
    }
    if(i == 3) {
        if(!bu(x, y, s)) x--;
        if(!bu(a, b, g)) a--;
    }
    if(hl(x, y, s) || hl(a, b, g)) return ep;
    return MP(MP(x, y), MP(a, b));
}

inline void out(state g) {
    //cout << g.AA.AA << " " << g.AA.BB << " " << g.BB.AA << " " << g.BB.BB << endl;
}

inline void run(int _T) {
    swap(s, g);
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            scanf("%d", &g[i][j]);
    if(_T == 0) return;

    /*
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++)
            cout << s[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
    */

    memset(dp, -1, sizeof dp);
    queue< pair<PII, PII> >q;
    state op = ep;
    for(int i = 0; q.empty() && i < 6; i++)
        for(int j = 0; q.empty() && j < 6; j++)
            for(int k = 0; q.empty() && k < 6; k++)
                for(int p = 0; q.empty() && p < 6; p++)
                    if(1 << 5 & s[i][j]) if(1 << 5 & g[k][p]) {
                        q.push(MP(PII(i, j), PII(k, p)));
                        op = q.front();
                        dp[i][j][k][p] = 0;
                        pp[i][j][k][p] = ep;
                        pre[i][j][k][p] = 0;
                    }
    state ed = ep;
    for(int i = 0; i < 6 && ed == ep; i++)
        for(int j = 0; j < 6 && ed == ep; j++)
            for(int k = 0; k < 6 && ed == ep; k++)
                for(int p = 0; p < 6 && ed == ep; p++)
                    if(1 << 6 & s[i][j]) if(1 << 6 & g[k][p]) {
                        ed = MP(MP(i, j), MP(k, p));
                    }
    while(!q.empty()) {
        state t = q.front();
        q.pop();
        int x = get(t);
        for(int i = 0; i < 4; i++) {
            state g = check(t, i);
            if(g == ep) continue;
            if(get(g) != -1) continue;
            use(g, x + 1);
            pre[g.AA.AA][g.AA.BB][g.BB.AA][g.BB.BB] = D[i];
            pp[g.AA.AA][g.AA.BB][g.BB.AA][g.BB.BB] = t;
            q.push(g);
        }
    }
    if(get(ed) == -1) {
        puts("-1");
    }
    else {
        state k = ed;
        string ans = "";
        while(k != ep) {
            if(k != op) ans = getp(k) + ans;
            k = pp[k.AA.AA][k.AA.BB][k.BB.AA][k.BB.BB];
        }
        for(int i = 0; i < ans.size(); i++) printf("%c", ans[i]);
        puts("");
    }
}

int main() {
    int _T, _cas=0; scanf("%d", &_T);
    while(_T--) run(_cas++);
    return 0;
}
