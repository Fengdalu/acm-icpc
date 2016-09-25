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


class Painting
{
public:
    int g[55][55], col[55][55], row[55][55], f[55][55];
    int sum[55][55];
    int n, m;
    bool check(int l) {

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(g[i][j]) {
                    if(l * l == sum[i][j] - sum[i][j - l] - sum[i - l][j] + sum[i - l][j - l])
                    {
                        for(int x = i - l + 1; x <= i; x++) {
                            for(int y = j - l + 1; y <= j; y++) {
                                f[x][y] = -2;
                            }
                        }
                    }
                }
            }
        }
        bool flag = true;
        for(int i = 1; i<= n; i++) for(int j = 1; j <= m; j++) {
            if(g[i][j] && f[i][j] != -2) flag = false;
            f[i][j] = 0;
        }
        return flag;
    }
    void outprint(int g[][55]) {
        cout << "xxxx" << endl;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }
    int largestBrush (vector <string> pic)
    {
        int ret = 1000;
        n = pic.size(), m = pic[0].length();
        memset(g, 0, sizeof(g));
        memset(row, 0x3f, sizeof(row));
        memset(col, 0x3f, sizeof(col));
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pic[i][j] == 'B') g[i + 1][j + 1] = 1;
            }
        }

        int dmax = 1000;
        for(int i = 1; i <= n+1; i++) {
            row[i][0] = 0;
            for(int j = 1; j <= m+1; j++) {
                if(g[i][j]) row[i][j] = row[i][j - 1] + 1;
                else {
                    row[i][j] = 0;
                    if(g[i][j - 1]) ret = min(ret, row[i][j - 1]), row[i][j - 1] = -1;
                }
            }
        }
        for(int j = 1; j <= m+1; j++) {
            col[0][j] = 0;
            for(int i = 1; i <= n+1; i++) {
                if(g[i][j]) col[i][j] = col[i-1][j] + 1;
                else {
                    col[i][j] = 0;
                    if(g[i-1][j]) ret = min(ret, col[i-1][j]), g[i-1][j] = -1;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int temp = sum[i-1][j] + sum[i][j - 1] - sum[i-1][j-1];
                if(g[i][j]) sum[i][j] = temp + 1;
                else sum[i][j] = temp;
            }
        }
        for(int i = ret; i >= 0; i--) {
            if(check(i)) return i;
        }
        outprint(g);
        outprint(row);
        outprint(col);
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
			string picture[]          = {"BBBB",  "BBBB",  "BBBB",  "BBBB"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string picture[]          = {"BBBB",  "BWWB",  "BWWB",  "BBBB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string picture[]          = {"WBBBBB",  "BBBBBB",  "BBBBBB",  "BBBBBB"} ;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string picture[]          = {"BBBB",  "BBBB",  "WBBB",  "BBBB",  "BBBB",  "BBBB"} ;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string picture[]          = {"WBBBBBWWWWWWWWW",  "WBBBBBBWWWWWWWW",  "WBBBBBBBBBBBWWW",  "WBBBBBBBBBBBWWW",  "BBBBBBBBBBBBBBB",  "BBBBBBBBBBBBBBB",  "BBBBBBBBBBBBBBB",  "BBBBBBBBWWBBBBB",  "BBBBBBBBWBBBBBB",  "WBBBBBBBWBBBBBW",  "BBBBBBBWWBBBBBW",  "BBBBBBBWWBBBBBW",  "BBBBBBWWWBBBBBW",  "BBBBBWWWWWWWWWW",  "BBBBBWWWWWWWWWW"} ;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			string picture[]          = {"BBWW", "BBWW", "WBBW", "WWBB", "WWBB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
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
