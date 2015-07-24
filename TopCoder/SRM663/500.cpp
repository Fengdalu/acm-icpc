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

class ABBA {
public:
	string canObtain(string, string);
};

string ABBA::canObtain(string initial, string target) {		
	if(target.find(initial) == 0)
	{
		bool flg = true;
		for(int i = initial.size(); i < target.size(); i++) { if(target[i] == 'B') { flg = false; break; } }
		if(flg) return string("Possible");
	}		
	bool flg = false;
	for(int i = 0; i < target.size(); i++)
	{
		int p = target.find(initial, i);
		if(p == target.npos) continue; 
		int l = p - 1, r = p + initial.size();
		if(l == -1 || r == target.size()) continue;
		if(target[l] != 'B') continue;
		int c1 = 0, c2 = 0;
		while(l >= 0) { if(target[l] == 'B') c1++; l--; }
		while(r < target.size()) { if(target[r] == 'B') c2++; r++; }
		if(c1 == c2) { flg = true; break; }
	}
	if(flg) return string("Possible");	
	reverse(initial.begin(), initial.end());
	
	if(target.find(initial) == 0)
	{
		bool flg = true;		
		for(int i = initial.size() + 1; i < target.size(); i++) { if(target[i] == 'B') { flg = false; break; } }
		if(flg && target[initial.size()] == 'B') return string("Possible");
	}		
	for(int i = 0; i < target.size(); i++)
	{
		int p = target.find(initial, i);
		if(p == target.npos) continue; 
		int l = p - 1, r = p + initial.size();
		if(l == -1 || r == target.size()) continue;
		if(target[r] != 'B') continue;
		int c1 = 0, c2 = 0;
		while(l >= 0) { if(target[l] == 'B') c1++; l--; }
		while(r < target.size()) { if(target[r] == 'B') c2++; r++; }
		if(c1 + 1 == c2) { flg = true; break; }
	}	
	if(flg) return string("Possible");	
	return string("Impossible");
}


//Powered by [KawigiEdit] 2.0!