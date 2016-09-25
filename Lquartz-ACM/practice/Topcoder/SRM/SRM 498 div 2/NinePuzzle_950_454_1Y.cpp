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

int ddd[10][10] = {
    {0, 1, 2, -1},
    {0, 2, 3, 4, -1},
    {0, 1, 5, 4, -1},
    {6, 7, 1, 4, -1},
    {1, 2, 3, 5, 7, 8, -1},
    {9, 3, 8, 4, -1},
    {3, 7, -1},
    {6, 3, 8, 4, -1},
    {9, 5, 7, 4, -1},
    {8, 5, -1}
};

VI d[10];
int xli[] = {0, 6, 9, 1, 2, 3, 5, 7, 8, 4};
VI li(xli, xli + 10);
struct node {
    string s;
    int e;
    int step;
    node(string s, int e, int step):s(s), e(e), step(step) {}
}now("", 0, 0);
queue <node> Q;
map <string,int> dmap;
class NinePuzzle
{
public:
    int bfs(string f, string e) {
        if(f == e) return 0;
        while(!Q.empty()) Q.pop();
        for(int i = 0; i < 10; i++) {
            if(f[i] == '*') {
                Q.push(node(f, i, 0));
                break;
            }
        }
        dmap.clear();
        dmap[f] = -1;
        while(!Q.empty()) {
            now = Q.front();
            Q.pop();
            for(int i = 0; i < d[now.e].SZ; i++) {
                string str = now.s;
                str[now.e] = now.s[d[now.e][i]];
                str[d[now.e][i]] = now.s[now.e];
                if(dmap[str] == 0) {
                    dmap[str] = now.step + 1;
                    Q.push(node(str, d[now.e][i], now.step + 1));
                    if(str == e) return dmap[e];
                }
            }
        }
        return -1;
    }
    int getMinimumCost (string init, string goal)
    {
        int ret;
        for(int i = 0; i < 10; i++) {
            int j = 0;
            while(ddd[i][j] != -1) {
                d[i].PB(ddd[i][j]);
                j++;
            }
        }
        ret = bfs(init, goal);
        if(ret == -1) {
            int r, g, b, y;
            r = g = b = y = 0;
            for(int i = goal.size() - 1; i >= 0; i--) {
                if(goal[i] == 'R') r++;
                else if(goal[i] == 'G') g++;
                else if(goal[i] == 'B') b++;
                else if(goal[i] == 'Y') y++;
            }
            for(int i = 0; i < init.SZ; i++) {
                if(r && init[i] == 'R') r--;
                else if(g && init[i] == 'G') g--;
                else if(b && init[i] == 'B') b--;
                else if(y && init[i] == 'Y') y--;
            }
            ret = r + g + b + y;
        }
        else ret = 0;
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
			string init               = "BG*YRGRRYR" ;
			string goal               = "BGGY*YRRRR" ;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = NinePuzzle().getMinimumCost( init, goal );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string init               = "GBBB*BGBBG" ;
			string goal               = "RYYY*YRYYR";
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = NinePuzzle().getMinimumCost( init, goal );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string init               = "RRBR*BRBBB" ;
			string goal               = "BBRB*RBRRR" ;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = NinePuzzle().getMinimumCost( init, goal );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 3: {
			string init               = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NinePuzzle().getMinimumCost( init, goal );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 4: {
			string init               = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NinePuzzle().getMinimumCost( init, goal );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			string init               = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NinePuzzle().getMinimumCost( init, goal );
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
