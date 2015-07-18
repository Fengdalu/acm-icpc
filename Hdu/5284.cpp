#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[3245728];

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        bool f1 = false, f2 = false, f3 = false;
        scanf("%s", s);
        int n = strlen(s);
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'w' || (i + 1 < n && s[i] == 'v' && s[i + 1] == 'v')) f1 = true;
            if(f1 && s[i] == 'y') f2 = true;
            if(f1 && f2 && s[i] == 'h') f3 = true;
        }
        if(f1 && f2 && f3) puts("Yes"); else puts("No");
    }

    return 0;
}
