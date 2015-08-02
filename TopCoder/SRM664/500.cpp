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
#include <queue>
#include <cstring>
using namespace std;
#define PB(x) push(x)
#define PII pair<int, int>

class BearPlaysDiv2 {
public:
	string equalPiles(int, int, int);
};

bool vis[2000][2000];
queue< pair<int, int> >q;
string BearPlaysDiv2::equalPiles(int A, int B, int C) {
	int n = A + B + C;
	int target = n / 3;
	if(n % 3 != 0) return string("impossible");
	memset(vis, 0, sizeof vis);
	vis[A][B] = true; vis[B][C] = true; vis[A][C] = true; vis[B][A] = true; vis[C][B] = true; vis[C][A] = true;
	q.PB(PII(A, B)); q.PB(PII(B, A)); q.PB(PII(A, C)); q.PB(PII(C, A)); q.PB(PII(C, B)); q.PB(PII(B, C));
	while(q.size())
	{
		PII x = q.front(); q.pop();
		if(x.first == target && x.second == target) return string("possible");
		//cout << x.first << " " << x.second << " " << vis[x.first][x.second] << endl;
		int a = x.first, b = x.second, c  = n - x.first - x.second;
		
		x.first = a; x.second = b;
		if(x.first != x.second){
			if(x.first > x.second) swap(x.first, x.second);
			if(!vis[x.first + x.first][x.second - x.first]) { vis[x.first + x.first][x.second - x.first] = true; q.PB(PII(x.first + x.first, x.second - x.first)); }
			if(!vis[x.second - x.first][x.first + x.first]) { vis[x.second - x.first][x.first + x.first] = true; q.PB(PII(x.second - x.first, x.first + x.first)); }
		}		
		x.first = a; x.second = c;
		if(x.first == target && x.second == target) return string("possible");
		if(x.first != x.second){
			if(x.first > x.second) swap(x.first, x.second);
			if(!vis[x.first + x.first][x.second - x.first]) { vis[x.first + x.first][x.second - x.first] = true; q.PB(PII(x.first + x.first, x.second - x.first)); }
			if(!vis[x.second - x.first][x.first + x.first]) { vis[x.second - x.first][x.first + x.first] = true; q.PB(PII(x.second - x.first, x.first + x.first)); }
		}
		x.first = b; x.second = c;
		if(x.first == target && x.second == target) return string("possible");
		if(x.first != x.second){
			if(x.first > x.second) swap(x.first, x.second);
			if(!vis[x.first + x.first][x.second - x.first]) { vis[x.first + x.first][x.second - x.first] = true; q.PB(PII(x.first + x.first, x.second - x.first)); }
			if(!vis[x.second - x.first][x.first + x.first]) { vis[x.second - x.first][x.first + x.first] = true; q.PB(PII(x.second - x.first, x.first + x.first)); }
		}
		
	}
	return string("impossible");
}

//Powered by [KawigiEdit] 2.0!