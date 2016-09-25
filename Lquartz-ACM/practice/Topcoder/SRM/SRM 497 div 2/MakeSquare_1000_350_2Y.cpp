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
#define BGN begin()
#define END end()
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

int dp[55][55];
string s1, s2;
class MakeSquare
{
public:
    int doit(int n, int m) {
        if(dp[n][m] >= 0) return dp[n][m];
        int ret = 1000;
        if(s1[n] == s2[m]) {
            if(n != 0 && m != 0)
                ret = min(ret, doit(n - 1, m - 1));
        }
        {
            if(n != 0)
                ret = min(ret, doit(n - 1, m) + 1);
            if(n != 0 && m != 0)
                ret = min(ret, doit(n - 1, m - 1) + 1);
            if(m != 0)
                ret = min(ret, doit(n, m - 1) + 1);
        }
        return (dp[n][m] = ret);
    }
    int minChanges (string S)
    {
        int ret = S.length();
//        cout << S << endl;
        for(int i = 1; i < S.length(); i++) {
            s1 = '*' + S.substr(0, i);
            s2 = '*' + S.substr(i, S.length());
            memset(dp, -1, sizeof(dp));
            dp[0][0] = 0;
            int temp = doit(s1.length() - 1, s2.length() - 1);
//            cout << s1 << " " << s2 << " " << temp << endl;
            ret = min(ret, temp);
        }
        return (int)(ret);
    }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 && !quiet )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}

		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}

		if ( total == 0 ) {
			cerr << "No test cases run." << endl;
		} else if ( correct < total ) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}

	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;

		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl;
			cerr << "    Received: " << received << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string S                  = "abcdabgcd";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MakeSquare().minChanges( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string S                  = "abcdeabce";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MakeSquare().minChanges( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string S                  = "abcdeabxde";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MakeSquare().minChanges( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string S                  = "aabcaabc";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MakeSquare().minChanges( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string S                  = "aaaaabaaaaabaaaaa";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MakeSquare().minChanges( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			string S                  = "a";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MakeSquare().minChanges( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
      case 6: {
			string S                  = "aaa";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MakeSquare().minChanges( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MakeSquare().minChanges( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
