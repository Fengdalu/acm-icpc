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

VI vg;
int dp[2][800000];
short g[7800000];
int kk, len;
char str[100];
VI bt;
//map < int, int > gmap;

class AmoebaCode
{
public:
    int e[10];
    void pregao(string code, int K) {
        kk = K;
        len = code.length();
        e[0] = 1;
        for(int i = 1; i < 10; i++) e[i] = e[i - 1] * 10;
        for(int i = 0; i < code.length(); i++) str[i] = code[i];
        str[code.length()] = '\0';
        memset(g, 0, sizeof(g));
        memset(dp, -1, sizeof(dp));
        vg.clear();
        bt.clear();
//        gmap.clear();
        make(0, bt);
//        cout << "make" << endl;
//        for(int i = 0; i < vg.SZ; i++) printf("vg %d\n", vg[i]);
        bt.clear();
        dfs(0, bt);
//        cout << "dfs" << endl;
    }
    int getdist(VI & bt, int & x) {
        int pre[10], dist = 1000;
        x = 0;
        for(int i = 0; i <= kk; i++) pre[i] = 0x3f;
        for(int i = bt.size() - 1; i >= 0; i--) {
                x = x * 10 + bt[i];
            dist = min(dist, pre[bt[i]] - i);
            pre[bt[i]] = i;
        }
//        for(int i = 0; i < bt.SZ; i++) {
//            x = x * 10 + bt[i];
//        }
//        printf("dist %d %d\n", x, dist);
        return min( (int)bt.SZ, dist);
//        return dist;
    }

    void dfs(int dep, VI & bt) {
        if(dep == kk) {
            int x, dist = getdist(bt, x);
//            printf("dist %d %d\n", x, dist);
            dp[0][x / 10] = max(dp[0][x / 10], dist);
            return;
        }

        if(str[dep] == '0') {
            for(int i = 1; i <= kk; i++) {
                bt.PB(i);
                dfs(dep + 1, bt);
                bt.pop_back();
            }
        }
        else {
            bt.PB(str[dep] - '0');
            dfs(dep + 1, bt);
            bt.pop_back();
        }
    }
    void make(int dep, VI & bt) {
        if(dep >= kk - 1) {
            int pre[10] = {0}, x = 0, z;
            for(int i = bt.size() - 1; i >= 0; i--) {
                pre[bt[i]]++;
                x = x * 10 + bt[i];
            }
//            ok[x].clear();
//            for(int i = 1; i <= kk; i++) {
//                if(!pre[i]) ok[x].PB(i);
//            }

            int dist = getdist(bt, z);
            if(dep == kk - 1) {
                vg.PB(x);
            }
//            printf("g %d %d\n", x, dist);
            if(dep == kk) {
//                gmap[x] = dist;
                g[x] = dist;
                return;
            }
        }
        for(int i = 1; i <= kk; i++) {
            bt.PB(i);
            make(dep + 1, bt);
            bt.pop_back();
        }
    }
//    int getit(int y) {
//        int x = y;
//        if(gmap[y] == 0) {
//            bt.clear();
//            while(y) {
//                bt.PB(y % 10);
//                y /= 10;
//            }
//            gmap[x] = getdist(bt, y);
//        }
//        return gmap[x];
//    }
    int find (string code, int K)
    {
        int xo = 0;
        for(int i = 0; i < code.length(); i++) {
            if(code[i] != '0') break;
            else xo++;
        }
        while(xo > K) code = code.substr(1, code.length()), xo--;
        xo = 0;
        for(int i = code.length() - 1; i >= 0; i--) {
            if(code[i] != '0') break;
            else xo++;
        }
        while(xo > K) code = code.substr(0, code.length() - 1), xo--;
//        cout << sizeof(dp)  + sizeof(g)<< endl;
        if(K == 1) return 1;
        pregao(code, K);
        int p = 1, q = 0;
        for(int i = kk - 1; i < len - 1; i++) {
            p ^= 1; q ^= 1;
            for(int j = 0; j < vg.SZ; j++) dp[q][vg[j]] = -1;
            for(int j = 0; j < vg.SZ; j++) {
                int x, y, z, ma;
                x = vg[j];
                if(dp[p][x] == -1) continue;
                if(str[i + 1] == '0') {
                    for(int k = 1; k <= kk; k++) {
                        y = x + k * e[kk - 1];
                        z = y / 10;
                        dp[q][z] = max(dp[q][z], min(dp[p][x], (int)g[y]));
                    }
                }
                else {
                    y = x + (str[i + 1] - '0') * e[kk - 1];
                    z = y / 10;
                    dp[q][z] = max(dp[q][z], min(dp[p][x], (int)g[y]));
                }
            }
        }
        int ret = 0;
        for(int j = 0; j < vg.SZ; j++) {
            ret = max(ret, dp[q][vg[j]]);
        }
//        outit();
        return int(ret);
    }

    void outit() {
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < vg.SZ; j++) {
                printf("dp[%d][%d] %d\n", i, vg[j], dp[i][vg[j]]);
            }
            printf("\n");
        }
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
///*
		case 0: {
			string code               = "01";
			int K                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = AmoebaCode().find( code, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string code               = "1001";
			int K                     = 2;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = AmoebaCode().find( code, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string code               = "1010";
			int K                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = AmoebaCode().find( code, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string code               = "01001";
			int K                     = 3;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = AmoebaCode().find( code, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string code               = "10012031001";
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = AmoebaCode().find( code, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			string code               = "00000000000000000000000000000000000000000012304567";
			int K                     = 7;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = AmoebaCode().find( code, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
      case 6: {
			string code               = "00000010000000000000000000000000400000000000300004";
			int K                     = 7;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = AmoebaCode().find( code, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
//*/
      case 7: {
			string code               = "00000000000000000000000000000000000000000000000000";
			int K                     = 7;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = AmoebaCode().find( code, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
      case 8: {
			string code               = "00000000000000000000000000000000000000000001100001";
			int K                     = 7;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = AmoebaCode().find( code, K );
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
