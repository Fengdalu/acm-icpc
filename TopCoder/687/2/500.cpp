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
#include <queue>

using namespace std;

class Quacking {
public:
    int quack(string);
};


bool vis[3000];
int Quacking::quack(string s) {
    string f = "quack";
    for(int i = 0; i < s.size(); i++) vis[i] = false;
    int tot = 0;
    while(true) {
        queue<int>q;
        int t = 0;
        int flag = false;
        for(int i = 0; i < s.size(); i++) if(!vis[i]) {
            if(f[t] == s[i]) {
                q.push(i);
                t++;
            }
            if(t == 5) {
                t = 0;
                while(q.size()) {
                    vis[q.front()] = true;
                    q.pop();
                    flag = true;
                }
            }
        }
        if(flag) tot++;
        else break;
    }
    for(int i = 0; i < s.size(); i++) if(!vis[i]) return -1;
    if(tot == 0) return -1;
    return tot;
}


//Powered by [KawigiEdit] 2.0!