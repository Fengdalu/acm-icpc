#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define LL long long

PII s[200010];
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i].AA;
        s[i].BB = i + 1;
    }
    sort(s, s + n);
    LL ans = 0;
    int p = s[0].BB;
    for(int i = 1; i < n; i++) {
        ans += (LL)abs(p - s[i].BB);
        p = s[i].BB;
    }
    cout << ans << endl;
}
