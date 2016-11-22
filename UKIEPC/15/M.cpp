#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
#define LL long long

LL a[1001], b[1001];
int n, m;
vector<LL>ans;

int main()
{
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++) scanf("%I64d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%I64d", &b[i]);

    for(int i = 0; i <= n - m; i++)
    {
        LL p = a[1] - a[0], q = b[i + 1] - b[i];
        bool flg = true;
        for(int j = i; j < i + m - 1; j++)
        if( p * (b[j + 1] - b[j]) != q * (a[j - i + 1] - a[j - i]) )
        {
            flg = false; break;
        }

        if(flg) ans.push_back(b[i + 1] - b[i]);
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}

