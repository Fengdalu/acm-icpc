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
#define ED end()
#define SZ size()
#define SORT(p) sort(p.BGN,p.ED)
#define CLR(a, b) memset(a, (b), sizeof(a))
typedef long long LL;
typedef pair<int, int> PII;


class Starport
{
public:
    double getExpectedTime (int N, int M)
    {
        double ret;
        LL gcd = __gcd((LL)N, (LL)M);
        LL n = N / gcd, m = M / gcd;
        ret = 1.0 * gcd * (0.0 + 1.0 * ( n - 1)) / 2;
        return double(ret);
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

	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }

	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if ( topcoder_fequ( expected, received ) ) {
			verdict = "PASSED";
			double rerr = moj_relative_error( expected, received );
			if ( rerr > 0 ) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int N                     = 4;
			int M                     = 2;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 5;
			int M                     = 3;
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 6;
			int M                     = 1;
			double expected__         = 2.5;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 12345;
			int M                     = 2345;
			double expected__         = 6170.0;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int M                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int N                     = ;
			int M                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			int M                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
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
