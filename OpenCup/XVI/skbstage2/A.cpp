#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <algorithm>
#include <queue>

const int maxn = 3010;
char s[maxn][maxn];
struct node {
    int type;
    int x;
    char c;
    node(int type, int x, char c) : type(type), x(x), c(c){}
    node(){}
}ans[maxn * 3];
bool vis['z' + 1];
bool vd[maxn], rd[maxn];
int ch[maxn]['z' + 1], cv[maxn]['z' + 1];
int th[maxn], tv[maxn];
int cnt;
int n;

int main() {
    //freopen("A.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if(s[i][j] != '?'){
            ch[i][s[i][j]]++;
            cv[j][s[i][j]]++;
        }
    std::queue< node >q;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        char p;
        for(char c = 'a'; c <= 'z'; c++)
            if(ch[i][c]) {
                cnt++;
                p = c;
            }
        th[i] = cnt;
        if(th[i] == 1) {
            q.push(node(0, i, p));
            rd[i] = true;
        }
    }
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        char p;
        for(char c = 'a'; c <= 'z'; c++)
            if(cv[i][c]) {
                cnt++;
                p = c;
            }
        tv[i] = cnt;
        if(tv[i] == 1) {
            q.push(node(1, i, p));
            vd[i] = true;
        }
    }
    int tot = 0;
    while(q.size()) {
        node p = q.front();
        int x = p.x;
        ans[tot++] = p;
        //std::cout << p.type << " " << p.x << " " << p.c << std::endl;
        q.pop();
        if(p.type == 0) {
            for(int j = 1; j <= n; j++)
            if(s[x][j] != '?') {
                cv[j][s[x][j]]--;
                if(cv[j][s[x][j]] == 0) {
                    tv[j]--;
                    if(tv[j] == 1 && !vd[j]) {
                        vd[j] = true;
                        char p;
                        for(p = 'a'; p <= 'z'; p++)
                            if(cv[j][p]) break;
                        q.push(node(1, j, p));
                    }
                }
            }
        }
        if(p.type == 1) {
            for(int i = 1; i <= n; i++)
            if(s[i][x] != '?') {
                ch[i][s[i][x]]--;
                if(ch[i][s[i][x]] == 0) {
                    th[i]--;
                    if(th[i] == 1 && !rd[i]) {
                        rd[i] = true;
                        char p;
                        for(p = 'a'; p <= 'z'; p++)
                            if(ch[i][p]) break;
                        q.push(node(0, i, p));
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    if(!rd[i]) {
        ans[tot].x = i;
        ans[tot].c = 'a';
        ans[tot].type = 0;
        tot++;
    }
    for(int i = 1; i <= n; i++)
    if(!vd[i]) {
        ans[tot].x = i;
        ans[tot].c = 'a';
        ans[tot].type = 1;
        tot++;
    }
    //std::cout << std::endl;
    std::reverse(ans, ans + tot);
    for(int i = 0; i < tot; i++) {
        if(ans[i].type == 0) printf("h %d %c", ans[i].x, ans[i].c);
        else printf("v %d %c", ans[i].x, ans[i].c);
        puts("");
    }
}