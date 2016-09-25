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

int n;
double all, p, q;
int L, R;

class AlternatingLane
{
public:
    double expectedBeauty (vector <int> low, vector <int> high)
    {
        double ret = 0.0;
        n = low.SZ;
        for(int ii = 0; ii < n - 1; ii++) {
//            cout << ii << endl;
            p = 0;
            L = low[ii + 1]; R = high[ii + 1];
            for(int i = low[ii]; i <= high[ii]; i++) {

                if(L >= i) {
                    p += 1.0 * (L - i + R - i) * (R - L + 1) / 2;
//                    printf("1 : %d %d %d\n", i, L, R);
                }
                else if(R <= i) {
                    p += 1.0 * (i - L + i - R) * (R - L + 1) / 2;
//                    printf("2 : %d %d %d\n", i, L, R);
                }
                else {
                    p += 1.0 * (i - L) * (i - L + 1) / 2;
                    p += 1.0 * (R - i) * (R - i + 1) / 2;
//                    printf("3 : %d %d %d\n", i, L, R);
                }
            }
            q = 1.0 * (high[ii] - low[ii] + 1) * (high[ii + 1] - low[ii + 1] + 1);
//            cout << "p = " << p << " q = " << q << endl;
            ret += p / q;
        }
        return (double)(ret);
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
			int low[]                 = {1};
			int high[]                = {100};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = AlternatingLane().expectedBeauty( vector <int>( low, low + ( sizeof low / sizeof low[0] ) ), vector <int>( high, high + ( sizeof high / sizeof high[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int low[]                 = {1, 1, 1};
			int high[]                = {2, 2, 2};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = AlternatingLane().expectedBeauty( vector <int>( low, low + ( sizeof low / sizeof low[0] ) ), vector <int>( high, high + ( sizeof high / sizeof high[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int low[]                 = {1, 3, 5, 7, 9};
			int high[]                = {2, 4, 6, 8, 10};
			double expected__         = 8.0;

			clock_t start__           = clock();
			double received__         = AlternatingLane().expectedBeauty( vector <int>( low, low + ( sizeof low / sizeof low[0] ) ), vector <int>( high, high + ( sizeof high / sizeof high[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int low[]                 = {4, 3, 3, 7};
			int high[]                = {10, 7, 7, 7};
			double expected__         = 6.171428571428572;

			clock_t start__           = clock();
			double received__         = AlternatingLane().expectedBeauty( vector <int>( low, low + ( sizeof low / sizeof low[0] ) ), vector <int>( high, high + ( sizeof high / sizeof high[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int low[]                 = ;
			int high[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = AlternatingLane().expectedBeauty( vector <int>( low, low + ( sizeof low / sizeof low[0] ) ), vector <int>( high, high + ( sizeof high / sizeof high[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int low[]                 = ;
			int high[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = AlternatingLane().expectedBeauty( vector <int>( low, low + ( sizeof low / sizeof low[0] ) ), vector <int>( high, high + ( sizeof high / sizeof high[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int low[]                 = ;
			int high[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = AlternatingLane().expectedBeauty( vector <int>( low, low + ( sizeof low / sizeof low[0] ) ), vector <int>( high, high + ( sizeof high / sizeof high[0] ) ) );
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
