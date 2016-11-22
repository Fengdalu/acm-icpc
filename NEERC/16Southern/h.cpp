#include <bits/stdc++.h>

const int N = 2000;
std::string s[N];
char buf[200];
int main() {
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s", buf);
        s[i] = std::string(buf);
    }
    std::vector<int> ans(m);
    for(int i = 0; i < m; i++) {
        int p; scanf("%d", &p);
        ans[i] = p - 1;
    }
    std::sort(ans.begin(), ans.end());
    int len = s[ans[0]].size();
    std::string st = s[ans[0]];
    bool flag = true;
    for(int i = 1 ; i < m && flag; i++) {
        if(s[ans[i]].size() != len) flag = false;
        for(int j = 0; j < len; j++) {
            if(s[ans[i]][j] != st[j]) st[j] = '?';
        }
    }
    int J = 0;
    for(int i = 0; i < n && flag; i++) {
        if(J < n && ans[J] == i) { J++; continue; }
        if(s[i].size() != len) continue;
        bool chk = false;
        for(int j = 0; j < len && !chk; j++)
            if(st[j] == '?') continue;
            else if((st[j] != '?') && st[j] != s[i][j]) chk = true;
        if(!chk) flag = false;
    }
    if(flag) printf("Yes\n%s\n", st.c_str());
    else puts("No");
    return 0;
}
