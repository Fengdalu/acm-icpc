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

queue < int > Q;
int g[1000100];
class StonesGame
{
public:
    string winner (int N, int M, int K, int L)
    {
        string ret;
        memset(g, 0, sizeof(g));
        if(check(N, M, K, L)) return "Romeo";
        //for(int i = 1; i <= N; i++) printf("xx %d %d\n", i, g[i]);
        if(check2(N, M, K, L)) return "Strangelet";
        return "Draw";
    }

    bool check1(int N, int M, int K, int L) {
        int l, r, len;
        len = abs(L - M) + 1;
        if(len > K) return false;
        l = min(M, L);
        r = max(M, L);
        if(len % 2 != K % 2) return false;
        if(l - (K - len) / 2 < 1) return false;
        if(r + (K - len) / 2 > N) return false;
        return true;
    }
    bool check(int N, int M, int K, int L) {
        for(int i = 1; i <= N; i++) {
            if(check1(N, M, K, i)) g[i] = -1;
        }
        if(g[L] == -1) return true;
        else return false;
    }
    bool check2(int N, int M, int K, int L) {
        for(int i = 1; i<= N; i++) {
            if(g[i] != -1) continue;
            if(!check1(N, i, K, L)) return false;
        }
        return true;
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

	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) {
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
			cerr << "    Expected: \"" << expected << "\"" << endl;
			cerr << "    Received: \"" << received << "\"" << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int N                     = 3;
			int M                     = 1;
			int K                     = 1;
			int L                     = 2;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 5;
			int M                     = 1;
			int K                     = 2;
			int L                     = 2;
			string expected__         = "Romeo";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 5;
			int M                     = 5;
			int K                     = 2;
			int L                     = 3;
			string expected__         = "Strangelet";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 5;
			int M                     = 5;
			int K                     = 2;
			int L                     = 2;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 1000000;
			int M                     = 804588;
			int K                     = 705444;
			int L                     = 292263;
			string expected__         = "Romeo";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int N                     = 1000000;
			int M                     = 100000;
			int K                     = 500000;
			int L                     = 600000;
			string expected__         = "Strangelet";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
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
