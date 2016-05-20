#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int a, b, d, n;
    while(cin >> a >> b >> d >> n) {
        if(a * b < 10) cout << (int)(d == a * b) * n << endl;
        else {
            int x = a * b / 10;
            int y = a * b % 10;
            int ans = 0;
            if(x + y < 10 || n == 1) {
                if(d == x) ans++;
                if(d == y) ans++;
                if(d == x + y) ans += n - 1;
            }
            else {
                int z = (x + y) % 10;
                int q = (z + 1) % 10;
                x++;
                if(d == z)  ans++;
                if(d == x) ans++;
                if(d == y) ans++;
                if(d == q) ans += max(0, n - 2);
            }
            cout << max(0, ans) << endl;
        }
    }
    return 0;
}
