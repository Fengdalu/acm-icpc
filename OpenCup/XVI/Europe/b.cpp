#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e6;
char s[maxn];
int pre[maxn];
int a[maxn];
int len;
int main() {
    gets(s);
    len = strlen(s);
    pre[0] = 0;
    for(int i = 0; i < len; i++) {
        if(s[i] == ' ') pre[i + 1] = i + 1;
        else pre[i + 1] = pre[i];
    }
    for(int i = len - 1; i >= 0; i--)
    if(s[i] == ' ') a[i] = 0;
    else a[i] = a[i + 1] + 1;
    int l, r;
    scanf("%d%d", &l, &r);
    for(int w = l; w < r + 1; w++) {
        int i = 0;
        int tot = 0;
        while(i < len) {
            tot += a[i] + 1;
            i += w;
            if(i >= len) break;
            if(s[i] != ' ') i = pre[i];
            while(s[i] == ' ') i++;
        }
        printf("%d\n", tot - 1);
    }
}
