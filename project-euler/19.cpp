#include <bits/stdc++.h>
using namespace std;

int m0[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int m1[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int x) {
    if(x % 4 == 0 && x % 100 != 0) return true;
    return x % 400 == 0;
}

int get_mo(int y, int m) {
    if(leap[y]) return m1[m];
    return m0[m];
}

int cal_sunday(int yy, int mm, int dd) {
    int y = 1900, m = 1, d = 1, s = 0, ans = 0;
    do{
        int M = get_mo(y, m);
        d++;
        if(d > M) {
            d = 1;
            m++;
            if(m > 12) {
                y++;
                m = 1;
            }
        }
        s++;
        if(s % 7 == 0 && d == 1) {
            ans++;
        }
    } while(y != yy || m != mm || d != dd);
    return ans;
}


int main() {
    printf("%d\n", cal_sunday(2000, 12, 31) - cal_sunday(1900, 12, 31));
    return 0;
}
