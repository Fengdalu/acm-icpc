#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

bool check(int x, const string &s) {
    char buf[10];
    sprintf(buf, "%d", x);
    string t(buf);
    while(t.size() < s.size()) t = "0" + t;
    if(t.size() != s.size()) return false;
    for(int i = 0; i < s.size(); i++)
        if(t[i] != s[i] && s[i] != '?') return false;
    return true;
}

int main() {
    int T;
    cin >> T;
    for(int ii = 1; ii <= T; ii++) {
        string a, b;
        cin >> a >> b;
        int p = -1, q = -1;
        for(int i = 0; i < 1000; i++)
                for(int j = 0; j < 1000; j++)
                    if(check(i, a) && check(j, b)) {
                         if(p == -1) {p = i; q = j;}
                         else if(abs(p - q) > abs(i - j)) {
                             p = i;
                             q = j;

                         }}
        char buf[10], buf1[10];
        sprintf(buf, "%d", p);
        sprintf(buf1, "%d", q);
        string t(buf), y(buf1);
        while(t.size() < a.size()) t = "0" + t;
        while(y.size() < b.size()) y = "0" + y;
        printf("Case #%d: %s %s\n", ii, t.c_str(), y.c_str());
    }
}


