#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
bool chk[1000];
char s[1000];

int main()
{
    memset(chk, 0, sizeof chk);
    for(int i = 1; i < 1000; i++) if(!(i % 8)) chk[i] = true;
    scanf("%s", s);
    int n = strlen(s);
    int x;
    for(int i = 0; i < n; i++)
    if(s[i] == '0')
    {
        puts("YES\n0");
        return 0;
    }
    for(int i = 0; i < n; i++)
    if(s[i] == '8')
    {
        puts("YES\n8");
        return 0;
    }
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++)
    {
        x = (s[i] - '0') * 10 + s[j] - '0';
        if(chk[x]){ printf("YES\n%d\n", x);  return 0; }
    }
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++)
            {
                x = (s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0';
                if(chk[x]) { printf("YES\n%d\n", x);  return 0; }
            }
    puts("NO");
    return 0;
}

