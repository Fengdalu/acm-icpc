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

class BearCheats {
public:
	string eyesight(int, int);
};

string BearCheats::eyesight(int A, int B) {
	int i = 0;
	while(A > 0 && B > 0)
	{
		if(A % 10 != B % 10) i++;
		A /= 10; B /= 10;
	}
	if(i > 1 || A != B) return string("glasses");
	return string("happy");
}


//Powered by [KawigiEdit] 2.0!
