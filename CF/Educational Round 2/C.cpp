#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define LL long long

int cnt['z' + 10];
vector<char>f;
string s;
string ans1;
string ans2;

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < s.length(); i++) {
        cnt[s[i]]++;
    }
    for(char c = 'a'; c <= 'z'; c++) if(cnt[c] & 1){
        f.push_back(c);
    }
    sort(f.begin(), f.end());
    while(f.size() > 1) {
        cnt[f[0]]++;
        cnt[f[f.size() - 1]]--;
        f.erase(f.begin());
        f.resize(f.size() - 1);
    }
    for(char c = 'a'; c <= 'z'; c++) if(cnt[c]) {
        while(cnt[c] >= 2) {
            ans1 += c;
            cnt[c] -= 2;
        }
    }
    ans2 = ans1;
    reverse(ans2.begin(), ans2.end());
    for(char c = 'a'; c <= 'z'; c++) if(cnt[c]) ans1 += c;
    cout << ans1 << ans2 << endl;
    return 0;
}

