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

class MakingPairs {
public:
	int get(vector <int>);
};

int MakingPairs::get(vector <int> card) {
	long long ans = 0;
	for(int i = 0; i < card.size(); i++) ans += card[i] / 2;
	return ans;
}


//Powered by [KawigiEdit] 2.0!
