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

class Quorum {
public:
    int count(vector <int>, int);
};

int Quorum::count(vector <int> arr, int k) {
    sort(arr.begin(), arr.end());
    int tot = 0;
    for(int i = 0; i < k; i++) tot += arr[i];
    return tot;
}


//Powered by [KawigiEdit] 2.0!