#include <bits/stdc++.h>

char s[2000100];
int main() {
    int n; scanf("%d%s", &n, s);
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == '<') ans++;
        else break;
    for(int i = n - 1; i >= 0; i--)
        if(s[i] == '>') ans++;
        else break;
    printf("%d\n", ans);
    return 0;
}
