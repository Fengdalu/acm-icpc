// BEGIN CUT HERE
/*

*/
// END CUT HERE
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef vector <int> VI;
typedef queue <int> QI;
typedef stack <int> StaI;
typedef vector <PII> VII;
typedef queue <PII> QII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;

class DropCoins {
public:
    int getMinimum (vector <string> bo, int K) {
        int i, j, k, l;
        int ret = MOD;
        int n = bo.SZ;
        int m = bo[0].length();
        int a[10], b[10];
        int sum[33][33] = {0};
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i-1][j-1];
                if(bo[i-1][j-1] == 'o') {
                    sum[i][j]++;
                }
            }
        }
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                for(k = i; k <= n; k++) {
                    for(l = j; l <= m; l++) {
                        if(sum[k][l] - sum[i - 1][l] - sum[k][j - 1] + sum[i-1][j-1] == K) {
                            int up = i - 1;
                            int down = n - k;
                            int left = j - 1;
                            int right = m - l;
                            int temp = min(up + down + up, 2*down + up) 
                                + min(2*left + right, 2*right + left);
                            cmin(ret, temp);
//                            cout << i << " " << j << " " << k << " " << l <<endl;
                        }
                    }
                }
            }
        }
        if(ret == MOD) ret = -1;
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
			string board[]            = {".o.." ,"oooo" ,"..o."} ;
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string board[]            = {".....o" ,"......" ,"oooooo" ,"oooooo" ,"......" ,"o....."} ;
			int K                     = 12;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string board[]            = {"...." ,".oo." ,".oo." ,"...."} ;
			int K                     = 3;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string board[]            = {"......." ,"..ooo.." ,"ooooooo" ,".oo.oo." ,"oo...oo"} ;
			int K                     = 12;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string board[]            = {"................." ,".ooooooo...oooo.." ,".ooooooo..oooooo." ,".oo.......oo..oo." ,".oo.......oo..oo." ,".ooooo.....oooo.." ,".ooooooo...oooo.." ,".....ooo..oo..oo." ,"......oo..oo..oo." ,".ooooooo..oooooo." ,".oooooo....oooo.." ,"................."} ;
			int K                     = 58;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
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

