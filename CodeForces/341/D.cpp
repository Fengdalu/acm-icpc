#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int Maxn = 100010;
#define ld long double
#define INF -1e100

string get(int id) {
	switch(id) {
		case 1:
			return "x^y^z";
		case 2:
			return "x^z^y";
		case 3:
			return "(x^y)^z";
		case 4:
			return "(x^z)^y";
		case 5:
			return "y^x^z";
		case 6:
			return "y^z^x";
		case 7:
			return "(y^x)^z";
		case 8:
			return "(y^z)^x";
		case 9:
			return "z^x^y";
		case 10:
			return "z^y^x";
		case 11:
			return "(z^x)^y";
		case 12:
			return "(z^y)^x";
	}
}

ld f(int id, ld x, ld y, ld z) { 
	switch(id) {
		case 1:
			if(x == 1) return INF;
			return z * log(y) + log(log(x)); 
		case 2:
			if(x == 1) return INF;
			return y * log(z) + log(log(x));
		case 3:
		case 4:
			if(x == 1) return INF;
			return log(y * z * log(x));
		case 5:
			if(y == 1) return INF;
			return z * log(x) + log(log(y));
		case 6:
			if(y == 1) return INF;
			return x * log(z) + log(log(y));
		case 7:
		case 8:
			if(y == 1) return INF;
			return log(x * z * log(y));
		case 9:
			if(z == 1) return INF;
			return y * log(x) + log(log(z));
		case 10:
			if(z == 1) return INF;
			return x * log(y) + log(log(z));
		case 11:
		case 12:
			if(z == 1) return INF;
			return log(x * y * log(z));
	}
}

int main() {
	vector< pair<ld, int> >s;
	ld x, y, z;
	cin >> x >> y >> z;
	for(int i = 1; i <= 12; i++) s.push_back(make_pair(f(i, x, y, z), -i));
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	cout << get(-s[0].second);
	return 0;
}
