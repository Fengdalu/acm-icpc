#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define LL long long
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()

int d;
char buf[10], buf1[10];
int main() {
    scanf("%d%s%s", &d, buf, buf1);
    if(buf1[0] == 'w') {
        int st;
        if(d == 5) st = 1;
        else if(d == 6) st = 2;
        else if(d == 7) st = 3;
        else st = d + 3;
        int ans = 0;
        while(st <= 366) {
            st += 7;
            ans++;
        }
        cout << ans << endl;
    }
    else {
        int ans;
        if(d <= 29) ans = 12;
        else if(d <= 30) ans = 11;
        else ans = 7;
        cout << ans << endl;
    }
    return 0;
}
