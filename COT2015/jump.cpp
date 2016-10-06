#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>

const int N = 1000020;
int v[N];
int dp[N];

int main()
{
    while(true)
    {
        int n;
        scanf("%d", &n);
        if(!n) break;
        std::map< int, std::vector<int> > left, right;
        for(int i = 1; i <= n; i++) scanf("%d", v + i);
        for(int i = 1; i <= n; i++)
        {
            right[i - v[i]].push_back(i);
            left[i + v[i]].push_back(i);
        }
        std::fill(dp, dp + n + 1, 0);
        dp[1] = true;
        std::queue<int> q;
        q.push(1);
        while(q.size())
        {
            int x = q.front();
            q.pop();
            std::vector<int> a = left[x - v[x]];
            std::vector<int> b = right[x + v[x]];
            for(int i = 0; i < a.size(); i++)
            {
                int v = a[i];
                if(v < x && !dp[v])
                {
                    dp[v] = 1;
                    q.push(v);
                }
            }
            for(int i = 0; i < b.size(); i++)
            {
                int v = b[i];
                if(v > x && !dp[v])
                {
                    dp[v] = 1;
                    q.push(v);
                }
            }
        }
        for(int i = n; i >= 1; i--) if(dp[i])
            {
                printf("%d\n", i-1);
                break;
            }
    }
    return 0;
}

/*
7
2 1 0 1 2 3 3
11
7 6 1 4 1 2 1 4 1 4 5
0
*/
