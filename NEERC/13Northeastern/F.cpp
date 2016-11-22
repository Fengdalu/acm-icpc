#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

string t;
int n;
vector<string>ans;

int main() {
    freopen("fraud.in", "r", stdin);
    freopen("fraud.out", "w", stdout);
    cin >> t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s.length() != t.length()) continue;
        bool flg = true;
        for(int j=0; j < t.length(); j++) if(t[j] != '*'){
            if(t[j] != s[j]) {flg = false; break; }
        }
        if(flg) ans.push_back(s);
    }
    cout << ans.size() << endl;
    for(int i=0; i < ans.size(); i++) cout << ans[i] << endl;
    fclose(stdout);
    return 0;
}