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

class SumFullSet {
public:
    string isSumFullSet(vector <int>);
};

string SumFullSet::isSumFullSet(vector <int> elements) {
    set<int>s;
    for(int i = 0; i < elements.size(); i++) s.insert(elements[i]);
    for(int i = 0; i < elements.size(); i++)
        for(int j = i + 1; j < elements.size(); j++)
            if(s.find(elements[i] + elements[j]) == s.end()) return "not closed";
    return "closed";
}

//Powered by [KawigiEdit] 2.0!