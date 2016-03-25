#include <stdio.h>
#include <string.h>
long long ans[1000001];
long long dfs(long long n)
{
    if(n <= 1000000 && ~ans[n]) return ans[n];
    if(n & 1)
    {
        if(n > 1000000) return n / 2 * 2+ 2 + dfs(n / 2 * 3 + 2);
        else return ans[n] = n / 2 * 2 + 2 + dfs(n / 2 * 3 + 2);
    }
    else
    {
        if(n > 1000000) return n + dfs(n / 2);
        else return ans[n] = n + dfs(n / 2);
    }
}
int main()
{
    memset(ans, -1, sizeof ans);
    ans[1] = 0;
    int n;
    while(~scanf("%d",&n))
        printf("%I64d\n",dfs(n));
}