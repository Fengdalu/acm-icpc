#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int Maxn = 200;

char s1[Maxn], s2[Maxn];
map<char, int> count1, count2;
map<char, int>::iterator it;
vector<int> words1, words2;

int main() {
	scanf("%s%s", s1, s2);
	int len = strlen(s1);
	bool check = true;
	if(len != strlen(s2)) {
		check = false;
	}
	else {
		for(int i = 0; i < len; i++) count1[s1[i]]++;
		for(int i = 0; i < len; i++) count2[s2[i]]++;
		for(it = count1.begin(); it != count1.end(); it++) words1.push_back(it->second);
		for(it = count2.begin(); it != count2.end(); it++) words2.push_back(it->second);
		sort(words1.begin(), words1.end());
		sort(words2.begin(), words2.end());
		if(words1.size() != words2.size()) check = false;
		else
			for(int i = 0; i < words1.size(); i++) if(words1[i] != words2[i]) check = false;
	}
	if(check) puts("YES");
	else puts("NO");
	return 0;
}
