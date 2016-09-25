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
#define Maxn 111111
#define Maxm 111111
class ABBADiv1
{
public:
    int n, m;
    int check(string & initial, string & target, int ii, int jj) {
        //printf("check %s %s %d %d\n", initial.c_str(), target.c_str(), ii, jj);
        int head = 0, tail = 0;
        if(ii >= 0 && target[0] != 'B') return 0;
        while(ii >= 0) {
            while(ii >= 0 && target[ii] == 'A') --ii;
            if(ii >= 0) {
                head++;
                --ii;
            }
            if(ii < 0) break;
        }
        while(jj < target.length()) {
            while(jj < target.length() && target[jj] == 'A') ++jj;
            if(jj < target.length()) {
                tail++;
                ++jj;
            }
            else {
                break;
            }
        }
        if(head == tail) return 1;
        else return 0;
    }
    string canObtain (string initial, string target)
    {
        int i, j, u, v, w;
        string pos = "Possible", impos = "Impossible";
        for(i = 0; i + initial.length() <= target.length(); ++i) {
            if(initial == target.substr(i, initial.length())) {
                int ii = i - 1, jj = i + initial.length();
                if(check(initial, target, ii, jj)) return pos;
            }
        }

        reverse(initial.begin(), initial.end());

        for(i = 0; i + initial.length() <= target.length(); ++i) {
            if(initial == target.substr(i, initial.length())) {
                int ii = i - 1, jj = i + initial.length();
                if(ii >= 0 && target[0] != 'B') {
                    continue;
                }
                while(ii >= 0 && target[ii] == 'A') --ii;
                if(ii >= 0 && target[ii] == 'B') {
                    --ii;
                    if(check(initial, target, ii, jj)) return pos;
                }
            }
        }
        
        return string(impos);
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string initial            = "A";
			string target             = "BABA";
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ABBADiv1().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string initial            = "BAAAAABAA";
			string target             = "BAABAAAAAB";
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ABBADiv1().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string initial            = "A";
			string target             = "ABBA";
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ABBADiv1().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string initial            = "AAABBAABB";
			string target             = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB";
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ABBADiv1().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string initial            = "AAABAAABB";
			string target             = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB";
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ABBADiv1().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string initial            = "AABBAA";
			string target             = "AAABBAA";
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ABBADiv1().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string initial            = ;
			string target             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ABBADiv1().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string initial            = ;
			string target             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ABBADiv1().canObtain(initial, target);
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
