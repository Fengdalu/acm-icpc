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

class PermutationSignature
{
public:
    int n;
    string str;
    vector <int> ret;
    bool check(int i) {
        cout << i << endl;
        if(i < 0) return true;
        if(str[i] == 'I' && ret[i] < ret[i + 1]) return true;
        if(str[i] == 'D' && ret[i] > ret[i + 1]) return true;
        int t = ret[i]; ret[i] = ret[i + 1]; ret[i + 1] = t;
        if(check(i - 1)) return true;
        else return false;
    }
    vector <int> reconstruct (string s)
    {

        n = s.length() + 1;
        str = s;
        for(int i = 1; i <= n; i++) ret.PB(i);
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == 'I' && ret[i] < ret[i + 1]) continue;
            if(s[i] == 'D' && ret[i] > ret[i + 1]) continue;
            int t = ret[i]; ret[i] = ret[i + 1]; ret[i + 1] = t;
            bool flag = true;
            if(i > 0) flag = check(i - 1);
            if(!flag) {
                ret.clear();
                break;
            }
        }
        return (vector <int>)(ret);
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

	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) {
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
			string signature          = "IIIII";
			int expected__[]          = {1, 2, 3, 4, 5, 6 };

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct( signature );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 1: {
			string signature          = "DI";
			int expected__[]          = {2, 1, 3 };

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct( signature );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 2: {
			string signature          = "IIIID";
			int expected__[]          = {1, 2, 3, 4, 6, 5 };

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct( signature );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 3: {
			string signature          = "DIIDID";
			int expected__[]          = {2, 1, 3, 5, 4, 7, 6 };

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct( signature );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}

		// custom cases

      case 4: {
			string signature          = "DD";
			int expected__[]          = {3, 2, 1};

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct( signature );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
/*      case 5: {
			string signature          = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct( signature );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 6: {
			string signature          = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct( signature );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
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
