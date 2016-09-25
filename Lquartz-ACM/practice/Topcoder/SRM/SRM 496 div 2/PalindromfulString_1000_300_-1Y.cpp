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

LL c[1 << 12];
bool used[1 << 12];
int n, m, k;
VI g;
int a[20];
int all;
class PalindromfulString
{
public:
    bool check() {
        int cnt = 0;
        for(int i = m - 1; i < n; i++) {
            for(int l = i - m + 1, r = i; l < r; l++, r--) {
                if(a[l] != a[r]) {
                    cnt--;
                    break;
                }
            }
            cnt++;
        }
        if(cnt >= k) return true;
        else return false;
    }
    void dfs(int dep, int pre) {
        if(dep == n) {
            if(check()) {
                g.PB(pre);
            }
            all++;
            return;
        }
        for(int i = 1; i <= pre; i++) {
            a[dep] = i;
            dfs(dep + 1, pre);
        }
        a[dep] = pre + 1;
        dfs(dep + 1, pre + 1);
    }

    long long count (int N, int M, int K)
    {
        n = N, m = M, k = K;
        long long ret = 0;
        g.clear();
        all = 0;
        dfs(0, 0);
//        cout << "g[]  " ;
        int used[20];
        memset(used, 0, sizeof(used));
        for(int i = 0; i < g.SZ; i++) {
            LL t = 1;
//            cout << g[i] << " ";
            used[g[i]]++;
            for(int j = 0; j < g[i]; j++) {
                t *= 26 - j;
            }
            ret += t;
        }

//        cout << endl;
//        if(g.SZ == 0) ret = 0;
//        cout << "all = " << all << endl;
        return (long long)(ret);
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

	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) {
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
			int N                     = 2;
			int M                     = 2;
			int K                     = 1;
			long long expected__      = 26LL;

			clock_t start__           = clock();
			long long received__      = PalindromfulString().count( N, M, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 2;
			int M                     = 2;
			int K                     = 0;
			long long expected__      = 676LL;

			clock_t start__           = clock();
			long long received__      = PalindromfulString().count( N, M, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 3;
			int M                     = 2;
			int K                     = 1;
			long long expected__      = 1326LL;

			clock_t start__           = clock();
			long long received__      = PalindromfulString().count( N, M, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 4;
			int M                     = 4;
			int K                     = 1;
			long long expected__      = 676LL;

			clock_t start__           = clock();
			long long received__      = PalindromfulString().count( N, M, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 7;
			int M                     = 3;
			int K                     = 3;
			long long expected__      = 4310176LL;

			clock_t start__           = clock();
			long long received__      = PalindromfulString().count( N, M, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases
/*
      case 5: {
			int N                     = 11;
			int M                     = 3;
			int K                     = 5;
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = PalindromfulString().count( N, M, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
//*/
/*      case 6: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = PalindromfulString().count( N, M, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = PalindromfulString().count( N, M, K );
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
