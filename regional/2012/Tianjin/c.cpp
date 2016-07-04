#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 1e7;
char s1[1010], s2[1010];
int f[1010][10][10][10];
int n;

int dfs(int x, int a, int b, int c) {
    if(x == n - 1) {
        int num = s2[x] - '0';
        int t1 = num - a;
        if(t1 < 0) t1 += 10;
        int add = min(t1, 10 - t1);
        return add;
    }
    if(x == n - 2) {
        int num = s2[x] - '0';
        int ans;
        int t1;
        t1 = num - a;
        if(t1 < 0) t1 += 10;
        ans = dfs(x + 1, (b + t1) % 10, -1, -1) + t1;
        for(int i = 0; i <= t1; i++)
            ans = min(ans, dfs(x + 1, (b + i) % 10, -1, -1) + t1);

        t1 = a - num;
        if(t1 < 0) t1 += 10;
        for(int i = 0; i <= t1; i++) {
            int b1 = b - i;
            if(b1 < 0) b1 += 10;
            ans = min(ans, dfs(x + 1, b1, -1, -1) + t1);
        }
        return ans;
    }

    if(f[x][a][b][c] != -1) return f[x][a][b][c];
    int &t = f[x][a][b][c];
    int num = s2[x] - '0';

    int t1;
    t1 = num - a;
    if(t1 < 0) t1 += 10;
    int y = s1[x + 3] - '0';
    t = dfs(x + 1, (b + t1) % 10, (c + t1) % 10, y) + t1;

    for(int i = 0; i <= t1; i++)
        for(int j = 0; j <= i; j++) {
            t = min(t, dfs(x + 1, (b + i) % 10, (c + j) % 10, y) + t1);
        }

    t1 = a - num;
    if(t1 < 0) t1 += 10;
    for(int i = 0; i <= t1; i++)
        for(int j = 0; j <= i; j++) {
            int b1 = b - i;
            int c1 = c - j;
            if(b1 < 0) b1 += 10; if(c1 < 0) c1 += 10;
            t = min(t, dfs(x + 1, b1, c1, y) + t1);
        }
    return t;
}

int main() {
    while(~scanf("%s%s", s1, s2)) {
        n = strlen(s1);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 10; j++)
                for(int k = 0; k < 10; k++)
                    for(int p = 0; p < 10; p++)
                        f[i][j][k][p] = -1;
        printf("%d\n", dfs(0, s1[0] - '0', s1[1] - '0', s1[2] - '0'));
    }
    return 0;
}
