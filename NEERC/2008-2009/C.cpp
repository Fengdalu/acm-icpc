#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

inline int cmin (int a, int b)
{
    return a < b ? a : b;
}

char out[200][200];

int main()
{
    freopen("class.in","r",stdin);
    freopen("class.out","w",stdout);
    int n,r,c;
    cin >> n >> r>> c;
    int ans = cmin (r,c);
    memset (out,'.',sizeof(out));
    int i,j;
    if (n >= ans * 2 - 1){
        for (i = 0; i < ans; i++){
            out[0][i] = '#';
        }
        for (i = 0; i < ans; i++){
            out[i][0] = '#';
        }
        int rec = n - (ans*2-1);
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (rec && out[i][j] == '.')
                {
                    out[i][j] = '#';
                    rec--;
                }
                if (!rec)
                    break;
            }
            if (!rec)
                break;
        }
        printf("%d\n",ans);
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                printf("%c",out[i][j]);
            }
            printf("\n");
        }
    }
    else{
        ans = (n+1)/2;
        for (i = 0; i < ans; i++)
        {
            out[0][i] = '#';
        }
        if (n % 2 == 0)
            out[0][i] = '#';
        for (j = 0; j < ans; j++)
        {
            out[j][0] = '#';
        }
        printf("%d\n",ans);
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                printf("%c",out[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}