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

class LuckyXor {
public:
	int construct(int);
};

bool check(int x)
{
	while(x)
	{
		if(x % 10 != 4 && x % 10 != 7) return false;
		x /= 10;
	}
	return true;
}

int LuckyXor::construct(int a) {
	for(int i = a + 1; i <= 100; i++) if(check(i ^ a)) return i;
	return -1;		
}


//Powered by [KawigiEdit] 2.0!