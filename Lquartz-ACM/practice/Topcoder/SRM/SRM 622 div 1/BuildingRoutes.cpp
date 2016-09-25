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
#define BG begin()
#define ED end()
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
int f[55][55];

class BuildingRoutes {
public:
    int build (vector <string> dist, int T) {
        int ret = 0;
        int n = dist.SZ;
        int i, j, k;
        vector < pair <int, PII> > g;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                f[i][j] = dist[i][j] - '0';
//                ret += f[i][j];
                if(i == j) continue;
                g.PB(MP(dist[i][j] - '0', MP(i, j)));
                
            }
        }
        for(k = 0; k < n; k++) {
            for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) {
                    if(f[i][j] > f[i][k] +f[k][j]) {
                        f[i][j] = f[i][k] + f[k][j];
                    }
                }
            }
        }
        sort(g.BG, g.ED);
        for(i = 0; i < g.SZ; i++) {
            int t = 0;
            int u = g[i].BB.AA, v = g[i].BB.BB;
            for(j = 0; j < n; j++) {
                for(k = 0; k < n; k++) {
                    if(f[j][u] + g[i].AA + f[v][k] == f[j][k]) {
                        t++;
                    }
                }
            }
            if(t >= T) ret += g[i].AA;
        }
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
        string dist[]             = {"011",  "101",  "110"};
        int T                     = 1;
        int expected__            = 6;

        clock_t start__           = clock();
        int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
        return verify_case( casenum, expected__, received__, clock()-start__ );
    }
    case 1: {
        string dist[]             = {"033",  "309",  "390"};
        int T                     = 1;
        int expected__            = 12;

        clock_t start__           = clock();
        int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
        return verify_case( casenum, expected__, received__, clock()-start__ );
    }
    case 2: {
        string dist[]             = {"0123",  "1023",  "1203",  "1230"};
        int T                     = 2;
        int expected__            = 5;

        clock_t start__           = clock();
        int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
        return verify_case( casenum, expected__, received__, clock()-start__ );
    }
    case 3: {
        string dist[]             = {"05789654",  "10347583",  "65085479",  "55602398",  "76590934",  "57939045",  "12345608",  "68647640"};
        int T                     = 3;
        int expected__            = 40;

        clock_t start__           = clock();
        int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
        return verify_case( casenum, expected__, received__, clock()-start__ );
    }

    // custom cases

    /*      case 4: {
    			string dist[]             = ;
    			int T                     = ;
    			int expected__            = ;

    			clock_t start__           = clock();
    			int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    /*      case 5: {
    			string dist[]             = ;
    			int T                     = ;
    			int expected__            = ;

    			clock_t start__           = clock();
    			int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    /*      case 6: {
    			string dist[]             = ;
    			int T                     = ;
    			int expected__            = ;

    			clock_t start__           = clock();
    			int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
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
