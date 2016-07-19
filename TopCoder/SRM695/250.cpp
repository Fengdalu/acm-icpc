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

class BearPasswordLexic {
public:
	string findPassword(vector <int>);
};

string BearPasswordLexic::findPassword(vector <int> x) {
	string s;
	vector<int>q;
	for(int i = x.size() - 1; i >= 0; i--) {
		cout << x[i] << endl;
		if(x[i] < 0) return "";
		for(int j = 0; j < x[i]; j++)  {
		    char c;
		    int cnt = i + 1;
		    q.push_back(cnt);
			for(int j = 0; j < i; j++) x[j] -= i - j + 1;
		}
	}
	sort(q.begin(), q.end());
	int flag = true;
	while(q.size()) {
		reverse(q.begin(), q.end());
		int cnt = *q.begin(); q.erase(q.begin());
		while(cnt--) {
			if(flag) s.push_back('a'); else s.push_back('b');
		}
		flag ^= 1;
	}
	if(s.size() != x.size()) return "";
	return s;
}


//Powered by [KawigiEdit] 2.0!
