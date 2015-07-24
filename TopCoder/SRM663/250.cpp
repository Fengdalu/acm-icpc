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

class ChessFloor {
public:
	int minimumChanges(vector <string>);
};

int ChessFloor::minimumChanges(vector <string> floor) {
	int INF = 0x3f3f3f;
	int ans = INF;	
	for(char p = 'a'; p <= 'z'; p++) for(char q = 'a'; q <= 'z'; q++)if(p != q)
	{ int tmp = 0;
	
	for(int i = 0; i < floor.size(); i++) for(int j = 0; j < floor[i].size(); j++)
	{
		if((i + j) % 2 == 0  && floor[i][j] != p) tmp++;
		if((i + j) % 2 == 1 && floor[i][j] != q) tmp++;
	}
	ans = min(ans, tmp);
	}
	return ans;
}


//Powered by [KawigiEdit] 2.0!