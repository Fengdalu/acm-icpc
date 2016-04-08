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
string S;
const long long mod = 1e9 + 7;;

class BracketSequenceDiv2 {
public:
    int count(string);
};


long long dp[200][200];
long long cal(int x, int y) {
    if(x == S.size()) return !y;
    long long tot = 0;
    if(dp[x][y] != -1) return dp[x][y];
    if(!y) tot++;
    int j = x;
    while(j < S.size() && S[j] != '(') j++;
    if(j < S.size()) tot += cal(j + 1, y + 1);
    tot %= mod;
    if(y) {
        j = x;
        while(j < S.size() && S[j] != ')') j++;
        if(j < S.size()) tot += cal(j + 1, y - 1);
        tot %= mod;
    }
    return dp[x][y] = tot;
}

int BracketSequenceDiv2::count(string s) {
    S = s;
    for(int i = 0; i < s.size(); i++)
        for(int j = 0; j < s.size(); j++)
            dp[i][j] = -1;
    return (cal(0, 0) - 1) % mod;
}


//Powered by [KawigiEdit] 2.0!