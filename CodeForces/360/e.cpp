#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <bitset>
using namespace std;

bitset<501> f[600];
int main() {
    int n, k;
    for(int i = 0; i <= 501; i++) f[i].reset(0);
    f[0][0] = 1;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        for(int j = k; j >= c; j--)
            f[j] |= (f[j - c] << c) | f[j - c];
    }
    int nx = 0;
    for(int i = 0; i <= k; i++)
        if(f[k][i]) nx++;
    printf("%d\n", nx);
    for(int i = 0; i <= k; i++)
    if(f[k][i]) printf("%d ", i);
    return 0;
}
