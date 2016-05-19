#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct node
{
    char s[111];
    int c;
    void cal()
    {
        scanf("%s", s);
        c = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
            {
                if (s[i] > s[j]) c++;
            }
    }
}f[50];

int cmp(node a, node b)
{
    return a.c < b.c;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        f[i].cal();
    }
    sort(f, f + m, cmp);
    for (int i = 0; i < m; i++)
        puts(f[i].s);
    return 0;
}