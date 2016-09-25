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
int n, ans;
class WhiteSpaceEditing
{
public:

    int getMinimum (vector <int> li)
    {
        VI g;
        g.PB(0);
        for(int i = 0; i< li.SZ; i++) g.PB(li[i]);
        n = g.SZ;
        int ret = 0;
        for(int i = 1; i < n; i++) {
            ret += max(0, g[i] - g[i - 1]);
        }
        ret += n - 2;
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
			int lines[]               = { 3, 2, 3 };
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int lines[]               = { 0 };
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int lines[]               = { 1, 2, 4 } ;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int lines[]               = { 250, 105, 155, 205, 350 } ;
			int expected__            = 499;

			clock_t start__           = clock();
			int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int lines[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int lines[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int lines[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
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
