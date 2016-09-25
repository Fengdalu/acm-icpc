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

class ColoredStrokes
{
public:
    int getLeast (vector <string> pic)
    {
        int ret = 0;
        int n = pic.SZ, m = pic[0].SZ;
        int x, y;
        vector < string > p1(pic), p2(pic);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(p1[i][j] == 'G') p1[i][j] = 'B';
                if(p2[i][j] == 'G') p2[i][j] = 'R';
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(p1[i][j] == 'B') {
                    x = i; y = j;
                    while(x < n && p1[x][y] == 'B') {
                        p1[x][y] = 'O';
                        x++;
                    }
                    ret++;
                }
                if(p2[i][j] == 'R') {
                    x = i; y = j;
                    while(y < m && p2[x][y] == 'R') {
                        p2[x][y] = 'O';
                        y++;
                    }
                    ret++;
                }
            }
        }
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < m; j++) cout << p1[i][j];
//            cout << endl;
//        }
//        cout << endl;
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < m; j++) cout << p2[i][j];
//            cout << endl;
//        }
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
			string picture[]          = {"...",  "..."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string picture[]          = {"..B.",  "..B."};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string picture[]          = {".BB."};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string picture[]          = {"...B..",  ".BRGRR",  ".B.B.."};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string picture[]          = {"...B..",  ".BRBRR",  ".B.B.."};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string picture[]          = {"GR",  "BG"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			string picture[]          = {"GGBRGGBRRGRRBBGGRBBBBBGGBRGBBRRBGRRRBBGBGBRBBBRRRB", "BGGRGRRGRGGGGRBRGGRGRBGRBGBRGGBBGBBRGGRGBRBBRBRRBG", "GRRRRGBRGRBGRGRBGRGRBRRRGRGBGBRGGBGGRBRRBGRGGBBRBG", "GRGGRBRRBGRRBRBBBBRGGBRBGGGGGRGGRRBGGRRRBBBGGBRGGB", "BBBGRBBGRBBBGRGBBRRGGRGBRGGGRRBGBGGBGRRGBGBGRRRBBR", "BBRGRBRBGBGRBBGRGRGRGGGRGRBGRGRGGBBRBGRRBGGRGGBGRR", "RRRRBBBGBRBBBRBRGRBGBRBRRRRGRRRGBRBRBRBGRRRBRGGBBG", "BRBGBGRGBGBGGBRBBRGRGGGBBRRBBBBBGBBGRBGBGRRGGRBBRB", "RBGBRRBRBBGGRBRRBBGGRBRGGRBBRGBGGRRBRRGBGBBRGBBGBR", "GRRGBBBGBRBRBGBGGRGBGGGGBRBBRBGGBRRBRBBRGGRRRRRRBR", "RBRGRRBRRRGRRGGRRGGRGGBGGRRRRGBGBGGGBBBGGGBBGRBBBB", "BBBRBBRBBBRGRBGBGGBBGBBRRGRGGBGGGRRBBRGBRRRGRRBBGG", "RRRGRGBRBBGBRRRRRGGBGGBBGBRRGBGBRBGBBBBGBBGGBGGGRR", "GBRGBGBRRRBRRBBBRGBRRBRRRGGBRBRBRGGBBRBBGBBGBRBGRG", "RGBGGGGGGBBRBRRRGBRGGGGGRRBRBBRRRRRGBGRBRRRBGGGBRG", "RRGGRBRRBBGGRBRGRGRBGBRBBGBGRBBGRBRBRBBGBBBGBRBGGR", "GRRBBBBRBBGGBGBRRGBRRBRBBBRGBBGRBBRRGBBRRBRRBGBBBG", "RGRBRGRBGBRRGBGGRBRBBRBGBRBRRGGBBBRRBGGBGRRGRGBGGR", "BBBGBBRRGBGBBRGRRRRGRRGRRRGRBBRBGBBRRBRRBBRGGBRRGB", "BGRGGRGGBGBBGBBBRGBRGGBRGRRGBRGGRRGBRBGRGBBRRGRGGB", "GRRGRRGBBBBBRBBRRRGGBRRGRBGGGBRRBGBBBRRRRRGRGBBGBB", "BGRGRBBRBBBBBGGGRRGRBGRRRRBGBRBBGGGRBGGBGGBGGBBGRG", "RGRRRRBGBBRGBBBRBBRBRRGBGGBGBBBGRBRGBBBBGRBRRGRBRG", "RBGGGRGGBGGRRBBRBRGBGRGBRGBGBGRGRRGRGRBGRRGGRGRBBB", "RRBRGRBBBGBGBRRRBBBRRGBRRGRRGBGGRGRRRBRBRRRBBGGRBB", "BGRBBGBBRRRBGGRGBGGBGBGBRGRRGGRBBGBBGRRBRBGGBRGBGB", "RGGBBGBBRBGBRBBBBGGBBRBRGRRGGGRRRRGBBRGRBRGBRGRBGB", "GBRBGGRRGGGRRBBGBRRGGBBRGBGRBGRRGGBBGRRBRBBGRGBGGB", "GRRRGGBBRBRGBBRRGGGRGBRRRBBRRGRGRGRGBRGRBRBGRGRGGG", "BRGBRRBGGGRGRBRGRGRRRGRBBBGRGGBBRGGBRBRBBBBRGBGBGG", "RGBRRBGRBGRBGRGRBGBRBBGBBGGRBRBBGBBGRGRBRBBGRBRRBG", "GGBGBBBBGGGGGGRRRBRBGBGBBBBRGBGBGBGGBRGGRBBBBGBGGG", "GBBGGRRBBGGGGGGBBRBRGRRRGRGBGGBRRRRGBRBRBRBRGBGRGR", "BGRRBGGBBRGBRRGBBBRBBGGBGRBRBRGGGGRGGBBGGGRBRBGRRG", "GGGBBGGBGGBBGBGBBRRRRGGGGRGRBGBRGBBBRRRBBRGBGBRRBR", "GRGGRBRGGRRBRRGRGBBRBGRBGGBBBBBBGBRBGGGGBBGGGRRGGR", "BGBGGBGBBBRRBRRRRBBRGGGRGBRRRBRGGRBRGRRBGRGRRRBGGR", "BRRBGGBGGBGRRBGRBGGRGGGGBBRGGBGGBRGGGBRRRBGGBRBGBG", "BBRRBRRRRBRGRGRRBBRBBRBGGGGRBBGGBRRGRGGBGGGGRBBGBR", "RGGGGRRRGRRRBGGRRGGBGBGBRRBGGGRGBRRBGBBGRGGRRRGRBB", "RRBGRGGGBGBBRGGRGBRBRGBBBBGRBBRBGGRRRRGRGRGBRGRRRR", "RRBRRBRGGRGGRRBRRBRRBBBGRRRGGGRBBBRRGGBBGGBBRBGBRR", "BGGGBGGGGBBRBGGRRGBBGGGBRGRRGGBRGRRBGBGGGRBGGGBRRG", "RBGRGRBGBGBGGBRGRBGBRBBBGBBBBBRGRBBBBBGGGRBGGRRBRR", "GBGBBBGGRRBBRGBRGRBRBBBRBRGRRBGGBRBRBGRGBGRRGGGGRB", "RRGBBRRGGRRGGGGGBBGRRGGGGGRBGRRBBGRRGBGBRBBGBRGRGG", "GRBRGBGBRGBGBGBRGBRGBRGGGBBRBGBGGRBBGGGRRBBBGRBRGR", "BGBGBBRGRGBRRBGBBBBBBBGRGGRGGBGGRBGBRBRBGRRRRRBRGB", "RBGBGGGGBBBRBRBGRRBBGBRBGGGGGGGRRRBGRBBGBGBGBBGRBR", "BBBRBRGGGBBRRGGGGGGBBRGGGGBBGBBBRGGBGGBGBBBBRBGBRB"};
			int expected__            = 1181;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
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
