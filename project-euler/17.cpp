#include <bits/stdc++.h>

using namespace std;

//          zero one two three four five six seven eight nine ten
int f[11]  = {0,   3,  3,  5,    4,   4,   3,  5,    5,    4,   3};
//          eleven twelve thirteen fourteen fifteen sixteen seventeen, eighteen nineteen twenty
int f1[10] = {6,     6,     8,       8,       7,      7,      9,         8,       8,       6};
//          twenty thirty forty fifty sixty seventy eighty ninety
int f3[8] = {6,     6,     5,    5,    5,    7,      6,     6};
// hundred=7
// and=3
// one thousand=11
int cal(int x) {
    if(x <= 10) return f[x];
    if(x <= 20) return f1[x-11];
    if(x < 100) {
        if(x % 10 == 0) return f3[x/10-2];
        return f3[x/10-2] + f[x%10];
    }
    if(x < 1000 && x % 100 == 0) return f[x/100] + 7;
    if(x < 1000) return f[x/100] + 10 + cal(x % 100);
    if(x == 1000) return 11;
    exit(-1);
}

int main() {
    int ans = 0;
    for(int i = 1; i <= 1000; i++) {
        ans += cal(i);
    }
    printf("%d\n", ans);
    return 0;
}
