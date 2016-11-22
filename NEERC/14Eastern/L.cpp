#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

char buf[100];

int BL(string s) {
    if(s[0] == 'A' || s[0] == 'P' || s[0] == 'R' || s[0] == 'O') return 1;
    if(s[0] == 'B' || s[0] == 'M' || s[0] == 'S') return 2;
    return 3;
}



int main() {
    int n, ans = 0, p = 1;
    scanf("%d", &n);
    while(n--){
        scanf("%s", buf);
        int t = BL(string(buf));
        ans += abs(p - t);
        p = t;
    }
    printf("%d\n", ans);
    return 0;
}
