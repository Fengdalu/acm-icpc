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

class EllysTimeMachine {
public:
    string getTime(string);
};

string EllysTimeMachine::getTime(string time) {
    int a, b;
    sscanf(time.c_str(), "%d:%d", &a, &b);
    char buf[100];
    sprintf(buf, "%02d:%02d", b == 0 ? 12 : b / 5, a == 12 ? 0 : a * 5);
    return string(buf);
}


//Powered by [KawigiEdit] 2.0!