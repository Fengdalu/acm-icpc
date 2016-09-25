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
int n, m;
map < pair < string, string > , int > match;
map < string , int > is;
map < string , int > cnt;
vector <string> vc;
VI gc[55];

class PalindromeGame
{
public:
    int getMaximum (vector <string> f, vector <int> b)
    {
        int ret = 0;
        m = f[0].length();
        match.clear();
        is.clear();
        for(int i = 0; i < f.SZ; i++) {
            is[f[i]] = 1;
            for(int l = 0, r = m - 1; l < r; l++, r--) {
                if(f[i][l] != f[i][r]) {
                    is[f[i]] = 0;
                    break;
                }
            }
            for(int j = 0; j < f.SZ; j++) {
//                if(i == j) continue;
                match[MP(f[i], f[j])] = 1;
                match[MP(f[j], f[i])] = 1;
                for(int l = 0, r = m - 1; l < m; l++, r--) {
                    if(f[i][l] != f[j][r]) {
                        match[MP(f[i], f[j])] = 0;
                        match[MP(f[j], f[i])] = 0;
                        break;
                    }
                }
            }
        }
        for(int x = 0; x <= f.SZ; x++) {
            cnt.clear();
            vc.clear();
//            cout << "delete " << x << endl;
            int ans = 0;
            for(int i = 0; i < f.SZ; i++) {
                if(i == x) {
                    if(is[f[i]]) {
                        ans += b[i];
                    }
//                    cout << " " << f[x] << " " << b[x] << endl;
                    continue;
                }
                if(cnt[f[i]] == 0) {
                    vc.PB(f[i]);
                }
                cnt[f[i]]++;
            }
            for(int i = 0; i < vc.SZ; i++) {
                gc[i].clear();
                for(int j = 0; j < f.SZ; j++) {
                    if(x == j) continue;
                    if(vc[i] == f[j])
                        gc[i].PB(b[j]);
                }
                sort(gc[i].begin(), gc[i].end());
//                cout << vc[i] << " ";for(int j = 0; j < gc[i].SZ; j++) cout << gc[i][j] << " "; cout << endl;
            }
            for(int i = 0; i < vc.SZ; i++) {
                for(int j = i; j < vc.SZ; j++) {
                    if(match[MP(vc[i], vc[j])]) {
                        int t = min(cnt[vc[i]], cnt[vc[j]]);
                        if(i == j) t /= 2;
//                        cout << "match " << vc[i] << " " << vc[j] <<endl;
                        for(int a = gc[i].SZ - 1, c = 0; a >= 0 && c < t; a--, c++) ans += gc[i][a], gc[i].pop_back();
                        for(int a = gc[j].SZ - 1, c = 0; a >= 0 && c < t; a--, c++)ans += gc[j][a], gc[i].pop_back();
                        break;
                    }
                }
            }
//            cout << "x = " << x << " ans = " << ans << endl;
            ret = max(ret, ans);
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
			string front[]            = { "topcoder", "redcoder", "redocpot" };
			int back[]                = { 7, 5, 3 };
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string front[]            = { "rabbit" };
			int back[]                = { 1000000 };
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string front[]            = { "abc", "abc", "def", "cba", "fed" };
			int back[]                = { 24, 7, 63, 222, 190 };
			int expected__            = 499;

			clock_t start__           = clock();
			int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 3: {
			string front[]            = {"xyx", "xyx", "xyx", "zzz", "zzz", "zzz"};
			int back[]                = {5, 7, 2, 1, 6, 4};
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
      case 4: {
			string front[]            = {"fhequickbrownfoxjumpsoverthelazydog", "godyzalehtrevospmujxofnworbkciuqeht"};
			int back[]                = {19, 76};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 5: {
			string front[]            = ;
			int back[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
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
