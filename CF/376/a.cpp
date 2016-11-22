#include <bits/stdc++.h>

char s[1000];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    char p = 'a';
    for(int i = 0; i < n; i++) {
        int d = std::abs(s[i] - p);
        ans += std::min(26 - d, d);
        p = s[i];
    }
    printf("%d\n", ans);
    return 0;
}
