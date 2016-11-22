#include <bits/stdc++.h>

typedef long long ll;
char s[200020];
int main() {
    int n;
    scanf("%s", s);
    int x = 0, y = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(s[i] == 'L') x++;
        if(s[i] == 'R') x--;
        if(s[i] == 'U') y++;
        if(s[i] == 'D') y--;
    }
    x = abs(x);
    y = abs(y);
    if((len) % 2 != 0) printf("-1");
    else printf("%d", (x + y) / 2);
    return 0;
}
