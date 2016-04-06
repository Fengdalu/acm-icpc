#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;


int a[4][4], b[4][4], c[4][4];
bool vis[16];
int p1[4], p2[4];
struct obj {
    int a, b, c;
    obj(){};
    obj(int a, int b, int c): a(a), b(b), c(c){}
};
queue<obj>ans;
int sum;
int main() {
    //freopen("G1.in", "r", stdin);
    //freopen("G.out", "w", stdout);
    freopen("puzzle-swap-plus.in", "r", stdin);
    freopen("puzzle-swap-plus.out", "w", stdout);
    sum = 1e9;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            scanf("%d", &c[i][j]);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            c[i][j]--;

    for(int i = 0; i < 4; i++) p1[i] = i;
    for(int i = 0; i < 4; i++) p2[i] = i;

    bool flag = true;
    do{
        do{
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    b[i][j] = c[p1[i]][p2[j]];
            queue<obj>q;
            int tot = 0;
            memset(vis, 0, sizeof vis);
            for(int i = 0; i < 4; i++)
            if(p1[i] != i && !vis[i]) {
                int x = i;
                while(!vis[x]) {
                    if(!vis[p1[x]]) {
                        q.push(obj(0, x, p1[x]));
                        tot++;
                    }
                    vis[x] = true;
                    x = p1[x];
                }
            }

            memset(vis, 0, sizeof vis);
            for(int i = 0; i < 4; i++)
            if(p2[i] != i && !vis[i]) {
                int x = i;
                while(!vis[x]) {
                    if(!vis[p2[x]]) {
                        q.push(obj(1, x, p2[x]));
                        tot++;
                    }
                    vis[x] = true;
                    x = p2[x];
                }
            }

            memset(vis, 0, sizeof vis);
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                if(!vis[i * 4 + j] && b[i][j] != i * 4 + j) {
                    int x = i, y = j;
                    int t = b[i][j];
                    vis[i * 4 + j] = true;
                    while(!vis[t]) {
                        if(!vis[t]) {
                            tot++;
                            q.push(obj(2, x, y));
                            q.push(obj(2, t / 4, t % 4));
                        }
                        vis[t] = true;
                        t = b[t / 4][t % 4];
                    }
                }
            if(sum == -1 || tot < sum) {
                sum = tot;
                ans = q;
            }
        }while(next_permutation(p2, p2 + 4));
    }while(next_permutation(p1, p1 + 4));
    printf("%d\n", sum);
    while(ans.size()) {
        obj t = ans.front();
        ans.pop();
        if(t.a == 0) printf("%c-%c", 'a' + t.b, 'a' + t.c);
        else if(t.a == 1) printf("%d-%d", 1 + t.b, 1 + t.c);
        else {
            int x = t.b, y = t.c;
            t = ans.front();
            ans.pop();
            int a = t.b, b = t.c;
            printf("%c%d-%c%d", 'a' + x, y + 1, 'a' + a, b + 1);
        }
        puts("");
    }
    return 0;
}
