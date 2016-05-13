#include <cstdio>
#include <cstring>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

string s;
int main() {
    getline(cin, s);
    istringstream in(s);
    int n(0);
    int a(0), b(0);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '+') a++;
        else if(s[i] == '-') b++;
        else if('0' <= s[i] && s[i] <= '9') n = n * 10 + (s[i] - '0');
    }
    if(a == 0 && b == 0) {
        cout << "Possible" << endl;
        cout << n << " = " << n << endl;
    }
    else if(a == 0 && b > 0) cout << "Impossible";
    else if(a > 0 && b == 0) {
        if(n == 1 && a == 1) cout << "Impossible";
        else if(a + 1 > n)  cout << "Impossible";
        else {
            cout << "Possible" << endl;
            cout << n - a;
            for(int i = 0; i < a; i++) {
                cout << " + " << 1;
            }
            cout << " = " << n << endl;
        }
    }
    else {
        queue<int>p, q;
        int tot = 0;
        for(int i = 0; i < min(a, b); i++) { q.push(1); p.push(1); }
        int t = min(a, b);
        a -= t; b -= t;
        if(a > 0) {
            for(int i = 0; i < a; i++) q.push(1);
            tot = a;
            while(tot && p.front() != n) {
                p.pop();
                tot++;
                int k = min(n, tot);
                tot -= k;
                p.push(k);
            }
        }
        else if(b > 0) {
            for(int i = 0; i < b; i++) p.push(1);
            tot = b;
            while(tot && q.front() != n)  {
                q.pop();
                tot++;
                int k = min(n, tot);
                tot -= k;
                q.push(k);
            }
        }
        if((a > 0 && n - tot <= 0) || (b > 0 && tot)) {
            cout << "Impossible" ;
            return 0;
        }
        cout << "Possible" << endl;
        cout << n - tot;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '+') { cout << " + " << q.front(); q.pop();  }
            else if(s[i] == '-'){ cout << " - " << p.front(); p.pop(); }
        }
        cout << " = " << n << endl;
    }
    return 0;
}
