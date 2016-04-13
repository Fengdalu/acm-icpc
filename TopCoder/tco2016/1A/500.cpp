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

class EllysSocks {
public:
    int getDifference(vector <int>, int);
};

bool vis[2000];
int EllysSocks::getDifference(vector <int> S, int P) {
    sort(S.begin(), S.end());
    int l = 0, r = 1e9 + 7;
    while(l < r)  {
        int mid = (l + r) /2;
        memset(vis, 0, sizeof vis);
        int tot = 0;
        for(int i = 0; i < S.size(); i++)
            if(!vis[i])
                for(int j = i + 1; j < S.size(); j++)
                    if(!vis[j] && S[j] - S[i] <= mid) {
                        tot++;
                        vis[i] = vis[j] = true;
                        break;
                    }
        if(tot >= P) r = mid;
        else l = mid + 1;
    }
    return l;
}


//Powered by [KawigiEdit] 2.0!