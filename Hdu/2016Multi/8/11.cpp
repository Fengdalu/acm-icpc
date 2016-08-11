#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[100010];
char a[100010];
int main() {
    int _T; scanf("%d", &_T);
    while(_T--) {
        int n; scanf("%d", &n);
        scanf("%s", a);
        if(!strcmp(a, "()")) {
            puts("No"); continue;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == '(') s[cnt++] = '(';
            else if(cnt && s[cnt - 1] == '(') { cnt--; }
            else s[cnt++] = ')';
            s[cnt] = 0;
        }
        s[cnt] = 0;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < cnt; i++) {
            if(s[i] == '(') c1++; else c2++;
        }
        if(c1 != c2 || cnt > 4)  printf("No"); else printf("Yes");
        puts("");
    }
    return 0;
}
