#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <queue>
typedef long long ll;


typedef std::pair<int, int> pii;
const int inf = 1e8;
const int N = 1e6+100;
int dp[N];
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int X, k, t;
        scanf("%d%d%d", &X, &k, &t);
        std::deque<pii> q;
        dp[X] = 0;
        q.push_front(pii(X, 0));
        for(int i = X - 1; i >= 1; i--) {
            while(q.size() && q.front().first > i + t) q.pop_front();
            dp[i] = q.front().second + 1;
            if(1ll * i * k <= X) dp[i] = std::min(dp[i], dp[i * k] + 1);
            while(q.size() && dp[i] <= q.back().second) q.pop_back();
            q.push_back(pii(i, dp[i]));
        }
        printf("%d\n", dp[1]);
    }
    return 0;
}
