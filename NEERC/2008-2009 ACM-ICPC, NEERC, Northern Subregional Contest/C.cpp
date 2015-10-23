#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool s[110][110];

int main()
{
    freopen("class.in", "r", stdin);
    freopen("class.out", "w", stdout);
    int n, r, c; scanf("%d%d%d", &n, &r, &c);
    if(n > r * c) { printf("-1\n"); fclose(stdout); return 0; }
    memset(s, 0, sizeof s);
    int ans = min(r, c);
    if(n >= 2 * ans - 1)
    {
        for(int i = 0; i < ans; i++)
            s[i][0] = s[0][i] = true;
        n -= 2 * ans - 1;
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++)
        if(n && !s[i][j])
        { s[i][j] = true; n--; }

    }
    else    {
        ans = (n + 1) / 2;
        for(int i = 0; i < ans; i++) s[i][0] = true;
        for(int i = 0; i < n - ans + 1; i++) s[0][i] = true;
    }
            printf("%d\n", ans);
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
                if(s[i][j]) printf("#");
                else printf(".");
            printf("\n");
        }
    fclose(stdout);
}
