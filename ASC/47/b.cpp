#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll n, k;
    //freopen("borderless.in", "r", stdin);
    //freopen("borderless.out", "w", stdout);
    while(cin >> n >> k) {
        if(!n && !k) break;
        k--;
        string s("");
        bool flag = false;
        if(k >= (1 << (n - 2)))  {
            flag = true;
            k -= (1 << (n - 2));
        }
        for(int i = 0; i < (n - 2); i++) {
            if(1LL << i & k) s = "b" + s;
            else s = "a" + s;
        }
        if(flag) {
            cout << "b" << s << "a" << endl;
        }
        else cout << "a" << s << "b" << endl;
    }
    return 0;
}
