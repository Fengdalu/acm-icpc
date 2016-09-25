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
VI p;
int vis[1100];
class ColorfulCards
{
public:
    vector <int> theCards (int N, string c)
    {
        //c = "B" + c;
        vector <int> ret, ret1, ret2;
        ret.clear(); ret1.clear();
        for(int i = 2; i <= N; i++) {
            int j;
            for(j = 2; j * j < i; j++) {
                if(i % j == 0) break;
            }
            if(j * j > i)vis[i] = 1;
        }
        int pre = 0;
        for(int i = 0; i < c.length(); i++) {
            if(c[i] == 'B') {
                for(int j = pre + 1; j <= N; j++) {
                    if(!vis[j]) {
                        ret.PB(j);
                        pre = j;
                        break;
                    }
                }
            }
            else {
                for(int j = pre + 1; j <= N; j++) {
                    if(vis[j]) {
                        ret.PB(j);
                        pre = j;
                        break;
                    }
                }
            }
        }
        pre = N + 1;
        for(int i = c.length() - 1; i >= 0; i--) {
            if(c[i] == 'B') {
                for(int j = pre - 1; j > 0; j--) {
                    if(!vis[j]) {
                        ret1.PB(j);
                        pre = j;
                        break;
                    }
                }
            }
            else {
                for(int j = pre - 1; j > 0; j--) {
                    if(vis[j]) {
                        ret1.PB(j);
                        pre = j;
                        break;
                    }
                }
            }
        }
        for(int i = ret1.SZ - 1; i >= 0; i--) ret2.PB(ret1[i]);
//        for(int i = 0; i < ret.SZ; i++) cout << " " << ret[i]; cout <<endl;
//        for(int i = 0; i < ret2.SZ; i++) cout << " " << ret2[i]; cout <<endl;

        if(ret2.SZ == ret.SZ) {
            for(int i = 0; i < ret.SZ; i++) {
                if(ret[i] != ret2[i]) ret[i] = -1;
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
			int N                     = 5;
			string colors             = "RRR";
			int expected__[]          = {2, 3, 5 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 1: {
			int N                     = 7;
			string colors             = "BBB";
			int expected__[]          = {1, 4, 6 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 2: {
			int N                     = 6;
			string colors             = "RBR";
			int expected__[]          = {-1, 4, 5 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 3: {
			int N                     = 58;
			string colors             = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
			int expected__[]          = {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 4: {
			int N                     = 495;
			string colors             = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
			int expected__[]          = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			string colors             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			string colors             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			string colors             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
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
