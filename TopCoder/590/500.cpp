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
typedef long long ll;
class XorCards {
public:
	long long numberOfWays(vector<ll>, long long);
};

int a[60][60];
long long detect(vector<ll>f, ll b) {
	ll tot = 1;
	int n = 60, m = f.size();
	for(int i = 0; i < 60; i++)
		for(int j = 0; j < m; j++) a[i][j] = (f[j] >> i) & 1;
	for(int i = 0; i < 60; i++) a[i][m] = (b >> i) & 1;
	int line = 0;
	for(int i = 0; i < m; i++) {
		int target = line;
		while(target < n && a[target][i] == 0) target++;
		if(target == n) { tot *= 2LL; continue; }
		for(int j = 0; j <= m; j++) swap(a[target][j], a[line][j]);
		for(int j = 0; j < n; j++)
		if(a[j][i] != 0 && j != line) {
			for(int k = 0; k <= m; k++)
				a[j][k] ^= a[line][k];
		}
		line++;
	}
	for(int j = line; j < n; j++)
	if(a[j][m] != 0) return 0;
	return tot;
}

long long XorCards::numberOfWays(vector<ll> number, long long limit) {
	ll ans;
	ans = detect(number, limit);
	cout << endl;
	cout << ans << endl;
	for(int i = 0; i < 60; i++)
	if(1LL << i & limit) {
		ll b = (limit >> (i + 1)) << (i + 1);
		vector<ll>f = number;
		for(int j = 0; j < f.size(); j++) {
			f[j] = (f[j] >> (i)) << (i);
		}
		cout << i << " " << ans << endl;
		ans = ans + detect(f, b);
	}
	return ans;
}


//Powered by [KawigiEdit] 2.0!
