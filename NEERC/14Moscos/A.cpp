#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 105;
#define LL long long
int f[N][N];
int n;
deque<int>q;
char buf[10];

void output() {
    /*
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) printf("%d ", f[i][j]);
        printf("\n");
    }
    printf("\n");
    */
}


int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    int k; scanf("%d", &k);
    memset(f, 0, sizeof f);
    for(int i = 0; i < k; i++)
    {
        int c, x, y; scanf("%d%d%d", &c, &x, &y);
        f[x][y] = c;
    }

    int L; scanf("%d", &L);
    LL ans = 0;
    output();
    for(int J = 0; J < L; J++)
    {
        scanf("%s", buf);
        if(buf[0] == 'L'){
            for(int i = 1; i <= n; i++)
            {
                q.clear();
                bool flg = false;
                for(int j = 1; j <= n; j++) if(f[i][j] != 0) {
                    if(q.size() && (q.back() == f[i][j]) && !flg) {
                        q.pop_back();
                        q.push_back(f[i][j] * 2);
                        ans += f[i][j] * 2LL;
                        flg = true;
                    }
                    else {
                        q.push_back(f[i][j]);
                        flg = false;
                    }
                }
                for(int j = 1; j <= n; j++) f[i][j] = 0;
                for(int j = 1; q.size(); j++)
                {
                    f[i][j] = q.front(); q.pop_front();
                }
            }
        }

        if(buf[0] == 'R'){
            for(int i = 1; i <= n; i++)
            {
                q.clear();
                bool flg = false;
                for(int j = n; j > 0; j--) if(f[i][j] != 0) {
                    if(q.size() && q.back() == f[i][j] && !flg) {
                        q.pop_back();
                        q.push_back(f[i][j] * 2);
                        ans += f[i][j] * 2LL;
                        flg = true;
                    }
                    else {
                        q.push_back(f[i][j]);
                        flg = false;
                    }
                }
                for(int j = 1; j <= n; j++) f[i][j] = 0;
                for(int j = n; q.size(); j--)
                {
                    f[i][j] = q.front(); q.pop_front();
                }
            }
        }

        if(buf[0] == 'U'){
            for(int i = 1; i <= n; i++)
            {
                q.clear();
                bool flg = false;
                for(int j = 1; j <= n; j++) if(f[j][i] != 0) {
                    if(q.size() && q.back() == f[j][i] && !flg) {
                        q.pop_back();
                        q.push_back(f[j][i] * 2);
                        ans += f[j][i] * 2LL;
                        flg = true;
                    }
                    else {
                        q.push_back(f[j][i]);
                        flg = false;
                    }
                }
                for(int j = 1; j <= n; j++) f[j][i] = 0;
                for(int j = 1; q.size(); j++)
                {
                    f[j][i] = q.front(); q.pop_front();
                }
            }
        }

        if(buf[0] == 'D'){
            for(int i = 1; i <= n; i++)
            {
                q.clear();
                bool flg = false;
                for(int j = n; j > 0; j--) if(f[j][i] != 0) {
                    if(q.size() && q.back() == f[j][i] && !flg) {
                        q.pop_back();
                        q.push_back(f[j][i] * 2);
                        ans += f[j][i] * 2LL;
                        flg = true;
                    }
                    else {
                        q.push_back(f[j][i]);
                        flg = false;
                    }
                }
                for(int j = 1; j <= n; j++) f[j][i] = 0;
                for(int j = n; q.size(); j--)
                {
                    f[j][i] = q.front(); q.pop_front();
                }
            }
        }
        int c, x, y; scanf("%d%d%d", &c, &x, &y);
        f[x][y] = c;
        output();
    }
    printf("%I64d\n", ans);
    return 0;
}
