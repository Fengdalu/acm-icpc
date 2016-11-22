#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long

LL m1, m2, m3, m4, m5;
LL w1, w2, w3, w4, w5;
LL hs, hu;

int main() {
    cin >> m1 >> m2 >> m3 >> m4 >> m5;
    cin >> w1 >> w2 >> w3 >> w4 >> w5;
    cin >> hs >> hu;
    LL ans = 0;
    ans += max(3 * 50LL, (250 - m1) * 2 - 50 * w1);
    ans += max(3 * 100LL, (250 - m2) * 4 - 50 * w2);
    ans += max(3 * 150LL, (250 - m3) * 6 - 50 * w3);
    ans += max(3 * 200LL, (250 - m4) * 8 - 50 * w4);
    ans += max(3 * 250LL, (250 - m5) * 10 - 50 * w5);
    ans += hs * 100;
    ans -= hu * 50;
    cout << ans << endl;
    return 0;
}
