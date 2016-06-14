#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    for(int b = 0; 123456 * b <= n; b++) {
        int left = n - b * 123456;
        for(int a = 0; 1234567 * a <= left; a++)
            if((left - a * 1234567) % 1234 == 0) {
                cout << "YES";
                return 0;
            }
    }
    cout << "NO";
    return 0;
}
