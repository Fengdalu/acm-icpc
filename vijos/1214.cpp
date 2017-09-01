#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> dp(n, 0);
    vector< pair<int, int> > lines(n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &lines[i].second, &lines[i].first);
        if(lines[i].second > lines[i].first) swap(lines[i].first, lines[i].second);
        lines[i].second *= -1;
    }
    std::sort(lines.begin(), lines.end());
    for(int i = 0; i < n; i++) {
        swap(lines[i].first, lines[i].second);
        lines[i].first *= -1;
    }
    dp[0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++) {
            if(lines[j].second <= lines[i].first) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    printf("%d\n", *max_element(dp.begin(), dp.end()));
    return 0;
}
