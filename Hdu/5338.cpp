#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#include <set>

int b[50];
int n;
int a;
int ans;

bool dfs(int p, int a){
    if(a == 0) return true;
    if(p == n) return false;
    if(dfs(p + 1, a)) return true;
    ans++;
    if(dfs(p + 1, a % b[p])) return true;
    ans--;
    return false;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &a);
        for(int i = 0; i < n; i++) scanf("%d", &b[i]);
        n = unique(b, b + n) - b;
        sort(b, b + n);
        reverse(b, b + n);
        ans = 0;
        if(dfs(0, a)) printf("%d\n", ans);
        else printf("-1\n");
    }
    return 0;
}
