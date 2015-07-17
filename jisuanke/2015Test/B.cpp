#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool chk[100];
int n;
char s[1000];
int num[1000];
int N;

bool dfs(int x, int p)
{
    if(x == n)
    {
        for(int i = 1; i < 50; i++)
        {
            if(!chk[i] && chk[i + 1]) return false;
        }
        for(int i = 0; i < p; i++) if(!i) printf("%d", num[i]); else printf(" %d", num[i]);
        printf("\n");
        return true;
    }
    int tmp = s[x] - '0';
    if(!chk[tmp] && tmp != 0)
    {
        chk[tmp] = true;
        num[p] = tmp;
        if(dfs(x + 1, p + 1)) return true;
        chk[tmp] = false;
    }
    tmp = (s[x] - '0') * 10 + s[x + 1] - '0';
    if(!chk[tmp] && tmp != 0)
    {
        chk[tmp] = true;
        num[p] = tmp;
        if(dfs(x + 2, p + 1)) return true;
        chk[tmp] = false;
    }
    return false;
}


int main()
{
    scanf("%s", s);
    memset(chk, 0, sizeof chk);
    n = strlen(s);
    dfs(0, 0);
    return 0;
}
