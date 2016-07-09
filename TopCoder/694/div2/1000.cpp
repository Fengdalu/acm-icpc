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

class UpDownNess {
public:
	int count(int, int);
};
typedef long long ll;
ll dp[60][6000];
const ll mod = 1e9 + 7;
int UpDownNess::count(int N, int K) {
	if(N <= 2 && K != 0) return 0;
	memset(dp, 0, sizeof dp);
	dp[1][0] = 1;
	dp[2][0] = 2;
	for(int i = 2; i <= N; i++) {
		for(int j = 0; j <= 5000; j++) {
			for(int k = 0; k <= i; k++) {
				ll add = k * (i - k);
				if(add + j > 5000) continue;
				dp[i + 1][add + j] = (dp[i + 1][add + j] + dp[i][j]) % mod;
			}
		}
	}
	return dp[N][K];
}


//Powered by [KawigiEdit] 2.0!
