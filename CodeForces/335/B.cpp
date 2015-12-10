#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define SZ size()
#define OP begin()
#define ED end()
#define LL long long

int n, m, x, y;
char s[100010];
int tot;
bool vis[1000][1000];

int main() {
    tot = 0;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    scanf("%s", s);
    int len = strlen(s);
    printf("1 "); tot++;
    vis[x][y] = true;
    for(int i = 0; i < len - 1; i++) {
        bool flg = false;
        if(s[i] == 'R') {
            if(y + 1 > m) { if(i != len - 1) printf("0 "); else {printf("0"); return 0;} }
            else {
                y++;
                if(i != len - 1) {
                    if(!vis[x][y])printf("1 ");
                    else printf("0 ");
                    vis[x][y] = true;
                }
                flg = true;
            }
        }
        else if(s[i] == 'L') {
            if(y - 1 < 1) { if(i != len - 1) printf("0 "); else {printf("0"); return 0;} }
            else {
                tot++;
                y--;
                if(i != len - 1) {
                    if(!vis[x][y])printf("1 ");
                    else printf("0 ");
                    vis[x][y] = true;
                }
                flg = true;
            }
        }
        else if(s[i] == 'U') {
            if(x - 1 < 1) { if(i != len - 1) printf("0 "); else {printf("0"); return 0;} }
            else {
                tot++;
                x--;
                if(i != len - 1) {
                    if(!vis[x][y])printf("1 ");
                    else printf("0 ");
                    vis[x][y] = true;
                }
                flg = true;
            }
        }
        else if(s[i] == 'D') {
            if(x + 1 > n) { if(i != len - 1) printf("0 "); else {printf("0"); return 0;} }
            else {
                tot++;
                x++;
                if(i != len - 1) {
                    if(!vis[x][y])printf("1 ");
                    else printf("0 ");
                    vis[x][y] = true;
                }
                flg = true;
            }
        }
    }
    tot = 0;
        for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++)
                if(vis[i][j]) tot++;
            printf("%d", n * m - tot);
//        cout << endl << "X Y " << x << " " << y << endl;

    return 0;
}
