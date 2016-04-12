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
#include <queue>

using namespace std;

class ReplacingDigit {
public:
    int getMaximumStockWorth(vector <int>, vector <int>);
};

int ReplacingDigit::getMaximumStockWorth(vector <int> A, vector <int> D) {
    vector<int>q[10];
    for(int i = 0; i < A.size(); i++) {
        int j = 0, x = A[i];
        while(x) {
            q[j].push_back(x % 10);
            x /= 10;
            j++;
        }
    }
    for(int i = 0; i < 10; i++)
        if(q[i].size())sort(q[i].begin(), q[i].end());
    int tot = 0;
    priority_queue<int>p;
    for(int i = 0; i < D.size(); i++)
        for(int j = 0; j < D[i]; j++)
            p.push(i + 1);
    for(int i = 9; i >= 0; i--)
        if(p.size()) {
            for(int j = 0; j < q[i].size(); j++)
                if(p.size() && p.top() > q[i][j]) {
                    q[i][j] = p.top();
                    p.pop();
                }
        }
    int ans = 0;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < q[i].size(); j++)
            ans += pow(10, i) * q[i][j];
    return ans;
}


//Powered by [KawigiEdit] 2.0!