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
#define MOD 1000000009
typedef long long LL;
typedef pair<int, int> PII;
typedef vector <int> VI;
typedef set < int > SI;
VI ux, uy, ox[55][210], oy[55][210], g[210][210];
int vis[210][210], cnt[210][210], sum[210];
int n, m, k;
map < VI, int > dmap;
set < VI > dset;
class FoxStones
{
public:
    int getdist(int x1, int y1, int x2, int y2) {
        return max(mabs(x1 - x2), mabs(y1 - y2));
    }

    int getCount (int N, int M, vector <int> sx, vector <int> sy)
    {
        int ret;
        n = N, m = M, k = sx.SZ;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < k; i++) {
            vis[sx[i]][sy[i]] = 1;
        }
        ux.clear(); uy.clear(); dmap.clear(); dset.clear();
        for(int i = 0; i < 55; i++) for(int j = 0;j < 210; j++) {
            ox[i][j].clear(); oy[i][j].clear();
        }
//        cout << "clear" << endl;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
//                cout << vis[i][j] << " ";
                g[i][j].clear();
                if(!vis[i][j]) {
                    ux.PB(i); uy.PB(j);
                    for(int l = 0; l < k; l++) {
//                        cout << "l = " << l << endl;
                        int dist = getdist(i, j, sx[l], sy[l]);
                        g[i][j].PB(dist);
                    }
                    dmap[g[i][j]]++;
                    dset.insert(g[i][j]);
                }
            }
//            cout << endl;
        }
        LL ans = 1;
        for( set < VI > ITE ite = dset.begin(); ite != dset.end(); ite++){
            LL t = dmap[*ite];

            for(LL i = t; i > 1; i--) {
                ans = (ans * i) % MOD;
            }
//            cout << " t = " << t << endl;
        }
        ret = ans % MOD;
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
			int N                     = 6;
			int M                     = 1;
			int sx[]                  = {3};
			int sy[]                  = {1};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = FoxStones().getCount( N, M, vector <int>( sx, sx + ( sizeof sx / sizeof sx[0] ) ), vector <int>( sy, sy + ( sizeof sy / sizeof sy[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 2;
			int M                     = 2;
			int sx[]                  = {2};
			int sy[]                  = {1};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = FoxStones().getCount( N, M, vector <int>( sx, sx + ( sizeof sx / sizeof sx[0] ) ), vector <int>( sy, sy + ( sizeof sy / sizeof sy[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 3;
			int M                     = 3;
			int sx[]                  = {1,2,3};
			int sy[]                  = {1,2,3};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = FoxStones().getCount( N, M, vector <int>( sx, sx + ( sizeof sx / sizeof sx[0] ) ), vector <int>( sy, sy + ( sizeof sy / sizeof sy[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 12;
			int M                     = 34;
			int sx[]                  = {5,6,7,8,9,10};
			int sy[]                  = {11,12,13,14,15,16};
			int expected__            = 410850247;

			clock_t start__           = clock();
			int received__            = FoxStones().getCount( N, M, vector <int>( sx, sx + ( sizeof sx / sizeof sx[0] ) ), vector <int>( sy, sy + ( sizeof sy / sizeof sy[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int M                     = ;
			int sx[]                  = ;
			int sy[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxStones().getCount( N, M, vector <int>( sx, sx + ( sizeof sx / sizeof sx[0] ) ), vector <int>( sy, sy + ( sizeof sy / sizeof sy[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int N                     = ;
			int M                     = ;
			int sx[]                  = ;
			int sy[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxStones().getCount( N, M, vector <int>( sx, sx + ( sizeof sx / sizeof sx[0] ) ), vector <int>( sy, sy + ( sizeof sy / sizeof sy[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			int M                     = ;
			int sx[]                  = ;
			int sy[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxStones().getCount( N, M, vector <int>( sx, sx + ( sizeof sx / sizeof sx[0] ) ), vector <int>( sy, sy + ( sizeof sy / sizeof sy[0] ) ) );
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
