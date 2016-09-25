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
#define mabs(x) ((x) < 0 ? -(x) : (x))
#define sqr(x) ((x)*(x))
#define ITE ::iterator
typedef long long LL;
typedef pair<int, int> PII;
typedef vector <int> VI;
typedef set < int > SI;
int n, m;
int matchx[55], matchy[55];
bool vis[55][55], boo[55];
VI have[55];
SI dset;
class OneDimensionalBalls
{
public:
    long long countValidGuesses (vector <int> fp, vector <int> sp)
    {
        long long ret = 0;
        sort(fp.begin(), fp.END);
        sort(sp.BGN, sp.END);
        n = fp.SZ; m = sp.SZ;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dset.insert(mabs(sp[j] - fp[i]));
            }
        }
        for(SI ITE ite = dset.BGN; ite != dset.END; ite++) {
            int L = *ite;
            if(L == 0) continue;
            for(int i = 0; i < n; i++) have[i].clear();
            memset(vis, false, sizeof(vis));
            memset(boo, false, sizeof(boo));
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(mabs(sp[j] - fp[i]) == L) {
                        vis[i][j] = true;
                        boo[i] = true;
                        have[i].PB(j);
                    }
                }
            }
            int xx = 0;
            for(int i = 0; i < n; i++) if(!boo[i]) xx++;
            if(xx) continue;

            int cnt = 0;
            memset(matchx, -1, sizeof(matchx));
            memset(matchy, -1, sizeof(matchy));
            for(int i = 0; i < n; i++) {
                if(matchx[i] == -1) {
                    memset(boo, false, sizeof(boo));
                    if(dfs(i)) cnt++;
                }
            }
            if(cnt < n) continue;
//            cout << L << endl;
//            for(int i = 0; i < n; i++) {
//                cout << "have " << i << endl;
//                for(int j = 0; j < have[i].SZ; j++) cout << " " << have[i][j];
//                cout << endl;
//            }
            cnt = 0;
            memset(boo, false, sizeof(boo));
            for(int i = 0; i < n; i++) matchx[i] = i;
            for(int i = 0; i < m; i++) matchy[i] = -1;
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    if(fp[j] - fp[i] == 2 * L) {
                        matchx[j] = matchx[i];
                        boo[j] = true;
                        break;
                    }
                }
            }
            LL t = 1;
            int p, q;
            for(int i = 0; i < n; i++) if(matchx[i] == i) {
//                for(int i = 0; i < m; i++) matchy[i] = i;
                p = 0; q = 0;
                for(int k = i; k < n; k++) if(matchx[k] == matchx[i]) {
                    p++;
                    for(int l = 0; l < have[k].SZ; l++) {
                        matchy[have[k][l]] = matchx[i];
                    }
                }
                for(int k = 0; k < m; k++) {
                    if(matchy[k] == matchx[i]) q++;
                }
//                cout << "t = " << t << " p = " << p << " q = " << q << endl;
//                for(int i = 0; i < m; i++) cout << matchy[i] << " " ; cout << endl;
                if(p < q) t *= q;
            }
//            cout << t << endl;
            ret += t;
        }

        return (long long)(ret);
    }
    bool dfs(int u) {
            int v;
            for(int j = 0; j < m; j++) {
                if(!vis[u][j]) continue;
                v = j;
                if(boo[v]) continue;
                boo[v] = true;
                if(matchy[v] == -1 || dfs(matchy[v])) {
                    matchy[v] = u;
                    matchx[u] = v;
                    return true;
                }
            }
            return false;
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
			int firstPicture[]        = {12,11};
			int secondPicture[]       = {10,11,13};
			long long expected__      = 3LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int firstPicture[]        = {1,2,3};
			int secondPicture[]       = {1,2,3};
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int firstPicture[]        = {1,3};
			int secondPicture[]       = {1,3};
			long long expected__      = 1LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int firstPicture[]        = {7234};
			int secondPicture[]       = {6316,689156,689160,689161,800000,1000001};
			long long expected__      = 6LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int firstPicture[]        = {6,2,4};
			int secondPicture[]       = {1,2,3,4,5,7,8};
			long long expected__      = 7LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			int firstPicture[]        = {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
			int secondPicture[]       = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49};
			long long expected__      = 161140441LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int firstPicture[]        = ;
			int secondPicture[]       = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int firstPicture[]        = ;
			int secondPicture[]       = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
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
