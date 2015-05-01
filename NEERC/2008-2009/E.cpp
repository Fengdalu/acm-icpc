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

char s1[200];
char s2[200];
char s3[200];
char s4[200];

int cnt1[30][30];
int cnt2[30][30];

int main()
{
    freopen("enchanted.in","r",stdin);
    freopen("enchanted.out","w",stdout);
    cin >> s1 >> s2 >> s3 >> s4;
    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));
    int len = strlen(s1);
    int i,j;
    for (i = 0, j = len-1; i < len; i++,j--)
    {
        cnt1[s1[i]-'A'][s2[j]-'A']++;
    }
    for (i = 0, j = len-1; i < len; i++,j--)
    {
        cnt2[s3[i]-'A'][s4[j]-'A']++;
    }
    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (cnt1[i][j] != cnt2[i][j])
            {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}