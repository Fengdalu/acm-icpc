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
struct node {
    int l, r, t;
    node(int l, int r, int t) : l(l), r(r), t(t) {}
};

class BottlesOnShelf
{
public:
    set < int > iset;
    int getNumBroken (int N, vector <int> left, vector <int> right, vector <int> damage)
    {
        int ret = 0;
//        for(int i = 0; i < left.size(); i++) {
//            iset.insert(left[i]);
//            iset.insert(right[i]);
//        }
//        vector <node> vec[iset.size()];
//        set < int > :: iterator ite = iset.begin();
//        int L, R = *ite;
//        int cnt = 0;
//        for(ite = iset.begin()++; ite!= iset.end(); ite++) {
//            L = R; R = *ite;
//            for(int i = 0; i < left.size(); i++) {
//                if(left[i] <= L && right[i] > R) {
//                    vec[cnt].PB(node(L, R, damage[i]));
//                }
//            }
//            cnt++;
//        }
//        ret = 0;
//        for(int i = 0; i < cnt; i++) {
//
//        }
        int m = left.size();
        for(int i = 1; i < (1 << m); i++) {
            int cnt = 0, temp = 0;
            int L = 0, R = N + 1;
            for(int j = 0; j < m; j++) {
                if(i & (1 << j)) {
                    L = max(L, left[j]);
                    R = min(R, right[j]);
                    cnt++;
                }
                if(L > R) break;
            }
            if(L <= R) {
                LL tt = 1, gcd;
                for(int j = 0; j < m; j++) {
                    if(i & (1 << j)) {
                        if(left[j] <= L && R <= right[j]) {
                            gcd = __gcd(tt, (LL)damage[j]);
                            tt /= gcd;
                            tt *= damage[j];
                            if(tt > R) break;
                        }
                    }
                }
                temp = (R / tt) - ((L - 1) / tt);
                if((cnt & 1)) {
                    ret += temp;
                } else {
                    ret -= temp;
                }
            }
        }
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
			int N                     = 7;
			int left[]                = {1};
			int right[]               = {7};
			int damage[]              = {2};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = BottlesOnShelf().getNumBroken( N, vector <int>( left, left + ( sizeof left / sizeof left[0] ) ), vector <int>( right, right + ( sizeof right / sizeof right[0] ) ), vector <int>( damage, damage + ( sizeof damage / sizeof damage[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 7;
			int left[]                = {1,1};
			int right[]               = {7,7};
			int damage[]              = {2,3};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BottlesOnShelf().getNumBroken( N, vector <int>( left, left + ( sizeof left / sizeof left[0] ) ), vector <int>( right, right + ( sizeof right / sizeof right[0] ) ), vector <int>( damage, damage + ( sizeof damage / sizeof damage[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 7;
			int left[]                = {1,1,1};
			int right[]               = {7,7,7};
			int damage[]              = {2,3,6};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BottlesOnShelf().getNumBroken( N, vector <int>( left, left + ( sizeof left / sizeof left[0] ) ), vector <int>( right, right + ( sizeof right / sizeof right[0] ) ), vector <int>( damage, damage + ( sizeof damage / sizeof damage[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 10;
			int left[]                = {1,6};
			int right[]               = {5,10};
			int damage[]              = {1,7};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BottlesOnShelf().getNumBroken( N, vector <int>( left, left + ( sizeof left / sizeof left[0] ) ), vector <int>( right, right + ( sizeof right / sizeof right[0] ) ), vector <int>( damage, damage + ( sizeof damage / sizeof damage[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 5;
			int left[]                = {4};
			int right[]               = {4};
			int damage[]              = {7};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BottlesOnShelf().getNumBroken( N, vector <int>( left, left + ( sizeof left / sizeof left[0] ) ), vector <int>( right, right + ( sizeof right / sizeof right[0] ) ), vector <int>( damage, damage + ( sizeof damage / sizeof damage[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int N                     = 1000000000;
			int left[]                = {1};
			int right[]               = {1000000000};
			int damage[]              = {1};
			int expected__            = 1000000000;

			clock_t start__           = clock();
			int received__            = BottlesOnShelf().getNumBroken( N, vector <int>( left, left + ( sizeof left / sizeof left[0] ) ), vector <int>( right, right + ( sizeof right / sizeof right[0] ) ), vector <int>( damage, damage + ( sizeof damage / sizeof damage[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int left[]                = ;
			int right[]               = ;
			int damage[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BottlesOnShelf().getNumBroken( N, vector <int>( left, left + ( sizeof left / sizeof left[0] ) ), vector <int>( right, right + ( sizeof right / sizeof right[0] ) ), vector <int>( damage, damage + ( sizeof damage / sizeof damage[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			int left[]                = ;
			int right[]               = ;
			int damage[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BottlesOnShelf().getNumBroken( N, vector <int>( left, left + ( sizeof left / sizeof left[0] ) ), vector <int>( right, right + ( sizeof right / sizeof right[0] ) ), vector <int>( damage, damage + ( sizeof damage / sizeof damage[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int N                     = ;
			int left[]                = ;
			int right[]               = ;
			int damage[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BottlesOnShelf().getNumBroken( N, vector <int>( left, left + ( sizeof left / sizeof left[0] ) ), vector <int>( right, right + ( sizeof right / sizeof right[0] ) ), vector <int>( damage, damage + ( sizeof damage / sizeof damage[0] ) ) );
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
