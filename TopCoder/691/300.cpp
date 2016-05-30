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
#include <cstring>

using namespace std;

class Sunnygraphs {
public:
	long long count(vector <int>);
};
typedef long long ll;
vector<int>aa;
ll s[100];
ll u[100];
ll c[100];

void dfs(int x, int i) {
	u[x] = i;
	c[x] |= 1 << (i - 1);
	if(u[aa[x]] != i) dfs(aa[x], i);
}


long long Sunnygraphs::count(vector <int> a) {
	aa = a;
	dfs(0, 1);
	dfs(1, 2);
	for(int i = 0; i < a.size(); i++) s[c[i]]++;
	ll r = (1LL << s[0]) * ((1LL << s[1]) - 1) * ((1LL << s[2]) - 1);
	r += ((1LL << s[3]) - 1) * (1LL << (a.size() - s[3]));
	if(s[3]) r += (1LL << s[0]);
	return r;
}


//Powered by [KawigiEdit] 2.0!
