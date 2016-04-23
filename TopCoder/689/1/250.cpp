#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

class ColorfulGarden {
public:
    vector <string> rearrange(vector <string>);
};

vector <string> ColorfulGarden::rearrange(vector <string> garden) {
    string a = garden[0], b = garden[1];
    vector<char>s;
    int c['z' + 1];
    memset(c, 0, sizeof c);
    for(int i = 0; i < a.size(); i++) c[a[i]]++;
    for(int i = 0; i < b.size(); i++) c[b[i]]++;
    vector<pair<int, char> >q;
    for(char i = 'a'; i <= 'z'; i++)
        if(c[i]) {
            q.push_back(make_pair(c[i], i));
        }
    sort(q.begin(), q.end());
    reverse(q.begin(), q.end());
    for(int i = 0; i < q.size(); i++)
        for(int j = 0; j < q[i].first; j++)
            s.push_back(q[i].second);
    string ans[2];
    ans[0] = ans[1] = a;
    int j = 0;
    for(int i = 0; i < a.size(); i++) {
        ans[i % 2][i] = s[j++];
    }
    for(int i = 0; i < a.size(); i++) {
        ans[(i + 1) % 2 ][i] = s[j++];
    }
    vector<string>p;
    for(int i = 0; i < a.size(); i++) {
        if(ans[0][i] == ans[1][i] || ans[0][i + 1] == ans[0][i] || ans[1][i] == ans[1][i + 1]) return p;
    }
    p.push_back(ans[0]);
    p.push_back(ans[1]);
    return p;
}


//Powered by [KawigiEdit] 2.0!