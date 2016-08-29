#include <bits/stdc++.h>
using namespace std;

char s[2000][11];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%s", s[i]);
    bool flag = false;
    for(int i = 0; i < n; i++) if(!flag) {
        if(s[i][0] == 'O' && s[i][1] == 'O') {
            s[i][0] = '+';
            s[i][1] = '+';
            flag = true;
        }
        else if(s[i][3] == 'O' && s[i][4] == 'O')  {
            s[i][3] = s[i][4] = '+';
            flag = true;
        }
    }
    if(flag) {
        printf("YES\n");
        for(int i = 0; i < n; i++) printf("%s\n", s[i]);
    }
    else printf("NO");
    return 0;
}
