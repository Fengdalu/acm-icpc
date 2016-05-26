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

class LCMGCD {
public:
    string isPossible(vector <int>, int);
};

//{{6, 27, 81, 729, 6}, 6}
string LCMGCD::isPossible(vector <int> x, int t) {
    int p = 0, q = 0;
    while(t % 2 == 0) { t /= 2; p++; }
    while(t % 3 == 0) { t /= 3; q++; }
    int f[3][3];
    memset(f, 0, sizeof f);
    for(int i = 0; i < x.size(); i++) {
        int a = 0, b = 0;
        while(x[i] % 2 == 0) { x[i] /= 2; a++; }
        while(x[i] % 3 == 0) { x[i] /= 3; b++; }
        if(a == p) a = 0; else if(a < p) a = 1; else a = 2;
        if(b == q) b = 0; else if(b < q) b = 1; else b = 2;
        f[a][b] += 1;
    }
    bool flag = false;
    if(f[0][0] > 1) flag = true;
    if(f[0][0]) {
        if(f[1][1] || f[2][2] || f[1][0] || f[2][0] || f[0][1] || f[0][2]) flag = true;
        if(f[1][2] && f[2][1]) flag = true;
        if(!f[1][2] && !f[2][1]) flag = true;
    }
    if(f[0][1] && f[1][0]) {
        flag = true;
    }
    if(f[0][2] && f[2][0]) {
        flag = true;
    }
    if(f[0][1] && (f[1][2] || f[0][2]) && f[2][0]) {
        flag = true;
    }
    if(f[0][2] && (f[0][1] || f[2][1]) && f[1][0]) {
        flag = true;
    }
    
    cout << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) cout << int(f[i][j]) << " " ;
        cout << endl;
    }
    if(flag) return "Possible";
    return "Impossible";
}


//Powered by [KawigiEdit] 2.0!