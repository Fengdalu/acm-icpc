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

#define MOD 1000000007
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

class HexagonPuzzle
{
public:
    int fa[5000], cnt[5000];
    int getfa(int x) {
        if(fa[x] == x) return x; else return (fa[x] = getfa(fa[x]));
    }
    int theCount (vector <string> board)
    {
        int ret, n = board.SZ + 1;
        LL ans = 1;
        int u, v, w;
        for(int i = 0; i < 5000; i++) fa[i] = i;
        for(int i = 0; i < board.SZ - 1; i++) {
            for(int j = 0; j <= i; j++) {
                if(board[i][j] == 'X') continue;
                if(board[i+1][j+1] == 'X') continue;
                u = getfa(i * n + j);
                v = getfa((i + 1) * n + j + 1);
                if(board[i+1][j] == '.') {
                    w = getfa((i + 1) * n + j);
                    fa[v] = fa[u];
                    fa[w] = fa[u];
                }
                if(board[i][j+1] == '.') {
                    w = getfa(i * n +j + 1);
                    fa[v] = fa[u];
                    fa[w] = fa[u];
                }
            }
        }
        for(int i = 0; i < board.SZ; i++) {
            for(int j = 0; j < i + 1; j++) {
                 cnt[getfa(i * n + j)]++;
            }
        }

        for(int i = 0; i < board.SZ; i++) {
            for(int j = 0; j < i + 1; j++) {
                 cout << getfa(i * n + j) << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < 5000; i++) {
            if(cnt[i] >= 3) {
                LL t = 1;
                for(LL j = 3; j <= cnt[i]; j++) {
                    t = (t * j) % MOD;
                }
                ans = (ans * t) % MOD;
            }
        }
        ret = ans % MOD;
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
			string board[]            = {".",  ".X",  "X..",  ".X.X"} ;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string board[]            = {"X"} ;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string board[]            = {".",  "..",  "...",  ".X.."} ;
			int expected__            = 20160;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string board[]            = {".",  "..",  "XXX",  "..X.",  ".X..X",  "XXXX..",  "..X.X.X",  "..X.XX.."} ;
			int expected__            = 108;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string board[]            = {".",  "..",  "...",  "....",  ".....",  "......",  ".......",  "........"};
			int expected__            = 261547992;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
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
