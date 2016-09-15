#include <bits/stdc++.h>

std::pair<int, int> f[400];

void solve() {
    int next = 0, cur = 1;
    int n; scanf("%d", &n);
    if(n == 0) exit(0);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &f[i].first, &f[i].second);
        f[i].first *= 60; f[i].second *= 60;
        f[i].first++;
        f[i].second--;
    }
    std::sort(f, f + n);
    int ANS = 0;
    int nil = f[0].first;
    for(int ST = nil; ST <= nil + 300; ST++) {
        if(ST % 60 != 1 && ST % 60 != 0) continue;
        std::priority_queue<int, std::vector<int>, std::greater<int> >q;
        int tot = 0;
        int J = 0;
        for(int i = ST; i < 1010*60; i += 300) {
            while(J < n && f[J].first <= i) {
                q.push(f[J].second);
                J++;
            }
            while(q.size() && q.top() < i) {
                q.pop();
            }
            if(q.size()) {
                q.pop();
                tot++;
            }
        }
        ANS = std::max(tot, ANS);
    }
    std::cout << ANS << std::endl;
}

int main() {
    while(true) solve();
    return 0;
}
