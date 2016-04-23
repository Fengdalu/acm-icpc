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
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class MultiplicationTable3 {
public:
    vector <int> construct(int);
};

vector <int> MultiplicationTable3::construct(int x) {
    int f[100][100];
    int k = 0;
    f[0][0] = 0;
    vector<int>q;
    queue<int>p;
    while(x) {
        q.push_back(x % 2);
        x /= 2;
    }
    reverse(q.begin(), q.end());
    for(int i = 1; i < q.size(); i++) {
        p.push(0);
        if(q[i] == 1) p.push(1);
    }
    
    while(p.size()) {
        int mask = p.front();
        cout << mask << endl;
        p.pop();
        if(mask == 0) {
            k++;
            for(int i = 0; i <= k; i++) f[i][k] = i;
            for(int i = 0; i <= k; i++) f[k][i] = i;
            f[k][k] = 0;
        }
        else {
            k++;
            for(int i = 0; i < k; i++)
                f[i][k] = f[k][i] = i + 1;
            for(int i = 0; i < k; i++)
                f[k][i] = i + 1;
            f[k][k] = 0;
        }
    }
    vector<int>ans;
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= k; j++) {
            cout << f[i][j] << " ";
            ans.push_back(f[i][j]);
        }
        cout << endl;
    }
    return ans;
}


//Powered by [KawigiEdit] 2.0!