#include <bits/stdc++.h>

const int N = 2e5+100;
char s[N];
int main() {
    int n; scanf("%d%s", &n, s);
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) if(s[i] == 'A') a++; else b++;
    if(a > b) puts("Anton"); else if(b > a) puts("Danik"); else puts("Friendship");
    return 0;
}
