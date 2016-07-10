#include <bits/stdc++.h>
using namespace std;

char buf[10000];
int main() {
    int T;
    scanf("%d", &T);
    int ii = 0;
    while(T--) {
        vector<pair<int, string> >f;
        int n;
        scanf("%d\n", &n);
        while(n--) {
            string s;
            gets(buf);
            s = string(buf);
            set<char>p;
            for(int i = 0; i < s.size(); i++)
                if(s[i] != ' ') p.insert(s[i]);
            f.push_back(make_pair(-p.size(), s));
        }
        sort(f.begin(), f.end());
        cout << "Case #" << ++ii << ": " << f[0].second << endl;
    }
    return 0;
}
