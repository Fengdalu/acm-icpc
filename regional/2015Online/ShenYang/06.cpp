#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1000100

char s[N];
int n;

int main()
{
    int _T; scanf("%d", &_T);
    for(int _i = 1; _i <= _T; _i++)
    {
        scanf("%s", s);
        int n = strlen(s);
        int ans = 0;
        for(int i = 0; i < n; i++)
        if(s[i] == 'c')
        {
            ans++;
            if(s[(i + 1) % n] == 'c' || s[(i + 2) % n] == 'c') { ans = -1; break; }
        }
        for(int i = 0; i < n; i++) if(s[i] != 'c' && s[i] != 'f'){ans = -1; break;}

        printf("Case #%d: ", _i);
        if(ans == -1) printf("-1\n");
        else if(ans == 0) printf("%d\n", (n + 1) / 2);
        else printf("%d\n", ans);
    }
    return 0;
}