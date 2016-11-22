#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long

int n;
string s;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        int len = s.length() - 1;
        if(s[len] == 'o' || s[len] == 's' || s[len] == 'x' || (len >= 1 && s[len - 1] == 'c' && s[len] == 'h') ) cout << s << "es" << endl;
        else if(s[len] == 'f') cout << s.substr(0, s.length() - 1) << "ves" << endl;
        else if(len >= 1 && s[len - 1] == 'f' && s[len] == 'e') cout << s.substr(0, s.length() - 2) << "ves" << endl;
        else if(len >= 1 && s[len] == 'y') cout << s.substr(0, s.length() - 1) << "ies" << endl;
        else cout << s << "s" <<endl;
    }
    fclose(stdout);
    return 0;
}
