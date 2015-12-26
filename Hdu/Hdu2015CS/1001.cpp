#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

char buf[10000];
string s[200];
bool vis[200];
int n;

bool check(string &a, string &b) {
    int tot = 0;
    if(a.length() != b.length()) return false;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] == b[i]) tot++;
    }
    if(tot > 2) return true;
    return false;
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%s", buf);
            int len = strlen(buf);
            for(int j = 0; j < len; j++) buf[j] = tolower(buf[j]);
            s[i] = string(buf);
        }
        int ans = 0;
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) if(check(s[i], s[j])) vis[i] = vis[j] = true;
        for(int i = 0; i < n; i++) if(vis[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
