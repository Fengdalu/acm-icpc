#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

char buf[1000010];
int cnt[10];
string ans;
void check(string &a, string b) {
    if(a == "") a = b;
    else if(b.size() < a.size()) a = b;
    else a = min(a, b);
}
int main() {
    scanf("%s", buf);
    int len = strlen(buf);
    int w = len;
    for(int i = 0; i < len; i++) cnt[buf[i] - '0']++;
    if(w == 2) {
        if(cnt[1]) for(int i = 0; i < 10; i++) if(i != 1 && cnt[i]) printf("%c", i + '0');
        return 0;
    }
    scanf("%s", buf);
    len = strlen(buf);
    for(int i = 0; i < len; i++) cnt[buf[i] - '0']--;
    string sub = string(buf);
    for(int t = 1; t <= 1e6; t++) {
        sprintf(buf, "%d", t);
        int len = strlen(buf);
        bool flag = true;
        for(int i = 0; i < len; i++) cnt[buf[i] - '0']--;
        for(int i = 0; i < 10; i++) if(cnt[i] < 0) flag = false;
        flag &= (w - len == t);
        if(flag) {
            string ans = "";
            if(sub[0] != '0') {
                ans = sub;
                for(int i = 0; i < 10; i++)
                    for(int j = 0; j < cnt[i]; j++)
                        ans.push_back(i + '0');
            }
            string p("");
            for(int i = 1; i < 10; i++) if(cnt[i]) {
                p.push_back(i + '0');
                cnt[i]--;
                break;
            }
            if(p.size()) {
                string p1 = p;
                for(int i = 0; i < sub[0] - '0'; i++)
                    for(int j = 0; j < cnt[i]; j++)
                        p1.push_back(i + '0');
                p1 += sub;
                for(int i = sub[0] - '0'; i < 10; i++)
                    for(int j = 0; j < cnt[i]; j++)
                        p1.push_back(i + '0');

                for(int i = 0; i <= sub[0] - '0'; i++)
                    for(int j = 0; j < cnt[i]; j++)
                        p.push_back(i + '0');
                p += sub;
                for(int i = sub[0] - '0' + 1; i < 10; i++)
                    for(int j = 0; j < cnt[i]; j++)
                        p.push_back(i + '0');

                check(ans, p);
                check(ans, p1);
            }
            if(ans.size()) {printf("%s", ans.c_str()); return 0;}
        }
        for(int i = 0; i < len; i++) cnt[buf[i] - '0']++;
    }
    return 0;
}

