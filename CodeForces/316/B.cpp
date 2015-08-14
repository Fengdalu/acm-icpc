#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int c1 = -1, c2 = -1;
    if(n == 1) { printf("1\n"); return 0; }
    if(m < n) { c1 = n - m; }
    if(m > 1) { c2 = m - 1; }
    if(c1 > c2) printf("%d\n", m + 1);
    else printf("%d\n", m - 1);
    return 0;
}
