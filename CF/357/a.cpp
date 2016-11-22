#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    string s;
    int a, b;
    int n;
    bool flag = false;
    cin >> n;
    while(n--) {
        cin >> s >> a >> b;
        if(a >= 2400) {
            if(b > a) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}
