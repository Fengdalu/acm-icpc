#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

stack<int>pre;
vector<int>ans;
vector<char>s;

void run(int CASE) {
	int n;
	scanf("%d", &n);
	s.clear();
	int tot = 0;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		for(int j = 0; j < x - tot; j++) s.push_back('(');
		s.push_back(')');
		tot = x;
	}
	while(pre.size()) pre.pop();
	ans.clear();
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') pre.push(i);
		else {
			int p = pre.top();
			pre.pop();
			int tot = 0;
			for(int j = p; j < i; j++) 
			if(s[j] == ')') tot++;
			ans.push_back(tot + 1);
		}
	}
	for(int i = 0; i < ans.size(); i++) 
	if(i == 0) printf("%d", ans[i]);
	else printf(" %d", ans[i]);
	puts("");
}

int main() {
	int T; 
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) run(i);
	return 0;
}
