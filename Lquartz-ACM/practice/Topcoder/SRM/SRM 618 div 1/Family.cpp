// BEGIN CUT HERE
/*

*/
// END CUT HERE
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef vector <int> VI;
typedef queue <int> QI;
typedef stack <int> StaI;
typedef vector <PII> VII;
typedef queue <PII> QII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;
int g[105][105];
class Family {
public:
    int n;
    int d[105];
    bool dfs(int u, int f) {
//        cout << "dfs " << u << " " << f << endl;
        d[u] = d[f] + 1;
        bool ret = true;
        for(int i = 0; i < n; i++) {
            if(i == f) continue;
            if(!g[u][i]) continue;
            if(d[i] != -1) {
                if(abs(d[u] - d[i]) % 2 == 0) {
                    return false;
                }
            }
            else {
                ret = dfs(i, u);
                if(!ret) return ret;
            }
        }
        return ret;
    }
    string isFamily (vector <int> pa1, vector <int> pa2) {
        int i, j, k, l;
        string ret;
        n = pa1.SZ;
        bool flag = true;
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= n; j++) {
                g[i][j] = 0;
            }
        }
        for(i = 0; i < n; i++) {
            if(pa1[i] == -1 && pa2[i] == -1) continue;
            else if(pa1[i] != -1 && pa2[i] != -1) {
                if(pa1[i] == pa2[i]) {
                    flag = false;
                    break;
                }
                else {
                    g[pa1[i]][pa2[i]] = g[pa2[i]][pa1[i]] = 1;
                }
            }
            else {
                flag = false;
                break;
            }
        }
        if(flag) {
            for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) d[j] = -1;
                d[n] = 0;
                flag = dfs(i, n);
                if(!flag) break;
            }
        }
        if(flag) ret = "Possible";
        else ret = "Impossible";
        return (string)(ret);
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
			int parent1[]             = {-1,-1,0};
			int parent2[]             = {-1,-1,1};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int parent1[]             = {-1,-1,-1,-1,-1};
			int parent2[]             = {-1,-1,-1,-1,-1};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int parent1[]             = {-1,-1,0,0,1};
			int parent2[]             = {-1,-1,1,2,2};
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int parent1[]             = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6} ;
			int parent2[]             = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1} ;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int parent1[]             = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11};
			int parent2[]             = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13};
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int parent1[]             = ;
			int parent2[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int parent1[]             = ;
			int parent2[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int parent1[]             = ;
			int parent2[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
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

