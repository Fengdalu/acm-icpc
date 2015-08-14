#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define N 300010

char s[N];
char buf[10];
int y;
int n, m;
int p[N], b[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s);

    int tot = 0;
    int sum = 0;
    int l = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '.') tot++;
        else { sum += max(0, tot - 1); tot = 0; }
    }
    sum += max(0, tot - 1);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%s", &y, buf);
        if(n == 1) { printf("0\n"); continue; }
        y--;
        if(buf[0] != '.')
        {
            if(s[y] != '.') { printf("%d\n", sum); continue; }
            if(y == 0 && s[y + 1] == '.') sum = sum - 1;
            else if(y == n - 1 && s[y - 1] == '.') sum = sum - 1;
            else if(y != n - 1 && y != 0) sum = sum - (s[y - 1] == '.' ? 1 : 0) - (s[y + 1] == '.' ? 1 : 0);
            printf("%d\n", sum);
            s[y] = buf[0];
        }
        else
        {
            if(s[y] == '.') { printf("%d\n", sum); continue; }
            if(y == 0 && s[y + 1] == '.') sum++;
            else if(y == n - 1 && s[y - 1] == '.') sum++;
            else if(y != n - 1 && y != 0) sum += (s[y - 1] == '.' ? 1 : 0) + (s[y + 1] == '.' ? 1 : 0);
            printf("%d\n", sum);
            s[y] = '.';
        }
    }
    return 0;
}
