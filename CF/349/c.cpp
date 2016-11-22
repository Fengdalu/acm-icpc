#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iostream>
using namespace std;

char buf[100010];
set<string>f[100010];
set<string>q;
set<string>::iterator it;
int main() {
    scanf("%s", buf);
    string s(buf);
    if(s.size() - 2 > 4)  {
        q.insert(s.substr(s.size() - 2, 2));
        f[s.size() - 2].insert(s.substr(s.size() - 2, 2));
    }
    if(s.size() - 3 > 4) {
        q.insert(s.substr(s.size() - 3, 3));
        f[s.size() - 3].insert(s.substr(s.size() - 3, 3));
    }
    for(int i = s.size() - 1; i > 4; i--) {
        string a;
        if(i + 2 > s.size()) continue;
        a = s.substr(i, 2);
        if(f[i + 2].size() == 2 || f[i + 2].size() && f[i + 2].count(a) == 0)  {
            f[i].insert(a);
            q.insert(a);
        }
        if(i + 3 > s.size()) continue;
        a = s.substr(i, 3);
        if(f[i + 3].size() == 2 || f[i + 3].size() && f[i + 3].count(a) == 0)  {
            f[i].insert(a);
            q.insert(a);
        }
    }
    cout << q.size() << endl;
    for(it = q.begin(); it != q.end(); it++) printf("%s\n", it->c_str());
    return 0;
}
