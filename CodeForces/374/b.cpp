#include <bits/stdc++.h>

std::map<int, std::set<std::string> >f;
char buf[200];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s", buf);
        std::string s(buf);
        f[s.size()].insert(s);
    }
    scanf("%s", buf);
    std::string pwd(buf);
    int cnt = 0;
    for(int i = 0; i < pwd.size(); i++)
        cnt += f[i].size();
    printf("%d %d\n",
    (cnt) / k * 5 + cnt + 1,
    (cnt + (int)f[pwd.size()].size() - 1) / k * 5
    + cnt + (int)f[pwd.size()].size());
    return 0;
}
