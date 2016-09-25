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
typedef pair<int, PII> PIII;

class CrouchingAmoebas
{
public:
    vector <LL> sx, sy, x, y;
    vector <LL> pt;
    set < pair<LL, LL> > dset;
    int count (vector <int> xx, vector <int> yy, int a, int t)
    {
        int ret = 0;
        LL A = a+1, T = t;
        for(int i = 0; i < xx.size(); i++) {
            x.PB(xx[i]); y.PB(yy[i]);
        }
        LL D = (1LL << 50);
        for(int i = 0; i < xx.size() - 1; i++) {
            D = min(D, x[i + 1] - x[i]);
            D = min(D, y[i + 1] - y[i]);
        }
        //D = t;
        D = max(D, T);
        sx.clear(); sy.clear();
        LL L = T;
        for(int i = 0; i < x.size(); i++) {
            for(LL xi =  - L; xi <=  + L; xi++) {
                sx.PB(x[i] + xi);
                sy.PB(y[i] + xi);
            }
        }
        LL x1, y1, x2, y2;
        for(int i = 0; i < sx.size(); i++) {
            x1 = sx[i];
            for(int j = 0; j < sy.size(); j++) {
                y1 = sy[j];
                x2 = x1 + A - 1; y2 = y1 + A - 1;
                //if(min(x1, y1) >= -1000000000 && max(x2, y2) <= 1000000000)
                ret = max(ret, doit(x1, y1, x2, y2, x, y, T));
            }
        }
        return int(ret);
    }
    LL getdist(LL x1, LL y1, LL x2, LL y2) {
        return (LL)abs(x1 - x2) + (LL)abs(y1 - y2);
    }

    int doit(LL x1, LL y1, LL x2, LL y2, vector <LL> & x, vector <LL> & y, LL t) {
            pt.clear();
//            printf("doit %d %d %d %d\n", x1, y1, x2, y2);
            for(int i = 0; i < x.size(); i++) {
                if(x1 <= x[i] && x[i] <= x2 && y1 <= y[i] && y[i] <= y2) pt.PB(0LL);
                else {
                    LL dist = getdist(x[i], y[i], x1, y1);

                    if(x1 <= x[i] && x[i] <= x2) {
                        dist = min(dist, (LL)min((LL)abs(y[i] - y1), (LL)abs(y[i] - y2)));
                    }
                    else if(y1 <= y[i] && y[i] <= y2) {
                        dist = min(dist, (LL)min((LL)abs(x[i] - x1), (LL)abs(x[i] - x2)));
                    }
                    else {
                        dist = min(dist, getdist(x[i], y[i], x2, y2));
                        dist = min(dist, getdist(x[i], y[i], x1, y2));
                        dist = min(dist, getdist(x[i], y[i], x2, y1));
                    }
                    pt.PB(dist);
                }
            }
            sort(pt.begin(), pt.end());
//            for(int i = 0; i < pt.size(); i++) {
//                printf("pt %d %lld\n", i, pt[i]);
//            }
            int cnt = 0;
            for(int i = 0; i < pt.size(); i++) {
                if( pt[i] > t ) {
                    break;
                }
                else {
                    t -= pt[i];
                    cnt++;
                }
            }
//            printf("doit %lld %lld %lld %lld cnt %d\n", x1, y1, x2, y2, cnt);
            return cnt;
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
			int x[]                   = {0,0};
			int y[]                   = {0,1};
			int A                     = 1;
			int T                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CrouchingAmoebas().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), A, T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int x[]                   = {0,1,2};
			int y[]                   = {1,2,0};
			int A                     = 1;
			int T                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CrouchingAmoebas().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), A, T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int x[]                   = {0,1,2};
			int y[]                   = {1,2,0};
			int A                     = 1;
			int T                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CrouchingAmoebas().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), A, T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int x[]                   = {0,0,3,3};
			int y[]                   = {0,3,0,3};
			int A                     = 2;
			int T                     = 4;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = CrouchingAmoebas().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), A, T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int x[]                   = {-1000000000,1000000000};
			int y[]                   = {-1000000000,1000000000};
			int A                     = 1;
			int T                     = 15;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CrouchingAmoebas().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), A, T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			int x[]                   = {-30916913, 41333560, 32113741, -25730663, 78089448, 66509792, 60858121, -47561775, -78011395, 52312141, 75654229, -30145606, -71363451, 20488878, 49309512, -86771125, 25112118, -46560595, -74727365, 81342366, 85389846, 11625211, 12298444, 94185775, 62521424, -52093013, -73272365, 68182416, -7158181, 40217602};
			int y[]                   = {-88072815, 31559654, 31895204, -83385343, -89635497, -73735099, 6328240, 52000168, -21330742, -63741287, 34779000, -2487947, 94657221, -18841830, 23500414, 21485395, -24606315, 24215383, -37287254, 75575392, -821602, 56589324, 48654069, 41709312, 62726799, -2628804, -48878141, 22210253, 71129941, -17045472};
			int A                     = 452344435;
			int T                     = 4;
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = CrouchingAmoebas().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), A, T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
      case 6: {
			int x[]                   = {64120008, -43727822, 44587005, -38714430, 38539936, -45580680, -42635928, -33334956, -36932589, -20080759, 3295777, -77661330, -78036681, -44286323, 58139001, 50120815, -76149149, -77218067, 24818917, -7592743, 75007548, -39706017, -87951323, 90762113, 90501529, 97205443, -2509522, -50822795, -80131170, -9745332};
			int y[]                   = {7308966, -33079962, -59222489, 1242129, -90454636, 14837515, -42009250, -59958946, -57621282, 13367922, -22242025, -31662484, -55313165, 33486514, -32023572, 19686500, -24802685, 12421376, 50113207, 38271158, 33033864, -63218453, -84298107, 36736237, 73950778, -98462665, -660305, -14766330, 26043138, 82689769};
			int A                     = 487744930;
			int T                     = 15;
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = CrouchingAmoebas().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), A, T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
      case 7: {
			int x[]                   = {-998139808, -667665059, -257257645, -891817128, 877608998, -692868224, 747650040, 928143061, -507403698, 814121980, -605396082, 920815039, 122262405, 862757259, -389329950, 538851828, 580361913, -194541267, -930899711, -509056112, 77354262, -541574628, 195271991, 157332722, -510943735, -924877352, -302208750, -731405642, -523008193, -90228708};
			int y[]                   = {623858208, 440089135, 713977303, -365858035, -783136683, -337025575, 748442808, -421572448, 878684063, -912176074, -35238480, 173255345, -853991919, -685021716, -908918542, 385195526, -732327420, 965847008, -36096264, -663704670, 620210696, 656036663, 829644914, 866879692, -203201290, -145603243, -567300521, 919695112, 202737120, 855656415};
			int A                     = 574236000;
			int T                     = 15;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = CrouchingAmoebas().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ), A, T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
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
