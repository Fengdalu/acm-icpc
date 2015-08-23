#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define PII pair<int, int>
#define PB(x) push_back(x)
#define AA first
#define BB second
vector<PII>s;

int main()
{
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    s.clear();

    int flg = 0;
    for(int i = 1; i <= n; i++)
    {
        flg ^= 1;
        if(flg)for(int j = 1; j <= m; j++) s.PB(PII(i, j));
        else for(int j = m; j >= 1; j--) s.PB(PII(i, j));
    }
    int cnt = 0;
    for(int i = 0; i < k - 1; i++)
    {
        printf("2 ");
        printf("%d %d ", s[cnt].AA, s[cnt].BB);
        cnt++;
        printf("%d %d\n", s[cnt].AA, s[cnt].BB);
        cnt++;
    }
    printf("%d ", s.size() - cnt);
    while(cnt < s.size()) { printf("%d %d ", s[cnt].AA, s[cnt].BB); cnt++; }
    return 0;
}
