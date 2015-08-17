#include <iostream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned int uint;

uint ELFHash(char *str)
{
    uint h = 0;
    uint x;
    while(*str == '0') str++;
    while(*str)
    {
        h = (h << 4) + *str++;
        x = 0xF000000 & h;
        if(x)
        {
            h ^= (x >> 24);
            h &= (~x);
        }
    }
    return h & 0x7FFFFFFF;
}

int c[5000];
int n;
char buf[50];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++) { scanf("%s", buf); c[i] = ELFHash(buf); }
        sort(c, c + n);
        int cnt = 1;
        int ans = 1;
        for(int i = 1; i < n; i++)
        {
            if(c[i] == c[i - 1]) { cnt++; ans = max(ans, cnt); }
            else cnt = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
