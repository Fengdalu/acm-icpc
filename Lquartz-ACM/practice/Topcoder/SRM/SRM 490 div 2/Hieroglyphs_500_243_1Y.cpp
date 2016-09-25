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
typedef struct line {
    int x1, x2, y1, y2;
    line(){
        line(0,0,0,0);
    }
    line(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
} line;

bool cmp1(const line & a, const line & b) {
    if(a.y1 <= b.y1) return true;
    else return false;
}

bool cmp2(const line & a, const line & b) {
    if(a.x1 <= b.x1) return true;
    else return false;
}

class Hieroglyphs
{
public:
    vector < line > v1, v2, h1, h2;
    bool v[100][100], h[100][100];
    int sv[100][100], sh[100][100];
    int minimumVisible (vector <string> hier1, vector <string> hier2)
    {
        int ret = 0, sum1 = 0, sum2 = 0, over = 0;
        char ch;
        int x1, x2, y1, y2;
        string str;
        for(int i = 0; i < hier1.size(); i++) {
            str = str + "," + hier1[i];
            //istringstream sin (hier1[i]);
        }

        istringstream sin1 (str);
        memset(v, false, sizeof(v));
        memset(h, false, sizeof(h));
        while(sin1 >> ch) {
            sin1 >> x1 >> y1 >> x2>> y2;
            if(x1 == x2) {
                v1.PB(line(x1, y1, x2, y2));
                for(int j = y1; j < y2; j++) v[x1][j] = true;
            } else {
                h1.PB(line(x1, y1, x2, y2));
                for(int i = x1; i < x2; i++) h[i][y1] = true;
            }
            sum1 += (x2 - x1) + (y2 - y1);
        }
        memset(sv, 0, sizeof(sv));
        memset(sh, 0, sizeof(sh));
        for(int i = 0; i <= 80; i++) {
            sv[i][0] = v[i][0];
            for(int j = 1; j <= 80; j++) {
                sv[i][j] = sv[i][j - 1] + v[i][j];
            }
        }
        for(int j = 0; j <= 80; j++) {
            sh[0][j] = h[0][j];
            for(int i = 1; i <= 80; i++) {
                sh[i][j] = sh[i - 1][j] + h[i][j];
            }
        }
        str.clear();
        for(int i = 0; i < hier2.size(); i++) {
            str = str + "," + hier2[i];
        }
        istringstream sin2 (str);
        while(sin2 >> ch) {
            sin2 >> x1 >> y1 >> x2 >> y2;
            if(x1 == x2) {
                v2.PB(line(x1,y1,x2,y2));
            } else {
                h2.PB(line(x1,y1,x2,y2));
            }
            sum2 += (x2 - x1) + (y2 - y1);
        }
        line line1, line2;
        for(int i = -80; i <= 80; i++) {
            for(int j = -80; j <= 80; j++) {
                int temp = 0;
                for(int z2 = 0; z2 < h2.size(); z2++) {
                    line2 = h2[z2];
                    line2.y1 += j;
                    line2.x1 += i; line2.x2 += i;
                    if(line2.y1 < 0 || line2.y1 > 80) continue;
                    line2.x1 = max(0, line2.x1);
                    line2.x2 = min(80, line2.x2);
                    if(line2.x1 >= line2.x2) continue;
                    temp += max(0, sh[line2.x2-1][line2.y1] - (line2.x1 == 0 ? 0 : sh[line2.x1-1][line2.y1]));
                }
                for(int z2 = 0; z2 < v2.size(); z2++) {
                    line2 = v2[z2];
                    line2.y1 += j; line2.y2 += j;
                    line2.x1 += i;
                    if(line2.x1 < 0 || line2.x1 > 80) continue;
                    line2.y1 = max(0, line2.y1);
                    line2.y2 = min(80, line2.y2);
                    if(line2.y1 >= line2.y2) continue;
                    temp += max(0, sv[line2.x1][line2.y2-1] - (line2.y1 == 0 ? 0 : sv[line2.x1][line2.y1-1]));
                }
                if(temp > over) {
                    x1 = i; y1 = j;
                }
                over = max(over, temp);

            }

            if(over == min(sum1, sum2)) break;
        }
        ret = sum1 + sum2 - over;
        printf("sum %d\n", sh[9][0]);
        printf("sum %d\n", sh[10][0]);
        printf("%d %d\n", x1, y1);
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
			string hier1[]            = {"0 0 10 0,10 0 10 3"};
			string hier2[]            = {"0 1 10 1","5 1 5 4"};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = Hieroglyphs().minimumVisible( vector <string>( hier1, hier1 + ( sizeof hier1 / sizeof hier1[0] ) ), vector <string>( hier2, hier2 + ( sizeof hier2 / sizeof hier2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string hier1[]            = {"1 1 1 5"};
			string hier2[]            = {"3 2 5 2"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = Hieroglyphs().minimumVisible( vector <string>( hier1, hier1 + ( sizeof hier1 / sizeof hier1[0] ) ), vector <string>( hier2, hier2 + ( sizeof hier2 / sizeof hier2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string hier1[]            = {"0 2 6 2"};
			string hier2[]            = {"5 1 6 1,8 1 9 1"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = Hieroglyphs().minimumVisible( vector <string>( hier1, hier1 + ( sizeof hier1 / sizeof hier1[0] ) ), vector <string>( hier2, hier2 + ( sizeof hier2 / sizeof hier2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string hier1[]            = {"10 20 10 30,15 20 15 30","10 20 15 20,0 30 30 30"};
			string hier2[]            = {"0 5 0 15,5 5 5 25","0 5 5 5,0 15 5 15"} ;
			int expected__            = 65;

			clock_t start__           = clock();
			int received__            = Hieroglyphs().minimumVisible( vector <string>( hier1, hier1 + ( sizeof hier1 / sizeof hier1[0] ) ), vector <string>( hier2, hier2 + ( sizeof hier2 / sizeof hier2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string hier1[]            = {"10 10 10 20,10 30 10 40","10 10 20 10"};
			string hier2[]            = {"10 0 10 20,10 27 10 35","10 0 20 0"};
			int expected__            = 45;

			clock_t start__           = clock();
			int received__            = Hieroglyphs().minimumVisible( vector <string>( hier1, hier1 + ( sizeof hier1 / sizeof hier1[0] ) ), vector <string>( hier2, hier2 + ( sizeof hier2 / sizeof hier2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			string hier1[]            = {"16 37 16 57,27 13 27 48,65 27 65 53,25 6 25 64", "51 46 51 48,76 6 76 26,6 2 6 47,42 22 42 73", "8 4 8 29,2 37 2 57,70 66 70 78,57 11 57 49", "64 28 64 42,40 12 40 36,53 73 53 80,70 19 70 66", "60 45 60 74,2 26 2 37,43 28 43 47,56 11 56 19", "10 4 10 71,3 6 3 58,33 26 33 29,46 39 46 46", "8 0 8 4,56 33 56 77,13 2 13 45,12 34 12 71", "2 24 2 26,24 18 24 22,69 9 69 56,35 14 35 23", "64 25 64 28,62 32 62 33,20 21 20 32,37 25 37 45", "41 0 41 30,28 3 28 13,79 4 79 56,51 56 51 77", "78 7 78 46,71 5 71 6,60 3 60 45,63 54 63 80", "0 53 0 67,9 50 9 68,50 41 50 80,72 5 72 17", "38 52 38 67,38 26 38 52,78 66 78 76,9 46 9 50", "46 46 46 56,59 14 59 61,9 20 9 46,53 1 53 52", "2 13 2 24,34 17 34 27,68 16 68 71,11 16 11 66", "12 6 12 34,15 39 15 46,13 48 13 72,41 30 41 77", "21 35 21 42,75 5 75 63,0 67 0 77,22 15 22 42", "36 14 36 78,59 0 59 14,54 4 54 11,24 10 24 18", "1 18 1 27,45 49 45 50,57 49 57 63,58 47 58 54", "72 17 72 44,55 35 55 37,65 55 65 74,29 64 29 65", "78 62 78 66,67 44 67 59,40 36 40 75,41 77 41 78", "77 3 77 24,45 24 45 42,33 24 33 25,32 19 32 77", "37 68 37 69,80 3 80 5,65 21 65 27,52 17 52 26", "11 1 11 16,14 49 14 73,71 21 71 72,62 1 62 32", "46 25 46 39,73 5 73 9,25 67 25 69,16 31 16 37", "42 8 42 22,27 48 27 50,78 46 78 62,14 15 14 49", "5 36 5 70,21 42 21 69,33 29 33 43,33 43 33 63", "80 5 80 55,54 11 54 49,27 6 27 13,32 77 32 79", "43 0 43 28,80 55 80 63,16 57 16 75,69 56 69 75", "44 1 44 16,27 5 27 6,63 6 63 50,72 44 72 80", "46 2 46 24,61 31 61 64,5 9 5 17,18 40 18 55", "23 16 23 40,52 12 52 13,59 65 59 78,55 1 55 6", "21 69 21 80,77 30 77 46,39 10 39 17,71 18 71 21", "28 56 28 74,77 24 77 30,54 53 54 72,33 3 33 10", "27 1 27 5,13 76 13 77,55 72 55 76,48 7 48 80", "49 13 49 28,18 0 18 40,44 37 44 71,33 63 33 68", "56 9 56 11,16 9 16 31,1 11 1 13,75 2 75 5", "4 32 4 78,56 7 56 9,35 9 35 14,50 8 50 35", "30 56 30 78,43 47 43 63,50 35 50 41,64 18 64 25", "5 17 5 36,39 33 39 55,64 51 64 52,42 1 42 8", "69 2 69 9,5 70 5 72,68 11 68 16,45 42 45 47", "51 23 51 27,43 63 43 78,14 2 14 15,2 57 2 61", "52 30 52 44,36 6 36 8,47 19 47 61,63 50 63 54", "33 13 33 24,8 37 8 50,70 2 70 19,19 14 19 19", "53 52 53 53,8 32 8 37,24 9 24 10,8 61 8 64,3 0 3 3", "53 67 53 69,6 47 6 62,58 2 58 16,78 4 78 7", "47 0 47 19,77 55 77 66,27 65 27 69,45 9 45 24", "17 14 17 32,4 5 4 26,34 8 34 17,7 23 7 77", "22 4 22 15,71 11 71 18,3 58 3 75,74 41 74 42", "54 0 54 4,20 48 20 79,11 66 11 74,16 0 16 9"};
			string hier2[]            = {"64 17 64 58,20 46 20 51,18 34 18 56,12 1 12 11", "0 37 0 79,31 14 31 63,44 56 44 60,4 46 4 77", "26 5 26 77,70 44 70 75,11 30 11 76,77 0 77 68", "15 24 15 64,6 34 6 51,75 11 75 54,26 0 26 5", "15 70 15 78,35 14 35 18,7 2 7 36,3 32 3 56", "36 2 36 74,58 15 58 70,80 4 80 78,40 16 40 18", "37 41 37 52,33 22 33 23,37 12 37 33,67 0 67 39", "59 29 59 40,21 8 21 11,68 31 68 51,22 49 22 76", "6 9 6 28,63 26 63 31,75 10 75 11,56 7 56 63", "9 18 9 21,14 0 14 35,22 42 22 49,38 30 38 57", "11 26 11 30,46 58 46 80,16 11 16 41,5 35 5 75", "52 5 52 66,47 9 47 33,50 4 50 17,51 1 51 62", "74 24 74 46,27 16 27 58,17 38 17 43,68 51 68 64", "54 41 54 70,78 3 78 17,65 49 65 71,22 11 22 42", "48 48 48 77,11 11 11 26,76 15 76 46,43 38 43 54", "76 46 76 55,22 9 22 11,14 35 14 77,59 16 59 29", "40 4 40 16,66 10 66 15,49 29 49 62,63 11 63 26", "62 12 62 27,53 14 53 58,13 16 13 57,66 49 66 59", "78 50 78 76,66 15 66 49,17 45 17 53,17 60 17 79", "31 5 31 14,39 41 39 52,50 31 50 77,76 1 76 15", "1 18 1 51,11 5 11 11,52 66 52 74,65 47 65 49", "32 62 32 68,59 10 59 16,64 64 64 78,54 24 54 41", "68 6 68 7,79 11 79 46,59 54 59 65,78 76 78 77", "32 1 32 9,69 38 69 40,34 22 34 29,37 33 37 41", "76 74 76 75,20 16 20 34,64 10 64 17,61 18 61 39", "16 41 16 43,62 3 62 12,29 7 29 12,73 45 73 61", "13 8 13 16,54 2 54 3,41 14 41 47,10 14 10 69", "49 62 49 77,55 20 55 73,40 61 40 63,12 25 12 65", "43 14 43 34,60 4 60 78,70 75 70 79,27 58 27 68", "4 14 4 46,43 54 43 78,45 35 45 67,59 1 59 10", "76 0 76 1,65 7 65 47,34 29 34 73,41 67 41 73", "16 43 16 58,0 7 0 16,20 34 20 46,3 8 3 32", "47 37 47 42,6 30 6 34,44 0 44 8,5 34 5 35", "8 44 8 61,43 36 43 38,74 46 74 56,8 17 8 44", "8 61 8 63,28 12 28 71,12 15 12 20,67 57 67 80", "69 11 69 26,71 22 71 66,61 12 61 18,61 11 61 12", "72 37 72 57,3 56 3 74,34 73 34 75,28 71 28 76", "12 11 12 15,42 6 42 56,71 16 71 22,21 0 21 4", "66 0 66 10,56 5 56 7,6 28 6 30,25 57 25 63", "70 32 70 44,31 63 31 68,47 8 47 9,46 27 46 31", "57 7 57 11,7 36 7 68,68 13 68 31,64 0 64 10", "35 34 35 78,12 21 12 25,22 2 22 9,2 7 2 12", "30 63 30 64,5 4 5 34,43 2 43 3,78 24 78 30", "39 69 39 80,44 63 44 66,9 53 9 71,60 78 60 80", "78 30 78 50,21 66 21 67,0 6 0 7,30 27 30 45", "73 8 73 16,17 12 17 24,36 0 36 2,48 7 48 10", "38 4 38 8,45 3 45 8,51 62 51 76,17 0 17 12", "13 57 13 65,15 11 15 24,48 4 48 7,16 1 16 11", "23 50 23 52,33 33 33 59,73 5 73 8,79 46 79 51", "39 3 39 4,43 10 43 14,45 19 45 35,35 6 35 14"};;
			int expected__            = 4986;

			clock_t start__           = clock();
			int received__            = Hieroglyphs().minimumVisible( vector <string>( hier1, hier1 + ( sizeof hier1 / sizeof hier1[0] ) ), vector <string>( hier2, hier2 + ( sizeof hier2 / sizeof hier2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			string hier1[]            = ;
			string hier2[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Hieroglyphs().minimumVisible( vector <string>( hier1, hier1 + ( sizeof hier1 / sizeof hier1[0] ) ), vector <string>( hier2, hier2 + ( sizeof hier2 / sizeof hier2[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string hier1[]            = ;
			string hier2[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Hieroglyphs().minimumVisible( vector <string>( hier1, hier1 + ( sizeof hier1 / sizeof hier1[0] ) ), vector <string>( hier2, hier2 + ( sizeof hier2 / sizeof hier2[0] ) ) );
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
