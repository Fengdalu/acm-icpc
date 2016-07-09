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

class DistinguishableSetDiv2 {
public:
	int count(vector <string>);
};

int DistinguishableSetDiv2::count(vector <string> answer) {
	int m = answer[0].size();
	int ans = 0;
	for(int mk = 0; mk < (1 << m); mk++) {
		vector<string>q;
		for(int i = 0; i < answer.size(); i++) {
			string s = "";
			for(int j = 0; j < m; j++)
			if(1 << j & mk) s.push_back(answer[i][j]);
			q.push_back(s);
		}
		sort(q.begin(), q.end());
		bool flag = true;
		for(int i = 0; i < q.size() - 1; i++) if(q[i] == q[i + 1]) flag = false;
		if(flag) ans++;
	}
	return ans;
}


//Powered by [KawigiEdit] 2.0!
