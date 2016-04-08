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

class AlmostFibonacciKnapsack {
public:
    vector <int> getIndices(long long);
};

long long a[2000];
vector <int> AlmostFibonacciKnapsack::getIndices(long long x) {
    a[1] = 2;
    a[2] = 3;
    int cnt = 3;
    while(a[cnt - 1] <= 1e18) {
        a[cnt] = a[cnt - 1] + a[cnt - 2] - 1;
        cnt++;
    }
    vector<int>b;
    while(cnt-- > 1) {
        if(x >= a[cnt] && a[cnt] != x - 1) {
            x -= a[cnt];
            cout << cnt << endl;
            b.push_back(cnt);
        }
    }
    if(x) {
        b.clear();
        b.push_back(-1);
        return b;
    }
    return b;
}


//Powered by [KawigiEdit] 2.0!