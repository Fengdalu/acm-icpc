#include <stdio.h>

char str[6][10] =
{
    "qrabuvlk",
    "stcdwxji",
    "acegikmo",
    "bdfhjlnp",
    "rtefwupo",
    "qsghxvnm"
};
int check(int * a)
{
    //for(int i = 0; i < 24; i++)
    //    printf("%d ", a[i]); puts("");
    for(int i = 0; i < 6; i ++)
    {
        int j = i * 4;
        if(a[j] == a[j + 1] && a[j] == a[j + 2] && a[j] == a[j + 3]);
        else return 0;
    }
    return 1;
}
int a[24];
int b[24];
void run(int cas)
{
    for(int i = 0; i < 24; i++) scanf("%d", &a[i]);
    int flag = check(a);
    for(int op = 0; op < 6; op++)
    {
        for(int i = 0; i < 24; i++) b[i] = a[i];
        for(int i = 0; i < 8; i++)
            b[str[op][i] - 'a'] = a[str[op][(i + 2) % 8] - 'a'];
        flag |= check(b);
    }
    for(int op = 0; op < 6; op++)
    {
        for(int i = 0; i < 24; i++) b[i] = a[i];
        for(int i = 0; i < 8; i++)
            b[str[op][i] - 'a'] = a[str[op][(i + 8 - 2) % 8] - 'a'];
        flag |= check(b);
    }
    if(flag) puts("YES"); else puts("NO");
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++) run(i + 1);
}
