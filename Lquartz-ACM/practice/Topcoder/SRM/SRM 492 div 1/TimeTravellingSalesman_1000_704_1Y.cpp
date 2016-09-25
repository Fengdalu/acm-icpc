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
#define M 20000
struct node {
    int u, v, l;
}edge[2*M];
int tot;
int fa[1010];

void addedge(int u, int v, int l) {
    //cout << u << " " << v << " " << l << endl;
    edge[tot].u = u; edge[tot].v = v; edge[tot].l = l;
    tot++;
}
bool cmp(const node & a, const node & b) {
        if(a.l < b.l) return true;
        else return false;
    }
class TimeTravellingSalesman
{
public:
    int getfa(int x) {
        if(x == fa[x]) return x;
        else return (fa[x] = getfa(fa[x]));
    }

    long long determineCost (int N, vector <string> roads)
    {
        long long ret;
        string str;
        for(int i = 0; i < roads.size(); i++) {
            str += roads[i];
        }
        istringstream sin (str);
        int u, v, l;
        char c1, c2;
        tot = 0;
        while(sin >> u >> c1 >> v >> c2 >> l) {
            addedge(u, v, l);
        }
        for(int i = 0; i < N; i++) {
            fa[i] = i;
        }
        sort(edge, edge + tot, cmp);
        ret = 0;
        int cnt = 0;
        for(int i = 0; i < tot; i++) {
            u = getfa(edge[i].u);
            v = getfa(edge[i].v);
            if(u != v) {
                fa[u] = v;
                ret += edge[i].l;
                cnt++;
            }
        }
        if(cnt < N - 1) ret = -1;
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
			int N                     = 3;
			string roads[]            = {"0,1,1 0,2,1 1,2,2"};
			long long expected__      = 2LL;

			clock_t start__           = clock();
			long long received__      = TimeTravellingSalesman().determineCost( N, vector <string>( roads, roads + ( sizeof roads / sizeof roads[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 6;
			string roads[]            = {"0,1,2 1,4,2 4,3,3 2,4,4 0,5,3"};
			long long expected__      = 14LL;

			clock_t start__           = clock();
			long long received__      = TimeTravellingSalesman().determineCost( N, vector <string>( roads, roads + ( sizeof roads / sizeof roads[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 3;
			string roads[]            = {"0,2,2"};
			long long expected__      = -1LL;

			clock_t start__           = clock();
			long long received__      = TimeTravellingSalesman().determineCost( N, vector <string>( roads, roads + ( sizeof roads / sizeof roads[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 4;
			string roads[]            = {"1,0",",10","0 2,1",",584 3,2",",754"};
			long long expected__      = 1438LL;

			clock_t start__           = clock();
			long long received__      = TimeTravellingSalesman().determineCost( N, vector <string>( roads, roads + ( sizeof roads / sizeof roads[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			string roads[]            = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TimeTravellingSalesman().determineCost( N, vector <string>( roads, roads + ( sizeof roads / sizeof roads[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int N                     = ;
			string roads[]            = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TimeTravellingSalesman().determineCost( N, vector <string>( roads, roads + ( sizeof roads / sizeof roads[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			string roads[]            = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TimeTravellingSalesman().determineCost( N, vector <string>( roads, roads + ( sizeof roads / sizeof roads[0] ) ) );
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
