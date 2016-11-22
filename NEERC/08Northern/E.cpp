#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[30][30];
char s1[200], s2[200];

int main()
{
    freopen("enchanted.in", "r", stdin);
    freopen("enchanted.out", "w", stdout);
    scanf("%s%s", s1, s2);
    memset(f, 0, sizeof f);
    int len = strlen(s1);
    for(int i = 0; i < len; i++)
        f[s1[i] - 'A'][s2[len - i - 1] - 'A']++;
    scanf("%s%s", s1, s2);
    for(int i = 0; i < len; i++)
        f[s1[i] - 'A'][s2[len - i - 1] - 'A']--;
    bool flg = true;
    for(int i = 0; i < 27; i++) for(int j = 0; j < 27; j++)
        if(f[i][j] != 0) flg = false;
    if(flg) puts("Yes");
    else puts("No");
    fclose(stdout);
    return 0;
}
