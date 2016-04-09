#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char buf[100];
int main() {
	string s;
	gets(buf);
	s = string(buf);
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) if(s[i] == '!') cnt++;
	if(cnt == 0) cout << "Pfff";
	else {
		cout << "W";
		for(int i = 0; i < cnt; i++) cout << "o";
		cout << "w";
	}
	return 0;
}
