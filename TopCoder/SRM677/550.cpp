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

class FourStrings {
public:
	int shortestLength(string, string, string, string);
};

string cp(string a, string b) {
	if(a.find(b) != a.npos) return a;
	for(int i = b.size(); i >= 1; i--) if((int)a.size()- i >= 0) {
		if(b.substr(0, i) == a.substr(a.length() - i))
		return a + b.substr(i);
	}
	return a + b;
}

vector<string>q;
int FourStrings::shortestLength(string a, string b, string c, string d) {
	q.push_back(a);
	q.push_back(b);
	q.push_back(c);
	q.push_back(d);
	int pos[4] = {0, 1, 2, 3};
	string ans = a + b + c + d;
	do{
		string tmp = q[pos[0]];
		for(int i = 1; i < 4; i++) tmp = cp(tmp, q[pos[i]]);
		if(tmp.length() < ans.length()) ans = tmp;
	}while(next_permutation(pos, pos + 4));
	cout << ans << endl;
	return ans.length();
}


//Powered by [KawigiEdit] 2.0!
