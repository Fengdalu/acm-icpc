#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[10];
int main() {
    int cur = 0;
    while(true) {
        bool flag = false;
        int x = cur + 1;
        while(true) {
            printf("%d\n", x);
            fflush(stdout);
            scanf("%s", s);
            if(s[0] == 'y') break;
            else x++;
        }
        cur = x;
        if(cur == 1) break;
        printf("%d\n", 1);
        fflush(stdout);
        scanf("%s", s);
        if(s[0] == 'y') return 0;
    }
    return 0;
}
