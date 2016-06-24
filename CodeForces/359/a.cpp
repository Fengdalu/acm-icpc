#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    int n; ll x;
    cin >> n >> x;
    string op;
    int c2 = 0;
    while(n--) {
        ll o;
        cin >> op >> o;
        if(op == "+")  x += o;
        else {
            if(x < o) c2++;
            else x -= o;
        }
    }
    cout << x << " " << c2;
    return 0;
}
