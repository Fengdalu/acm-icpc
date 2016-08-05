#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 0, b = 0;
    int n; cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;
        a += 1*(x > y); b += 1*(y > x);
    }
    if(a == b) cout << "Friendship is magic!^^";
    else if(a > b) cout << "Mishka";
    else cout << "Chris";
}
