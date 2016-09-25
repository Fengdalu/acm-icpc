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
int n, m;
#define N 6000
#define M 200000
struct node {
    int u, v, c, next;
}E[M];
int tot, last[N];
int visit[60][60];
int S, T;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
map<pair<PII, PII>, bool>dmp;
void addE(int u, int v, int c) {
//    cout << "addE " << u << " " << v << " " << c << endl;
    E[tot].u = u; E[tot].v = v; E[tot].c = c; E[tot].next = last[u]; last[u] = tot++;
    E[tot].u = v; E[tot].v = u; E[tot].c = 0; E[tot].next = last[v]; last[v] = tot++;
}
int dist[N], cur[N], sta[N], que[N], pre[N];
bool bfs(int s, int t, int n) {
    int front = 0, tail = 0;
    memset(dist, -1, sizeof(dist[0]) * (n + 1));
    dist[s] = 0;
    que[tail ++ ] = s;
    while (front < tail) {
        for (int i = last[que[front ++ ]]; i != -1; i = E[i].next)
            if (E[i].c > 0 && dist[E[i].v] == -1){
                dist[E[i].v] = dist[E[i].u] + 1;
                if (E[i].v == t)
                    return 1;
                que[tail ++ ] = E[i].v;
            }
    }
    return 0;
}
int dinic(int s, int t, int n) {
    int maxflow = 0, tp;
    while (bfs(s, t, n)) {
        for (int i = 0; i < n; i ++ )
            cur[i] = last[i];
        int u = s, tail = 0;
        while(cur[s] != -1){
            if(u == t){
                tp = MOD;
                for (int i = tail - 1; i >= 0; i -- )
                    tp = min(tp, E[sta[i]].c);
//                cout << "dinic " << tp << endl;
                maxflow += tp;
                for (int i = tail - 1; i >= 0; i -- ){
                    E[sta[i]].c -= tp;
                    E[sta[i] ^ 1].c += tp;
                    if (E[sta[i]].c == 0)
                        tail = i;
                }
                u = E[sta[tail]].u;
            }
            else if (cur[u] != -1 && E[cur[u]].c > 0
                  && dist[u] + 1 == dist[E[cur[u]].v]) {
                sta[tail ++ ] = cur[u];
                u = E[cur[u]].v;
            }
            else {
                while (u != s && cur[u] == -1)
                    u = E[sta[ -- tail]].u;
                cur[u] = E[cur[u]].next;
            }
        }
    }
    return maxflow;
}
class BlockTheBlockPuzzle {
public:
    void gao(vector<string> & bo) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) 
                visit[i][j] = 0;
        queue<PII> Q;
        VII ve;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(bo[i][j] == '$') {
                    Q.push(MP(i, j));
                    ve.PB(MP(i, j));
                    addE(S, i * n + j, 20000);
                    addE(i * n + j, i * n + j + n * n, 20000);
                }
            }
        }
        while(!Q.empty()) {
            int x = Q.front().AA, y = Q.front().BB;
            Q.pop();
            visit[x][y] = 1;
//            cout << "gao " << x << " " << y << endl;
            for(int k = 0; k < 4; k++) {
                int u = x + 3 * dx[k], v = y + 3 * dy[k];
                if(u < 0 || v < 0 || u >= n || v >= n) continue;
                if(visit[u][v]) continue;
                visit[u][v] = 1;
                ve.PB(MP(u, v));
                if(bo[u][v] == 'b') continue;
                Q.push(MP(u, v));
            }
        }
        dmp.clear();
        for(int i = 1; i < ve.SZ; i++) {
            int u = ve[i].AA, v = ve[i].BB;
            int l = 0;
            if(bo[u][v] == 'b') l = 20000;
            else if(bo[u][v] == '.') l = 1;
            addE(u * n + v, u * n + v + n * n, l);
            if(bo[u][v] == 'b') {
                addE(u * n + v + n * n, T, 20000);
            }
        }
        for(int i = 0; i < ve.SZ; i++) {
            int x = ve[i].AA, y = ve[i].BB;
            if(bo[x][y] == 'b') continue;
            for(int j = 1; j < ve.SZ; j++) {
                if(i == j) continue;
                int u = ve[j].AA, v = ve[j].BB;
                if(dmp[MP(MP(x, y), MP(u, v))]) continue;
                dmp[MP(MP(x, y), MP(u, v))] = true;
                for(int k = 0; k < 4; k++) {
                    if(x + dx[k] * 3 == u && y + dy[k] * 3 == v) {
                        int l = 0;
                        if(bo[x + dx[k]][y + dy[k]] == 'b') l = 20000;
                        else if(bo[x + dx[k]][y + dy[k]] == '.') l++;
                        if(bo[x + 2 *dx[k]][y + 2 * dy[k]] == 'b') l = 20000;
                        else if(bo[x + 2 * dx[k]][y + 2 * dy[k]] == '.') l++;
                        addE(x * n + y + n * n, u * n + v, l);
                        break;
                    }
                }
            }
        }
    }
    int minimumHoles (vector <string> bo) {
        int i, j;
        int ret;
        n = bo.SZ;
        tot = 0;
        for(i = 0; i < N; i++) last[i] = -1;
        S = n * n * 2;
        T = S + 1;
        gao(bo);
        int maxflow = dinic(S, T, T + 1);
        if(maxflow >= 20000) ret = -1;
        else ret = maxflow;
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
			string board[]            = {"b..$",  "....",  "HHHH",  "HHHH"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BlockTheBlockPuzzle().minimumHoles( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string board[]            = {"............H..",  "...............",  "...............",  "HHH$HHH.....H..",  "HHHHHHH........",  "HHHHHHHH.......",  "......b..H.....",  "...............",  "...............",  "...H..H..H.....",  "...............",  "...............",  "...............",  "...............",  "..............."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BlockTheBlockPuzzle().minimumHoles( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string board[]            = {"............H..",  "...............",  "...............",  "HHH$HHH........",  "HHHHHHH........",  "HHHHHHHH.......",  "......b..H.....",  "...............",  "...............",  "...H..H..H.....",  "...............",  "...............",  "...............",  "...............",  "..............."};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = BlockTheBlockPuzzle().minimumHoles( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string board[]            = {"b..$...",  "...H...",  ".......",  "b..b..b",  "...H...",  ".......",  "b..b..b"}  ;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BlockTheBlockPuzzle().minimumHoles( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string board[]            = {"b..b..b",  "..b..b.",  ".......",  "b..$bbb",  ".b.....",  "....b..",  "b..b..b"} ;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = BlockTheBlockPuzzle().minimumHoles( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BlockTheBlockPuzzle().minimumHoles( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BlockTheBlockPuzzle().minimumHoles( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BlockTheBlockPuzzle().minimumHoles( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
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

