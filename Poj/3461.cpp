#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, n) for(int i = 0; i != n; i++)
#define FOR(i, j, k) for(int i = j; i != k; i++)

using namespace std;

int nt[11111];
char a[11111], b[1111111];

int main()
{
    int nn;
    cin >> nn;
    rep(ii, nn)
    {
        scanf("%s %s", a, b);
        int j = -1;
        int len = strlen(a);
        nt[0] = -1;
        for(int i = 1; i < len; i++)
        {
            while(j != -1 && a[j + 1] != a[i]) j = nt[j];
            if (a[i] == a[j + 1]) j++;
            nt[i] = j;
        }
        
        j = -1;
        len = strlen(b);
        int len2 = strlen(a) - 1;
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            while(j != -1 && a[j + 1] != b[i]) j = nt[j];
            if (a[j + 1] == b[i]) j++;
            if (j == len2) {ans++; j = nt[j];}
        }
        printf("%d\n", ans);
    }
    return 0;
}