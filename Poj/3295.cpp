#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

char s[200];

stack<char>op;
stack<bool>num;
map<char, bool>val;
const char v[5] = {'p', 'q', 'r', 's', 't'};

int deal() {
	if(op.empty()) return false;
	char p = op.top();
	if(p == 'N' && !num.empty()) {
		bool c = num.top();
		num.pop();
		num.push(!c);
	}
	else if(p == 'K' && num.size() > 1) {
		bool b = num.top(); num.pop();
		bool a = num.top(); num.pop();
		num.push(a && b);
	}
	else if(p == 'A' && num.size() > 1) {
		bool b = num.top(); num.pop();
		bool a = num.top(); num.pop();
		num.push(a || b);
	}
	else if(p == 'C' && num.size() > 1) {
		bool a = num.top(); num.pop();
		bool b = num.top(); num.pop();
		num.push(!(a && !b));
	}
	else if(p == 'E' && num.size() > 1) {
		bool b = num.top(); num.pop();
		bool a = num.top(); num.pop();
		num.push(a == b);
	}
	else return false;
	op.pop();
	return true;
}

bool check(int mask) {
	for(int i = 0; i < 5; i++) {
		if(1 << i & mask) val[v[i]] = true;
		else val[v[i]] = false;
	}
	while(!op.empty()) op.pop();
	while(!num.empty()) num.pop();

	int len = strlen(s);
	for(int i = 0; i < len; i++) {
		if(val.find(s[i]) == val.end()) {
			op.push(s[i]);
			deal();
		}
		else {
			num.push(val[s[i]]);
		}
	}
	while(deal());
	return num.top();
}

int run() {
	scanf("%s", s);
	if(s[0] == '0') return 1;
	reverse(s, s + strlen(s));
	bool flag = true;
	for(int i = 0; i < (1 << 5); i++) flag &= check(i);
	if(flag) puts("tautology");
	else puts("not");
	return 0;
}

int main() {
	while(!run());
	return 0;
}
