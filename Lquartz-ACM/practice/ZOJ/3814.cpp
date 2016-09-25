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
 
#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 281111
#define Maxm 111111
int step[Maxn];
char init[9][10][10], targ[9][10][10], tini[10][10];
int edge[4][4][5];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
vector<int> ok[9];
int ntar;
void read() {
    int i, j, k, l;
    for(k = 0; k < 3; k++) {
        for(i = 0; i < 8; i++) {
            for(l = 0; l < 3; l++) {
                scanf("%s", init[k * 3 + l][i]);
            }
        }
    }
    for(k = 0; k < 3; k++) {
        for(i = 0; i < 8; i++) {
            for(l = 0; l < 3; l++) {
                scanf("%s", targ[k * 3 + l][i]);
            }
        }
    }
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++){
            for(k = 0; k < 4; k++) {
                scanf("%d", &edge[i][j][k]);
            }
        } 
    }
}
void rotateit(char G[][10]) {
    char tp[10][10];
    int i, j, k;
    for(j = 0; j < 8; j++) {
        for(i = 0; i < 8; i++) {
            tp[j][8 - 1 - i] = G[i][j];
        }
    }
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            G[i][j] = tp[i][j];
        }
    }
}
bool match(char A[][10], char B[][10]) {
    int i, j;
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            if(A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}
void dfs(int status, int dep) {
    if(dep >= 9) {
        ntar++;
        step[status] = -1;
        return;
    }
    for(int i = 0; i < ok[dep].SZ; i++) {
        dfs(status + (ok[dep][i] << (2 * dep)), dep + 1);
    }
}
void outit(char g[][10]) {
    for(int i = 0; i < 8; i++) {
        printf("%s\n", g[i]);
    }
    printf("end\n");
}
void outit1(char str[], int g[][4]) {
    cout << "outit1 " << str << ":"<<endl;
    for(int i = 0; i < 3; i++) {
        cout << "\t";
        for(int j = 0; j < 3; j++) cout << g[i][j] << " ";
        cout << endl;
    }
    cout << "end" << endl;
}
void ready() {
    int i, j;
    for(i = 0; i < Maxn; i++) step[i] = MOD;
    for(i = 0; i < 9; i++) {
//        cout << "ready " << i << endl;
        for(j = 0; j < 8; j++) strcpy(tini[j], init[i][j]);
        ok[i].clear();
        if(match(tini, targ[i])) ok[i].PB(0);
//        outit(tini);
        for(j = 1; j < 4; j++) {
            rotateit(tini);
            if(match(tini, targ[i])) ok[i].PB(j);
//            outit(tini);
        }
    }
//    for(i = 0; i < 9; i++) cout << ok[i].SZ << endl;
    ntar = 0;
    dfs(0, 0);
}
queue<int> Q;
queue<PII> que;
int org[4][4], tar[4][4], visit[4][4];
void moveit(int org[][4], int tar[][4], int b, int & toit) {
    int i, j, x, y, u, v;
    x = b / 3; y = b % 3;
    while(!que.empty()) que.pop();
    que.push(MP(x, y));
    for(i = 0; i < 3; i++) for(j = 0; j < 3; j++) tar[i][j] = visit[i][j] = 0;
    tar[x][y] = 1;
    while(!que.empty()) {
        x = que.front().AA, y = que.front().BB; que.pop();
//        cout << "que " << x << " " << y << endl;
        for(i = 0; i < 4; i++) {
            u = x + dx[i]; v = y + dy[i];
            if(u < 0 || u >= 3 || v < 0 || v >= 3) continue;
            if(tar[u][v]) continue;
//            cout << "find " << u << " " << v << endl;
            if(edge[x][y][(4 - org[x][y] + i) % 4] && edge[u][v][(4 - org[u][v] + i + 2) % 4]) {
                tar[u][v] = -tar[x][y];
                que.push(MP(u, v));
            }
        }
    }
    toit = 0;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            u = (org[i][j] + tar[i][j] + 4) % 4;
            toit += u << (2 * (i * 3 + j));
        }
    }
}
int ans;
void bfs() {
    int i, j, k, status, toit;
    int org[4][4], tar[4][4];
    while(!Q.empty()) Q.pop();
    Q.push(0);
    if(step[0] == -1) {
        ans = 0;
        return;
    }
    step[0] = 0;
    while(!Q.empty()) {
//        cout << "bfs " << status << " " << step[status] << endl;
        status = Q.front(); Q.pop();
        toit = status;
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                org[i][j] = toit & 3;
                toit >>= 2;
            }
        }
//        outit1("org ", org);
        for(i = 0; i < 9; i++) {
            moveit(org, tar, i, toit);
//            outit1("tar", tar);
            if(step[toit] == MOD) {
                step[toit] = step[status] + 1;
                Q.push(toit);
            }
            else if(step[toit] < 0) {
                ans = step[status] + 1;
                return;
            }
        }
    }
}
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        read();
        ready();
        ans = -1;
//        cout << "ntar " << ntar << endl;
        if(ntar != 0) {
            bfs();
        }
        printf("%d\n", ans);
    }
    return 0;
}
