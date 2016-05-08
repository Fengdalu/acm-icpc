#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s("a");
    for(int i = 0; i < n / 25; i++)
    if(i % 2 == 0) s.push_back('z');
    else s.push_back('a');

    if(s.length() == 1 || n == 25) {
        if(n != 25)s.push_back('a' + n);
        cout << s << endl;
    }
    else if(s.length() == 2) {
        s[1] = 'a' + (n + 1) / 2;
        s.push_back(s[1] - (n - (n + 1) / 2));
        cout << s << endl;
    }
    else if(n % 25 == 0) {
        cout << s << endl;
    }
    else {
        int left = n % 25;
        string ans = s;
        if(s[s.size() - 1] == 'a') ans.push_back('a' + n % 25);
        else ans.push_back('z' - n % 25);
        for(char c = 'a'; c < 'z' + 1; c++) {
            int tot = 'z' - c;
            tot *= 2;
            tot += left;
            if(tot <= 25) {
                string t = s;
                t[1] = c;
                if(t[t.size() - 1] == 'a')
                   t.push_back('a' + tot);
                else t.push_back('z' - tot);
                ans = min(ans, t);
            }
        }
        cout << ans << endl;
    }
}
