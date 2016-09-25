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

class FoxSequence
{
public:
    string isValid (vector <int> seq)
    {
        string ret , no = "NO", yes = "YES";
        if(seq.SZ < 5) return no;
        if(seq[1] <= seq[0]) return no;
        int a = 1, b, c, d, e;
        for(int i = 2; i < seq.SZ; i++) {
            if(seq[i] - seq[i - 1] == seq[1] - seq[0]) a = i;
            else break;
        }
        cout << "a = " << a << endl;
        if(a == seq.SZ - 1) return no;
        b = a + 1;
        if(seq[b] >= seq[b-1] ) return no;
        for(int i = a + 2; i < seq.SZ; i++) {
            if(seq[i] - seq[i - 1] == seq[a + 1] - seq[a]) b = i;
            else break;
        }
        if(b == seq.SZ - 1) return no;
        cout << "b = " << b << endl;
        c = b;
        while(c < seq.SZ && seq[c + 1] == seq[c]) c++;

        if(c == seq.SZ - 1|| seq[c + 1] <= seq[c]) return no;
        cout << "c = " << c << endl;
        d = c + 1;
        for(int i = c + 1; i < seq.SZ; i++) {
            if(seq[i] - seq[i-1] == seq[c + 1] - seq[c]) d = i;
            else break;
        }
        if(d == seq.SZ - 1) return no;
        if(seq[d + 1] >= seq[d]) return no;
        cout << "d = " << d << endl;
        for(int i = d + 1; i < seq.SZ; i++) {
            if(seq[i] - seq[i - 1] != seq[d + 1] - seq[d]) return no;
        }
        return (string)(yes);
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
			int seq[]                 = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1} ;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid( vector <int>( seq, seq + ( sizeof seq / sizeof seq[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int seq[]                 = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4} ;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid( vector <int>( seq, seq + ( sizeof seq / sizeof seq[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int seq[]                 = {3,6,9,1,9,5,1} ;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid( vector <int>( seq, seq + ( sizeof seq / sizeof seq[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int seq[]                 = {1,2,3,2,1,2,3,2,1,2,3,2,1} ;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid( vector <int>( seq, seq + ( sizeof seq / sizeof seq[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int seq[]                 = {1,3,4,3,1,1,1,1,3,4,3,1} ;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid( vector <int>( seq, seq + ( sizeof seq / sizeof seq[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int seq[]                 = {6,1,6} ;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid( vector <int>( seq, seq + ( sizeof seq / sizeof seq[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			int seq[]                 = {1, 2, 1, 2, 1};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid( vector <int>( seq, seq + ( sizeof seq / sizeof seq[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
      case 7: {
			int seq[]                 = {1, 2, 1, 2, 3};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid( vector <int>( seq, seq + ( sizeof seq / sizeof seq[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 8: {
			int seq[]                 = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid( vector <int>( seq, seq + ( sizeof seq / sizeof seq[0] ) ) );
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
