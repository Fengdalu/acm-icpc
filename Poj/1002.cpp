#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXM 300
#define MAXN 100005

using namespace std;


int ans[MAXN];

int cal(char x)
{
    if (x >= '0' && x <= '9') return x - '0';
    if (x >= 'A' && x <= 'Z') return (x - 'A' - (x > 'Q')) / 3 + 2;
    return -1;
}

char s[MAXM];
int n;

int main()
{
    int i, j, k;
    
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
    {
        gets(s);
        ans[i] = 0;
        for (j = 0; j < strlen(s); j++)
        {
            k = cal(s[j]);
            if (k >= 0) ans[i] = ans[i] * 10 + k;
        }
    }
    
    sort(ans, ans + n);
    i = 0;
    int flg = 0;
    while (i < n)
    {
        k = 1;
        while (ans[i + 1] == ans[i])
        {
            k++;
            i++;
        }
        
        if (k > 1)
        {
            flg = 1;
            printf("%03d-%04d %d\n", ans[i] / 10000, ans[i] % 10000, k);
        }
        i++;
    }
    if (!flg) printf("No duplicates. \n");
    
    return 0;
}