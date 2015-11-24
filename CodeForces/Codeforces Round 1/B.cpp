#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL long long

char s[10010];
int pos[100010];
int pos1[100010];
int l[400], r[400], k[400];
int n, m;


int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) scanf("%d%d%d", &l[i], &r[i], &k[i]);
    for(int i = 1; i <= n; i++) pos[i] = i;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++)
            if(l[j] <= pos[i] && pos[i] <= r[j])
                pos[i] = l[j] + (pos[i] - l[j] + k[j]) % (r[j] - l[j] + 1);
    for(int i = 1; i <= n; i++) pos1[pos[i]] = i;
    for(int i = 1; i <= n; i++) printf("%c", s[pos1[i]]);
    return 0;
}
