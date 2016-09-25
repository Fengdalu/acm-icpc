// BEGIN CUT HERE
/*

*/
// END CUT HERE
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
using namespace std;
 
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SZ size()
#define SQ(x) ((x)*(x))
#define SORT(p) sort(p.BGN,p.ED)
#define MEM(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef queue<int> QI;
typedef deque<int> DQI;
typedef set<int> SI;
typedef vector<PII> VII;
typedef queue<PII> QII;
typedef deque<PII> DQII;
typedef set<PII> SII;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef vector<LL> VL;
typedef queue<LL> QL;
typedef deque<LL> DQL;
typedef set<LL> SL;
typedef vector<PLL> VLL;
typedef queue<PLL> QLL;
typedef deque<PLL> DQLL;
typedef set<PLL> SLL;
#define Maxn 5111
#define Maxm 5555
const LL MOD = 1000000007LL;
class SumOverPermutations
{
public:
    int n, m;
    LL dp[Maxn][2];
    LL inv[Maxn];
    inline LL modadd(LL & x, LL y) {
	x = (x + y) % MOD;
	return x;
    }
    int findSum (int n)
    {
        LL ret = 0;
        int i, j, u, v, w;
	for(inv[1]=1,i=2;i<5000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;//MOD is prime
        dp[1][0] = n; dp[1][1] = 0;
	dp[2][0] = 0; dp[2][1] = 2 * n * (n - 1);
	for(i = 3; i <= n; ++i) {
	    dp[i][0] = dp[i][1] = 0;
	    //i first
	    modadd(dp[i][0], n * (n - 1) * dp[i - 1][0] % MOD * inv[n] % MOD);
	    modadd(dp[i][0], n * (n - 2) * dp[i - 1][1] % MOD * inv[n - 1] % MOD);
	    //i last
	    modadd(dp[i][1], (n - 1) * dp[i - 1][0] % MOD);
	    modadd(dp[i][1], (n - 1) * dp[i - 1][1] % MOD);
	    //
	    for(j = 1; j < i - 1; ++j) {
		modadd(dp[i][1], (n - 1) * dp[i - 1][0] % MOD);
		modadd(dp[i][1], (n - 1) * dp[i - 1][1] % MOD);
		modadd(dp[i][0], n * (n - 1) % MOD * dp[i - 1][0] % MOD * inv[n] % MOD);
		modadd(dp[i][0], n * (n - 2) % MOD * dp[i - 1][1] % MOD * inv[n - 1] % MOD);
	    }
	}
	for(i = 1; i <= n; ++i) {
	    cerr << dp[i][0] << " " << dp[i][1] << " " << dp[i][0] + dp[i][1] << endl;
	}
	ret = (dp[n][0] + dp[n][1]) % MOD;
        return int(ret);
    }
};
 
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int n                     = 2;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = SumOverPermutations().findSum(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 3;
			int expected__            = 66;

			std::clock_t start__      = std::clock();
			int received__            = SumOverPermutations().findSum(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 10;
			int expected__            = 58310114;

			std::clock_t start__      = std::clock();
			int received__            = SumOverPermutations().findSum(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 3900;
			int expected__            = 940560814;

			std::clock_t start__      = std::clock();
			int received__            = SumOverPermutations().findSum(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SumOverPermutations().findSum(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SumOverPermutations().findSum(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SumOverPermutations().findSum(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

 
#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
