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

using namespace std;

class BearBall {
public:
    int countThrows(vector <int>, vector <int>);
};

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

typedef pair<int, int> pii;

vector<int>a, b;
int n;
map<pair<int, int>, int>f;
pair<int, int>s[4000000];
int cnt;


int BearBall::countThrows(vector <int> x, vector <int> y) {
    a = x;
    b = y;
    n = x.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        map<pair<int, int>, int>f;
        map<pair<int, int>, int>::iterator it;
        for(int j = 0; j < n; j++) if(i != j) {
            pii slp = make_pair(a[j] - a[i], b[j] - b[i]);
            int g = gcd(abs(slp.first), abs(slp.second));
            slp.first /= g; slp.second /= g;
            f[slp]++;
        }
        if(f.size() == 1) ans += f.begin()->second * (f.begin()->second + 1) / 2;
        else if(f.size() == 2 && f.begin()->first.first == -1 * f.rbegin()->first.first && f.begin()->first.second == -1 * f.rbegin()->first.second) {
            cout << "ok" << endl;
            ans += f.begin()->second * (f.begin()->second + 1) / 2;
            ans += f.rbegin()->second * (f.rbegin()->second + 1) / 2;
        }
        else {
            ans += n - 1;
            for(it = f.begin(); it != f.end(); it++) ans += it->second - 1;
        }
    }
    return ans;
}

//Powered by [KawigiEdit] 2.0!
