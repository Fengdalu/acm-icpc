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
#define eps 1e-10
typedef long long LL;
typedef pair<int, int> PII;


class TimeTravellingGardener
{
public:
    int determineUsage (vector <int> dist, vector <int> h)
    {
        int n = h.size();
        int ret = n - 1;
        int sum[100] = {0};
        int h1, h2, d1, d2, l;
        for(int i = 0; i < n - 1; i++) sum[i + 1] = sum[i] + dist[i];
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int cnt = 0;
                h1 = h[j] - h[i];
                d1 = sum[j] - sum[i];
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;
                    double hh = h[i] + (1.0 * h1 / d1) * (sum[k] - sum[i]);
                    if(hh < -eps) {
                        cnt = n;
                        break;
                    }
                    if(hh - h[k] > eps) {
                        cnt = n;
                        break;
                    }
                    if(fabs(hh - h[k]) > eps) cnt++;
                }
                ret = min(ret, cnt);
            }
        }
        return int(ret);
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
			int distance[]            = {2,2};
			int height[]              = {1,3,10};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage( vector <int>( distance, distance + ( sizeof distance / sizeof distance[0] ) ), vector <int>( height, height + ( sizeof height / sizeof height[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int distance[]            = {3,3};
			int height[]              = {3,1,3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage( vector <int>( distance, distance + ( sizeof distance / sizeof distance[0] ) ), vector <int>( height, height + ( sizeof height / sizeof height[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int distance[]            = {1,3};
			int height[]              = {4,4,4};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage( vector <int>( distance, distance + ( sizeof distance / sizeof distance[0] ) ), vector <int>( height, height + ( sizeof height / sizeof height[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int distance[]            = {4,2};
			int height[]              = {9,8,5};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage( vector <int>( distance, distance + ( sizeof distance / sizeof distance[0] ) ), vector <int>( height, height + ( sizeof height / sizeof height[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int distance[]            = {476,465,260,484};
			int height[]              = {39,13,8,72,80};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage( vector <int>( distance, distance + ( sizeof distance / sizeof distance[0] ) ), vector <int>( height, height + ( sizeof height / sizeof height[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int distance[]            = {173,36,668,79,26,544};
			int height[]              = {488,743,203,446,444,91,453};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage( vector <int>( distance, distance + ( sizeof distance / sizeof distance[0] ) ), vector <int>( height, height + ( sizeof height / sizeof height[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int distance[]            = {2,4,2,2,4,2,4,2,2,4};
			int height[]              = {2,2,10,10,10,16,16,22,22,28,28};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage( vector <int>( distance, distance + ( sizeof distance / sizeof distance[0] ) ), vector <int>( height, height + ( sizeof height / sizeof height[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 7: {
			int distance[]            = ;
			int height[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage( vector <int>( distance, distance + ( sizeof distance / sizeof distance[0] ) ), vector <int>( height, height + ( sizeof height / sizeof height[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int distance[]            = ;
			int height[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage( vector <int>( distance, distance + ( sizeof distance / sizeof distance[0] ) ), vector <int>( height, height + ( sizeof height / sizeof height[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			int distance[]            = ;
			int height[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage( vector <int>( distance, distance + ( sizeof distance / sizeof distance[0] ) ), vector <int>( height, height + ( sizeof height / sizeof height[0] ) ) );
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
