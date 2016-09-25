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
#define N 2005
#define MOD (1<<20)
#define cmin(x,y) x=min(x,y)
#define M 1000005
struct node {
    int v, l, next;
}e[M];
int tot, last[N];
int dp[N];
class EmoticonsDiv1
{
public:
    int spfa(int s, int t) {
        bool visit[N] = {false};
        queue<int> Q;
        Q.push(s);
        visit[s] = true;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            visit[u] = false;
//            cout << "u " << u << endl;
            for(int j = last[u]; j != -1; j = e[j].next) {
                int v = e[j].v;
//                cout << "\t " << v << " " << dp[u] << " " << dp[v] << " " << e[j].l << endl;
                if(dp[v] > dp[u] + e[j].l) {
                    dp[v] = dp[u] + e[j].l;
                    
                    if(!visit[v]) 
                    {
                        Q.push(v);
                        visit[v] = true;
                    }
                }
            }
        }
        return dp[t];
    }
    void adde(int u, int v, int l) {
        e[tot].v = v; e[tot].l = l; e[tot].next = last[u]; last[u] = tot++;
    }
    int printSmiles (int s)
    {
        int ret = MOD;
        for(int i = 2; i <= 2 * s; i++) dp[i] = MOD;
        dp[1] = 0;
        for(int i = 0; i <= 2 * s; i++) last[i] = -1;
        tot = 0;
        for(int i = 1; i <= 2 * s; i++) {
            for(int j = 2 * i; j <= 2 * s; j+=i) {
                adde(i, j, j / i);
            }
            adde(i, i - 1, 1);
        }
        
        ret = spfa(1, s);
//        for(int i = 0; i <= 2*s; i++) {
//            printf("%d %d \n", i, dp[i]);
//        }
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
			int smiles                = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles( smiles );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int smiles                = 4;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles( smiles );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int smiles                = 6;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles( smiles );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int smiles                = 18;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles( smiles );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int smiles                = 11;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles( smiles );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int smiles                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles( smiles );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int smiles                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles( smiles );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int smiles                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles( smiles );
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
