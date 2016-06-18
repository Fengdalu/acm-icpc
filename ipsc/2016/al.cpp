#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;

string s[10];
int p[10];
bool vis[10];

int main() {
    int n;
    cin >> n;
    while(n--) {
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < 10; i++) cin >> s[i];
        string ans = "";
        bool flag = true;
        for(int i = 0; i < 10; i++)
        if(flag)
            for(int j = 0; j < 10; j++)
            if(flag)
                if(i != j) {
                    if(s[i][3] == s[j][0]) {
                        vis[i] = vis[j] = true;
                        ans = s[i] + s[j].substr(1, 3);
                        flag = false;
                    }
                    else if(s[i].substr(1, 3) == s[j].substr(0, 3)) {
                        vis[i] = vis[j] = true;
                        ans = s[i];
                        ans += s[j][3];
                        flag = false;
                    }
                    else if(s[i].substr(2, 2) == s[j].substr(0, 2)) {
                        vis[j] = vis[i] = true;
                        ans = s[i] + s[j].substr(2, 2);
                        flag = false;
                    }
                    else if(s[i] == s[j]) {
                         vis[i] = vis[j] = true;
                         ans = s[i];
                         flag = false;
                    }
                }
        for(int i = 0; i < 10; i++)
        if(!vis[i]) ans = ans + s[i];
        while(ans.size() < 39) ans.push_back('A');
        for(int i = 0; i < 10; i++)
            assert(ans.find(s[i]) != ans.npos);
        assert(ans.size() == 39);
        cout << ans << endl;
    }
}
