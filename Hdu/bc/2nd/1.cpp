#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 10000010;
char s[maxn];
int a[maxn], b[maxn];
int c[maxn];
int f[10];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int len = strlen(s);
        memset(f, 0, sizeof f);
        for(int i = 0; i < len; i++) f[s[i] - '0']++;
        int add = -1;
        for(int i = 1; i < 10; i++) {
            if(f[i]) {
                f[i]--;
                add = i;
                break;
            }
        }
        if(add == -1) {
           puts("Uncertain");
           continue;
        }
        int c3 = 0;
        for(int i = 0; i < 10; i++) {
            while(f[i]--) {
                c[c3++] = i;
            }
        }
        if(c[c3 - 1] == 0) {
           puts("Uncertain");
           continue;
        }
        c[0] += add;
        int i = 0;
        while(c[i] >= 10) {
            c[i] -= 10;
            if(i + 1 >= c3) {
                c[c3++] = 0;
            }
            c[i + 1]++;
            i++;
        }
        for(int i = c3 - 1; i >= 0; i--) printf("%d", c[i]);
        printf("\n");
    }
    return 0;
}

