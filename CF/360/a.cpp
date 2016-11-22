#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int t = 0;
    int ans = 0;
    int cur = 0;
    while(d--) {
        string s;
        cin >> s;
        if(s.find("0") == s.npos)  {
            cur = 0;
        }
        else cur++;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}
