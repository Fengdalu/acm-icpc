#include <bits/stdc++.h>
using namespace std;

string s, t;
char buf[1000100];

int main() {
    scanf("%s", buf);
    s = string(buf);
    if(s == "0") { cout << s << endl; return 0; }
    if(s == ".") { cout << 0 << endl; return 0; }
    bool flag = true;
    for(int i = 0; i < s.size(); i++) if(s[i] != '0' && s[i] != '.') flag = false;
    if(flag) {
        cout << 0 << endl;
        return 0;
    }

    bool ff = s.find(".") != s.npos;
    int n = strlen(buf);
    int l = 0, r = n - 1;
    for(int i = 0; i < n; i++) if(buf[i] != '0'){ l = i; break; }
    while(ff && buf[r] == '0') { buf[r] = 0; r--; }
    s = string(buf + l);

    if(s[s.size() - 1] == '.') s = s.substr(0, s.size() - 1);
    if(s == "0") { cout << s << endl; return 0; }
    if(s == ".") { cout << 0 << endl; return 0; }
    if(s.find('.') == s.npos) {
        t = t + s[0];
        if(s.size() == 1) { printf("%s", t.c_str()); return 0; }
        t = t + ".";
        t = t + s.substr(1);
        int r = t.size() - 1;
        while(t[r] == '0') r--;
        if(t[r] == '.') r--;
        printf("%sE%d", t.substr(0, r + 1).c_str(), s.size() - 1);
        return 0;
    }
    int pos = s.find('.');
    if(pos == 0) {
        s = s.substr(1);
        if(s.size() == 1) { printf("%sE-1", s.c_str()); return 0; }
        int pp = 0;
        for(int i = 0; i < s.size(); i++) if(s[i] == '0') { pp++; } else break;
        t = s[pp];
        t = t + ".";
        t = t + s.substr(pp + 1);
        int r = t.size() - 1;
        while(t[r] == '0') r--;
        if(t[r] == '.') r--;
        printf("%sE-%d", t.substr(0, r + 1).c_str(), pp + 1);
        return 0;
    }
    t = s[0];
    t = t + ".";
    t = t + s.substr(1, pos - 1);
    t = t + s.substr(pos + 1);
    r = t.size() - 1;
    while(t[r] == '0') r--;
    if(t[r] == '.') r--;
    if(pos != 1) printf("%sE%d", t.substr(0, r + 1).c_str(), pos - 1);
    else printf("%s", t.substr(0, r + 1).c_str());
    return 0;
}
