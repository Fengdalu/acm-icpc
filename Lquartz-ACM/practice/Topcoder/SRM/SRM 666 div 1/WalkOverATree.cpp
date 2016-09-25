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
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SZ size()
#define SQ(x) ((x)*(x))
#define SORT(p) sort(p.BGN,p.ED)
#define MEM(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef queue<int> QI;
typedef deque<int> DQI;
typedef set<int> SI;
typedef vector<PII> VII;
typedef queue<PII> QII;
typedef deque<PII> DQII;
typedef set<PII> SII;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef vector<LL> VL;
typedef queue<LL> QL;
typedef deque<LL> DQL;
typedef set<LL> SL;
typedef vector<PLL> VLL;
typedef queue<PLL> QLL;
typedef deque<PLL> DQLL;
typedef set<PLL> SLL;
#define Maxn 55
#define cmax(x, y) x=max(x,y)
#define Maxm 111
class WalkOverATree
{
public:
    int n, m;
    vector<int> g[Maxn];
    int used[Maxn];
    int getMaxDep(int u, int fa, int dep) {
	//cerr << u << " " << fa << " " << dep << endl;
	used[u] = 1;
	int ret = dep;
	int i, v;
	for(i = 0; i < g[u].SZ; ++i) {
	    v = g[u][i];
	    if(!used[v]) {
		cmax(ret, getMaxDep(v, u, dep + 1));
	    }
	}
	return ret;
    }
    int maxNodesVisited (vector <int> p, int L)
    {
        int ret = 0;
        int i, j, u, v, w;
        int n = p.SZ + 1;
	for(i = 0; i < n; ++i) g[i].clear();
	for(i = 0; i < p.SZ; ++i) {
	    g[i + 1].PB(p[i]);
	    g[p[i]].PB(i + 1);
	}
	memset(used, 0, sizeof(0));
	w = getMaxDep(0, -1, 1);
	//cout << w << endl;
	if(w > L) ret = L + 1;
	else {
	    ret = w + (L - w + 1) / 2;
	}
	if(ret > n) ret = n;
        return int(ret);
    }
};
 
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int parent[]              = {0, 0};
			int L                     = 2;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int parent[]              = {0, 0};
			int L                     = 3;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int parent[]              = {0, 1, 2, 3};
			int L                     = 2;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int parent[]              = {0,0,0,0,2,4,2,3,1};
			int L                     = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int parent[]              = {0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9};
			int L                     = 4;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int parent[]              = {0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4};
			int L                     = 26;
			int expected__            = 17;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int parent[]              = {0, 0, 2, 0} ;
			int L                     = 100;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int parent[]              = {0, 0, 2};
			int L                     = 4;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

///*      
		case 8: {
			int parent[]              = {};
			int L                     = 10;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		//*/
/*      case 9: {
			int parent[]              = ;
			int L                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int parent[]              = ;
			int L                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

 
#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
