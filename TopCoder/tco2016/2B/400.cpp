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

class TriangleTriples {
public:
	int count(int, int, int);
};

typedef long long ll;
ll mod = 1e9 + 7;
ll qpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}

ll cal(ll p) {
	if(p <= 0) return 0;
	return (qpow(p, 3) - p + mod) * qpow(6, mod - 2) % mod;
}

ll f(ll A, ll B, ll C) {
	return (((cal(A) - cal(A - B)) % mod - cal(A - C)) % mod + cal(A - B - C)) % mod;
}

int TriangleTriples::count(int A, int B, int C) {
	ll tot = (ll)A * B % mod * C % mod;
	ll s = f(C, A, B);
	s = (s + f(A, B, C)) % mod;
	s = (s + f(B, A, C)) % mod;
	return ((tot - s) % mod + mod) % mod;
}


//Powered by [KawigiEdit] 2.0!
