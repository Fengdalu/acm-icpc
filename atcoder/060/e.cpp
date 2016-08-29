#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>
using namespace std;

typedef long long ll;

ll cal(ll x, ll b) {
    ll t = x;
    ll sum = 0;
    while(t != 0) {
        sum += t % b;
        t /= b;
    }
    return sum;
}

int main() {
    ll n, s;
    cin >> n >> s;
    for(int i = 2; i < 2e7; i++)
        if(cal(n, i) == s) {
            cout << i << endl;
            exit(0);
        }
    cout << -1 << endl;
}
