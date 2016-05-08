#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int ii = 1; ii <= T; ii++) {
        int n;
        cin >> n;
        set<pair<int, int> >s;
        int tot = 0;
        for(int i = 0; i < n; i++) {
            int p;
            cin >> p;
            s.insert(make_pair(-p, i));
            tot += p;
        }
        string t("");
        cout << "Case #" << ii << ": ";
        while(s.size()) {
            pair<int, int>x = *s.begin();
            s.erase(s.begin());
            t.push_back(x.second + 'A');
            x.first++;
            if(x.first) {
                s.insert(x);
            }
            tot--;
            if(-s.begin()->first * 2 <= tot) {
                cout << t << " ";
                t = "";
            }
        }
        if(t.size()) cout << t;
        cout << endl;
    }
    return 0;
}


