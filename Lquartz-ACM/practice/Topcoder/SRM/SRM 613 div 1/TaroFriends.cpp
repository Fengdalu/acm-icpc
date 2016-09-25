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
#define MP make_pair
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SZ size()
#define SORT(p) sort(p.BGN,p.ED)
#define CLR(a, b) memset(a, (b), sizeof(a))
#define mabs(x) (x < 0 ? -x : x)
#define sqr(x) ((x)*(x))
#define ITE ::iterator
typedef long long LL;
typedef pair<int, int> PII;
typedef vector <int> VI;
typedef set < int > SI;

class TaroFriends
{
public:
    int getNumber (vector <int> c, int X)
    {
        int n = c.SZ;
        int ret = (1 << 30);
        sort(c.BG, c.ED);
        for(int i = 0; i < n; i++) {
            int dmax = -(1<<28);
            int dmin = -dmax;
            for(int j = 0; j < n; j++) {
                int x = c[j] + X * (j <= i ? 1 : -1);
                dmax = max(x, dmax);
                dmin = min(x, dmin);
            }
            ret = min(ret, dmax - dmin);
        }
        return (int)(ret);
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
			int coordinates[]         = {-3, 0, 1};
			int X                     = 3;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int coordinates[]         = {4, 7, -7};
			int X                     = 5;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int coordinates[]         = {-100000000, 100000000};
			int X                     = 100000000;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int coordinates[]         = {3, 7, 4, 6, -10, 7, 10, 9, -5};
			int X                     = 7;
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int coordinates[]         = {-4, 0, 4, 0};
			int X                     = 4;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int coordinates[]         = {7};
			int X                     = 0;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			int coordinates[]         = {106, 347, -103, -482, 807, -507, -485, -582};
			int X                     = 832;
			int expected__            = 1204;

			std::clock_t start__      = std::clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int coordinates[]         = ;
			int X                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int coordinates[]         = ;
			int X                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
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
