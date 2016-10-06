#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long ll;

inline bool num(char c) { if('0' <= c && c <= '9') return true; else return false; }
inline int cv(char c) { return c - '0'; }
ll cal(std::string &s, int l, int r) {
    int flag = false;
    int pos = 0;
    for(int i = l; i <= r; i++) {
        if(s[i] == '+' || s[i] == '-') flag = true;
    }
    if(!flag) {
        ll ans = 1;
        ll cur = 0;
        for(int i = l; i <= r; i++) {
            if(num(s[i])) cur = cur * 10 + cv(s[i]);
            else {
                ans = ans * cur;
                cur = 0;
            }
        }
        return ans * cur;
    }
    ll ans = 0;
    int pre = l;
    for(int i = l; i <= r; i++) {
        if(s[i] == '+' || s[i] == '-' || i == r) {
            ll t = cal(s, num(s[pre]) ? pre : pre + 1, i != r ? i - 1 : i);
            if(s[pre] == '-') ans -= t;
            else ans += t;
            pre = i;
        }
    }
    return ans;
}

char line[3][100000];
std::string s[3];
ll cal(std::string s) {
    int l = 0, r = s.size() - 1;
    while(s[l] == ' ') l++;
    while(s[r] == ' ') r--;
    s = s.substr(l, r - l + 1);
    l = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') s[l++] = s[i];
    }
    s = s.substr(0, l);
    return cal(s, 0, s.size() - 1);
}

char buf[50];
int main() {
    int R, C;
    while(true) {
        scanf("%d%d", &R, &C);
        if(R == 0 && C == 0) break;
        gets(buf);
        for(int i = 0; i < R; i++) gets(line[i]);
        for(int i = 0; i < R; i++) s[i] = std::string(line[i]);

        if(R == 1) { printf("%I64d\n", cal(std::string(s[0]))); continue; }
        else {
            for(int i = 0; i < C; i++) {
                if(s[1][i] == '=') {
                    int l = i;
                    while(s[1][l] == '=') l++;
                    ll fz = cal(s[0].substr(i, l - i));
                    ll fm = cal(s[2].substr(i, l - i));
                    ll r = fz / fm;
                    for(int j = i; j < l; j++) s[1][j] = ' ';
                    sprintf(buf, "%I64d", r);
                    int len = strlen(buf);
                    for(int j = 0; j < len; j++) s[1][j + i] = buf[j];
                }
                else if(s[1][i] == '\\') {
                    int l = i + 2;
                    while(s[0][l] == '_') l++;
                    ll r = sqrt(cal(s[1].substr(i + 2, l - i - 2)));
                    for(int j = i; j < l; j++) s[1][j] = ' ';
                    sprintf(buf, "%I64d", r);
                    int len = strlen(buf);
                    for(int j = 0; j < len; j++) s[1][j + i] = buf[j];
                }
            }
        }
        printf("%I64d\n", cal(s[1]));
    }
    return 0;
}
/*
1 13
1 + 2 * 3 - 4

2 16
  _________
\/3 * 4 - 3 + 10

3 5
6 * 4
=====
   12

3 13
    22     __
3 - == - \/16
    11

0 0
*/


