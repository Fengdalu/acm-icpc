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

class UniformBoard {
public:
    int getBoard (vector <string> bo, int K) {
        int i, j;
        int x0, y0, h, w, xx, yy;
        int ret;
        int n = bo.SZ;
        int all = 0, alld = 0, allp = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(bo[i][j] == 'A') all++;
                if(bo[i][j] == '.') alld++;
                if(bo[i][j] == 'P') allp++;
            }
        }
        ret = 0;
        for(x0 = 0; x0 < n; x0++) {
            for(y0 = 0; y0 < n; y0++) {
                for(h = 1; h <= n; h++) {
                    if(x0 + h - 1 >= n) break;
                    for(w = 1; w <= n; w++) {
                        if(y0 + w - 1 >= n) break;
                        if(h * w > all) break;
                        xx = x0 + h - 1;
                        yy = y0 + w - 1;
                        int now = 0, nowd = 0, nowp = 0;
                        for(i = x0; i <= xx; i++) {
                            for(j = y0; j <= yy; j++) {
                                if(bo[i][j] == 'A') now++;
                                if(bo[i][j] == '.') nowd++;
                                if(bo[i][j] == 'P') nowp++;
                            }
                        }
                        if(now == h * w) {
                            cmax(ret, h * w);
                            continue;
                        }
                        if(!alld && nowp) continue;
                        if(nowd + nowp * 2 > K) continue;
                        cmax(ret, h * w);
                        
                    }
                }
            }
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
			string board[]            = {"AP",  ".A"};
			int K                     = 0;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string board[]            = {"AP",  ".A"};
			int K                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string board[]            = {"PPP",  "APA",  "A.P"};
			int K                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string board[]            = {"AAA",  "PPP",  "AAA"};
			int K                     = 10;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string board[]            = {"."};
			int K                     = 1000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string board[]            = {"PPAAPA..AP",  "PPA.APAP..",  "..P.AA.PPP",  "P.P..APAA.",  "P.P..P.APA",  "PPA..AP.AA",  "APP..AAPAA",  "P.P.AP...P",  ".P.A.PAPPA",  "..PAPAP..P"};
			int K                     = 10;
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
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

