#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
typedef long long ll;

int vis[256];
char s[100010];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int ans = n, tot = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[s[i]]) tot++;
        vis[s[i]]++;
    }
    memset(vis, 0, sizeof vis);
    int r = 0, cur = 0;
    for(int l = 0; l < n; l++) {
        while(r < n && cur != tot) {
            if(!vis[s[r]]) cur++;
            vis[s[r]]++; r++;
        }
        if(tot != cur) break;
        ans = min(ans, r - l);
        vis[s[l]]--;
        if(!vis[s[l]]) cur--;
    }
    cout << ans << endl;
    return 0;
}
