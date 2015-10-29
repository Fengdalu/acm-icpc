#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


char f[2000];
char s[50000];
int cnt = 0;

int main()
{
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    scanf("%s", f); cnt = 0;
    int n = strlen(f);
    bool flg = false;
    for(int i = 0; i < n; i++)
    {
        if(f[i] == '+' || f[i] == '-')
        {
            s[cnt++] = f[i];
            flg = false;
            if(f[i] == '-') { flg = true; s[cnt++] = f[i + 1]; i++; }
        }
        else if(flg)
        {
            if(f[i] == '0') { s[cnt++] = '+'; s[cnt++] = f[i]; }
            else { s[cnt++] = '+'; s[cnt++] = f[i]; flg = false; }
        }
        else s[cnt++] = f[i];
    }
    printf("%s", s);
    fclose(stdout);
    return 0;
}
