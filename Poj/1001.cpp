#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define max(a, b)  (((a) > (b)) ? (a) : (b))
#define MAXN 100000

using namespace std;

int x[MAXN], y[MAXN], z[MAXN];
int cntx, cnty, cntz;
char s[MAXN];
int n, p;
float r;

int main()
{
    int i, j, k;
    
    while(scanf("%f%d", &r, &n) == 2)
    {
        x[1] = 1;
        cntx = 1;
        cnty = 0;
        cntz = 0;
        p = 0;
        memset(z, 0, sizeof(z));
        sprintf(s, "%.4f", r);
        
        for (i = strlen(s) - 1; i >= 0; i--)
        {
            if (s[i] != '.') y[++cnty] = s[i] - '0';
            else p = cnty;
        }
        
        
        for (int ii = 1; ii <= n; ii++)
        {
            for (i = 1; i <= cnty; i++)
                for (j = 1; j <= cntx; j++)
                {
                    z[i + j - 1] += x[j] * y[i];
                    cntz = max(i + j - 1, cntz);
                    if (z[i + j - 1] >= 10)
                    {
                        z[i + j] += z[i + j - 1] / 10;
                        z[i + j - 1] %= 10;
                        cntz = max(cntz, i + j);
                    }
                    
                    while (z[cntz] >= 10)
                    {
                        z[cntz + 1] = z[cntz] / 10;
                        z[cntz] = z[cntz] % 10;
                        cntz++;
                    }
                }
            
            for (i = 1; i <= cntz; i++) {x[i] = z[i]; z[i] = 0;}
            cntx = cntz;
            cntz = 0;
        }
        
        p = n * p;
        for (i = cntx; i > p; i--) if (x[cntx] != 0) printf("%d", x[i]);
        
        j = 1;
        while (x[j] == 0) j++;
        
        if (i >= j) printf(".");
        for (;i >= j; i--) printf("%d", x[i]);
        
        printf("\n");
    }
    
    return 0;
}
