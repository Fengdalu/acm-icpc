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

using namespace std;

class ExploringNumbers {
public:
    int numberOfSteps(int);
};

bool chk(int x) {
    if(x == 1) return false;
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0) return false;
    return true;
}

int sqr(int x) { return x * x; }
set<int>s;

int ExploringNumbers::numberOfSteps(int n) {
    int len = 0;
    int nn = n;
    while(len < nn) {
        len++;
        s.insert(n);
        if(chk(n)) break;
        else {
            int t = 0;
            while(n) {
                t += sqr(n % 10);
                n /= 10;
            }
            if(s.find(t) != s.end()) {
                len = nn + 1;
                break;
            }
            n = t;
        }
    }
    if(len < nn) return len;
    return -1;
}


//Powered by [KawigiEdit] 2.0!