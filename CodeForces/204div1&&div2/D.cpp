#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define N 100010
#define PII pair<int, int>
#define PB(x) push_back(x)

int a[N];
int main()
{
    int n; scanf("%d", &n); int cnt = 0;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++)
    if(a[j] < a[i]) cnt++;
    if(cnt % 2 == 0) cnt = cnt * 2;
    else cnt = cnt * 2 - 1;
    printf("%d.000000\n", cnt);
    return 0;
}
