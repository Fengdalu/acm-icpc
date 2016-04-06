#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

long long get(char s[3][3]) {
    long long tot = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            tot = tot * 3;
            if(s[i][j] == 'x') tot++;
            else if(s[i][j] == 'o') tot += 2;
        }
    return tot;
}
char res[3][3];
void de(int s) {
    stack<int>q;
    for(int i = 0; i < 9; i++) {
        q.push(s % 3);
        s /= 3;
    }
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            int x =  q.top();
            if(x == 0) res[i][j] = '.';
            else if(x == 1) res[i][j] = 'x';
            else if(x == 2) res[i][j] = 'o';
            q.pop();
        }
}
int next[20000];
int vis[20000];
char s[3][3];
int judge(char s[3][3]) {
    for(int i = 0; i < 3; i++)
    if(s[i][0] == 'x' && s[i][1] == 'x' && s[i][2] == 'x') return true;
    for(int i = 0; i < 3; i++)
    if(s[0][i] == 'x' && s[1][i] == 'x' && s[2][i] == 'x') return true;
    if(s[0][0] == 'x' && s[1][1] == 'x' && s[2][2] == 'x') return true;
    if(s[0][2] == 'x' && s[1][1] == 'x' && s[2][0] == 'x') return true;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        if(s[i][j] == '.') return -1;
    return false;
}
bool dfs(int d) {
    int flag = judge(s);
    long long tot = get(s);
    if(vis[tot] != -1) return vis[tot];
    if(flag != -1) { vis[tot] = flag; return flag; }
    else {
        vis[tot] = true;
        if(d & 1) {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                if(s[i][j] == '.') {
                    s[i][j] = 'o';
                    vis[tot] &= dfs(d ^ 1);
                    s[i][j] = '.';
                }
        }
        else {
            vis[tot] = false;
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                if(s[i][j] == '.') {
                    s[i][j] = 'x';
                    if(dfs(d ^ 1)) {
                        next[tot] = get(s);
                        vis[tot] = true;
                        s[i][j] = '.';
                        return true;
                    }
                    s[i][j] = '.';
                }
        }
    }
    return vis[tot];
}

char input[3][3];
char buf[10];
int main() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            s[i][j] = '.';
    memset(vis, -1, sizeof vis);
    dfs(0);
    while(true) {
        for(int i = 0; i < 3; i++) {
            scanf("%s", buf);
            s[i][0] = buf[0]; s[i][1] = buf[1]; s[i][2] = buf[2];
        }
        int count = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) {
                if(s[i][j] == 'x') count++;
            }
        if(count == 9) break;
        de(next[get(s)]);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++)
                printf("%c", res[i][j]);
            printf("\n");
        }
        fflush(stdout);
    }
    return 0;
}
