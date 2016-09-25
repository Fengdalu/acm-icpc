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


class QuickT9
{
public:
    int minimumPressings (vector <string> t9, string word)
    {
        int ret;

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
			string t9[]               = {"aae", "bab", "abad", "bdbd", "beta"};
			string word               = "babe";
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = QuickT9().minimumPressings( vector <string>( t9, t9 + ( sizeof t9 / sizeof t9[0] ) ), word );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string t9[]               = {"ann","ie"};
			string word               = "annie";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = QuickT9().minimumPressings( vector <string>( t9, t9 + ( sizeof t9 / sizeof t9[0] ) ), word );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string t9[]               = {"ann","amm"};
			string word               = "annie";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = QuickT9().minimumPressings( vector <string>( t9, t9 + ( sizeof t9 / sizeof t9[0] ) ), word );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string t9[]               = {"aaa aab","aac aba abb ccca"};
			string word               = "aba";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = QuickT9().minimumPressings( vector <string>( t9, t9 + ( sizeof t9 / sizeof t9[0] ) ), word );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string t9[]               = {"acac aba aaab","aab aa baa","bba bacade abb","baba"};
			string word               = "abbaca";
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = QuickT9().minimumPressings( vector <string>( t9, t9 + ( sizeof t9 / sizeof t9[0] ) ), word );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string t9[]               = {"aaa aab aac","aba abb","ccca"};
			string word               = "ccc";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = QuickT9().minimumPressings( vector <string>( t9, t9 + ( sizeof t9 / sizeof t9[0] ) ), word );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			string t9[]               = ;
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = QuickT9().minimumPressings( vector <string>( t9, t9 + ( sizeof t9 / sizeof t9[0] ) ), word );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string t9[]               = ;
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = QuickT9().minimumPressings( vector <string>( t9, t9 + ( sizeof t9 / sizeof t9[0] ) ), word );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string t9[]               = ;
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = QuickT9().minimumPressings( vector <string>( t9, t9 + ( sizeof t9 / sizeof t9[0] ) ), word );
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
