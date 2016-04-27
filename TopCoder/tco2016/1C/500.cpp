#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

class ThreeProgrammers {
public:
    string validCodeHistory(string);
};

int na, nb, nc;
int dp[100][100][100][2][3];
struct node {
    int a, b, c, k1, k2;
    node(){};
    node(int a, int b, int c, int k1, int k2): a(a), b(b), c(c), k1(k1), k2(k2) {}
}to[100][100][100][2][3];

int dfs(int a, int b, int c, int k1, int k2) {
    if(a == 0 && b == 0 && c == 0) return true;
    if(dp[a][b][c][k1][k2] != -1) return dp[a][b][c][k1][k2];
    bool flag = false;
    if(a && dfs(a - 1, b, c, min(1, k1 + 1), min(2, k2 + 1))) { flag = true; to[a][b][c][k1][k2] = node(a - 1, b, c, min(1, k1 + 1), min(2, k2 + 1)); return true; }
    else if(k1 && b && dfs(a, b - 1, c, k1 - 1, min(2, k2 + 1))) { flag = true; to[a][b][c][k1][k2] = node(a, b - 1, c, k1 - 1, min(2, k2 + 1)); return true; }
    else if(k2 == 2 && c && dfs(a, b, c - 1, min(1, k1 + 1), 0)) { flag = true; to[a][b][c][k1][k2] = node(a, b, c - 1, min(1, k1 + 1), 0); return true; }
    return dp[a][b][c][k1][k2] = false;
}

string ThreeProgrammers::validCodeHistory(string code) {
    na = nb = nc = 0;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < code.size(); i++)
        if(code[i] == 'A') na++;
        else if(code[i] == 'B') nb++;
        else if(code[i] == 'C') nc++;
    
    if(dfs(na, nb, nc, 1, 2)) {
        node p = node(na, nb, nc, 1, 2);
        string s;
        while(p.a != 0 || p.b != 0 || p.c != 0) {
            node k = to[p.a][p.b][p.c][p.k1][p.k2];
            if(k.a < p.a) s.push_back('A');
            else if(k.b < p.b) s.push_back('B');
            else s.push_back('C');
            p = k;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    else return "impossible";
}


//Powered by [KawigiEdit] 2.0!