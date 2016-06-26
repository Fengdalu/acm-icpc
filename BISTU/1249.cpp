#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char buf[10];
bool dig(char c) {
    return '0' <= c && c <= '9';
}
bool check(char buf[])  {
    if(strlen(buf) != 5) return false;
    if(!dig(buf[0]) || !dig(buf[1]) || !dig(buf[3]) || !dig(buf[4])) return false;
    if(buf[2] != ':') return false;
    return true;
}
int main() {
    int _T;
    scanf("%d", &_T);
    while(_T--) {
        bool flag = true, flag1 = true, flag2 = true;
        scanf("%s", buf);
        flag &= !strcmp(buf, "beginner")
        || !strcmp(buf, "middle")
        || !strcmp(buf, "higher");
        double lv = 0;
        if(buf[0] == 'b') lv = 10;
        else if(buf[0] == 'm') lv = 11;
        else if(buf[0] == 'h') lv = 12;

        int h0, m0, h1, m1;
        scanf("%s", buf);
        sscanf(buf, "%d:%d", &h0, &m0);
        flag1 &= check(buf);
        scanf("%s", buf);
        sscanf(buf, "%d:%d", &h1, &m1);
        flag1 &= check(buf);
        int l = 60 * h0 + m0, r = h1 * 60 + m1;
        if(l >= r || l >= 1440 || r >= 1440) {
            flag1 = false;
        }
        if(m0 >= 60 || m1 >= 60 || h0 > 23 || h1 > 23) {
            flag1 = false;
        }
        double base = min(r, 1320) - l;
        double add = max(r, 1320) - 1320;
        scanf("%s", buf);
        flag2 &= !strcmp(buf, "weekend")
        || !strcmp(buf, "workday");
        double tot;
        if(buf[1] == 'e')  {
            tot = (1.5 * base * lv + 2 * add * lv) / 60;
        }
        else
            tot = (base * lv + add * lv + add * lv * 0.5) / 60;
        if(flag && flag1 && flag2) {
            printf("%.2f\n", tot);
        }
        else if(!flag) puts("Wrong class!");
        else if(!flag1) puts("Wrong time!");
        else puts("Wrong days!");
    }
    return 0;
}
