#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 100010
#define PII pair<int, int>
#define PB(x) push_back(x)
#define INF 1e9

int f[N];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &f[i]);
    for(int i = 0; i < n; i++) f[i] = abs(f[i]);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int a = 0, b = 0;
        for(int j = 0; j < i; j++) if(f[j] < f[i]) a++;
        for(int j = i + 1; j < n; j++) if(f[j] < f[i]) b++;
        ans += min(a, b);
    }
    printf("%d\n", ans);
    return 0;
}
