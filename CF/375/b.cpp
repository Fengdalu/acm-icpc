#include <bits/stdc++.h>

char s[10000];

int cal(std::string s) {
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(')  s[i] = ' ';
		if(s[i] == ')')  s[i] = ' ';
		if(s[i] == '_') s[i] = ' ';
	}
	int tot = 0;
	std::istringstream in(s);
	std::string word;
	while(in >> word) tot++;
	return tot;
}

int cal1(std::string line) {
	int ans = 0;
	int tot = 0;
	for(int i = 0; i < line.size(); i++) {
		if(line[i] == '(') tot++;
		if(line[i] == ')') tot--;
		if(tot || line[i] == '(' || line[i] == ')') line[i] = ' ';
	}
	for(int i = 0; i < line.size(); i++) {
		if(line[i] == '_') line[i] = ' ';
	}
	std::string word;
	std::istringstream in(line);
	while(in >> word) {
		ans = std::max(ans, (int)word.size());
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	std::string line(s);
	int tot = 0;
	int ans1 = cal1(line);
	int ans2 = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') {
			int J = i;
			while(s[J] != ')') J++;
			ans2 += cal(line.substr(i + 1, J - i));
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}
