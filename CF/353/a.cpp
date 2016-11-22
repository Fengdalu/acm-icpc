#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    if(a == b) cout << "YES";
    else if(c == 0) cout << "NO";
    else if(a > b && c > 0) cout << "NO";
    else if(a < b && c < 0) cout << "NO";
    else if((b - a) % c == 0) cout << "YES";
    else cout << "NO";
}
