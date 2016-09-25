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


class PrefixTree
{
public:
    vector < string > wd;
    vector < int > all;
    int m;
    int f[(1<<16)], tot[20][27];
    int getNumNodes (vector <string> words)
    {
        int ret;
        m = words.size();
        memset(f, -1, sizeof(f));
        for(int i = 0; i < words.size(); i++) {
            wd.PB(words[i]);
            for(int j = 0; j < wd[i].length(); j++) {
                tot[i][wd[i][j] - 'a'] ++;
            }
        }
        for(int b = 0; b < m; b++) {
            f[1<<b] = wd[b].length();
        }
        ret = dp((1 << wd.size()) - 1);
        return int(ret+1);
    }

    int calc(int status) {
        int ca[27] = {0};
        for(int i = 0; i < 26; i++) ca[i] = 51;
        for(int b = 0; b < m; b++) {
            if(status & (1 << b)) {
                for(int i = 0; i < 26; i++) {
                    ca[i] = min(ca[i], tot[b][i]);
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < 26; i++) ret += ca[i];
        return ret;
    }

    int dp(int status) {
        if(f[status] != -1) return f[status];
        if(status == 0) {
            return f[status] = 0;
        }
        int sub = status & (status - 1);
        int same = calc(status);
        while(sub != 0) {
            int temp = dp(sub) + dp(status ^ sub) - same;
            if(f[status] == -1) f[status] = temp;
            f[status] = min(f[status], temp);
            sub = (sub - 1) & status;
        }
        return f[status];
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
			string words[]            = {"topcoder"};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string words[]            = {"topcoder","topcoder"};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string words[]            = {"aab","ca"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string words[]            = {"aab","ca","ba"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string words[]            = {"ab","cd","ef"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string words[]            = {"a","aa","aaa"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
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
