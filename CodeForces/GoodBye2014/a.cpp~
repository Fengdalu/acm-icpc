#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
int f[44444];

int main()
{   
    int t;
    scanf("%d%d", &n, &t);
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d", &f[i]);
    }  
   int p = 0;
   t--;
    while(p < t) 
    {
        p += f[p];
    }
    if(p == t) puts("YES");
    else puts("NO");
    return 0;
}
