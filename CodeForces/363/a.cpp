#include <bits/stdc++.h>
using namespace std;

const int maxn = 200100;
char s[maxn];
int pos[maxn];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for(int i = 0; i < n; i++) scanf("%d", &pos[i]);
    int ans = 1e9;
    for(int i = 0; i < n - 1; i++) if(s[i] == 'R'){
        int j = i + 1;
        if(s[j] == 'R') continue;
        else ans = min(ans, (pos[i + 1] - pos[i]) / 2);
    }
    if(ans == 1e9) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}
