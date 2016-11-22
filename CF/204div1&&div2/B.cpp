#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define N 100010
#define PII pair<int, int>
#define PB(x) push_back(x)

vector<int>q[N];
vector<PII>ans;

int main()
{
    for(int i = 1; i < N; i++) q[i].clear();
    ans.clear();int x;
    int n; scanf("%d", &n);
    int m = 0;
    for(int i = 0; i < n; i++) { scanf("%d", &x); q[x].PB(i); m = max(m, x); }
    for(int i = 0; i <= m; i++)
    if(q[i].size())
    {
        if(q[i].size() == 1) { ans.PB(PII(i, 0)); continue; }
        int p = q[i][1] - q[i][0];
        bool flg = true;
        for(int j = 1; j < q[i].size(); j++)
        {
            if(p != q[i][j] - q[i][j - 1]) { flg = false; break; }
        }
        if(flg) ans.PB(PII(i, p));
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
