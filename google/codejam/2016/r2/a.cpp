#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 12;

int f[3];
string cal(int top, int c) {
    if(top == 0) {
        f[c]++;
        if(c == 0) return "R";
        if(c == 1) return "P";
        if(c == 2) return "S";
    }
    if(c == 0) {
        string x = cal(top - 1, 0);
        string y = cal(top - 1, 1);
        return min(x + y, y + x);
    }
    if(c == 1) {
        string x = cal(top - 1, 2);
        string y = cal(top - 1, 1);
        return min(x + y, y + x);
    }
   if(c == 2) {
        string x = cal(top - 1, 0);
        string y = cal(top - 1, 2);
        return min(x + y, y + x);
    }
   return "";
}


int main() {
    int _;
    cin >> _;
    int cas = 0;
    while(_--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;

        string ss;
        string ans = "";
        memset(f, 0, sizeof f);
        ss = cal(n, 0);
        if(f[0] == a && f[1] == b && f[2] == c) { if(!ans.size()) ans = ss; else ans = min(ans, ss); }

        memset(f, 0, sizeof f);
        ss = cal(n, 1);
        if(f[0] == a && f[1] == b && f[2] == c) { if(!ans.size()) ans = ss; else ans = min(ans, ss); }

        memset(f, 0, sizeof f);
        ss = cal(n, 2);
        if(f[0] == a && f[1] == b && f[2] == c) { if(!ans.size()) ans = ss; else ans = min(ans, ss); }
        if(ans.size())
         cout << "Case #" << ++cas << ": " << ans << endl;
        else cout << "Case #" << ++cas << ": IMPOSSIBLE" << endl;
    }
    return 0;
}
