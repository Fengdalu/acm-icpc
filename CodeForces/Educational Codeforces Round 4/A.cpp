#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string s;
int n, p, q;

int main() {
    cin >> n >> p >> q;
    cin >> s;
    for(int i = 0; i * p <= n; i++) if((n - i * p) % q == 0) {
        int t = 0;
        int j = (n - i * p) / q;
        cout << i + j << endl;
        for(int k = 0; k < i; k++) {
            cout << s.substr(t, p) << endl;
            t += p;
        }
        for(int k = 0; k < j; k++) {
            cout << s.substr(t, q) << endl;;
            t += q;
        }
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
