#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool vis[1000100];
char s[1000100];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
        if(s[i] != 'a') vis[i] = true;
        else vis[i] = false;
    }
    int l = -1, r = -1;
    for(int i = 0; i < n; i++) {
        if(vis[i] && l == -1) l = i;
        else if(!vis[i] && l != -1) break;
        r = i;
    }
    if(l == -1){
        int len = strlen(s);
        s[len-1]='z';
        printf("%s", s);
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(l <= i && i <= r) {
            printf("%c", s[i] - 1);
        }
        else printf("%c", s[i]);
    }
    return 0;
}
