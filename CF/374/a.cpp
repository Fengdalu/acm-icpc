#include <bits/stdc++.h>

char buf[500];
int main() {
    int n; scanf("%d", &n);
    scanf("%s", buf);
    buf[n] = 'W';
    int cnt = 0;
    std::vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(buf[i] == 'B') cnt++;
        if(buf[i] == 'B' && buf[i + 1] == 'W') {
            ans.push_back(cnt);
            cnt = 0;
        }
    }
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    return 0;
}
