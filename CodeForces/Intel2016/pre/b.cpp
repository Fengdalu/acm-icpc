#include <bits/stdc++.h>
#include <sstream>

char buf[10000000];
int a[200];
int n;
int check(char ch) {
	if(ch == 'a' 
			|| ch == 'e' 
			|| ch == 'i' 
			|| ch == 'o' 
			|| ch == 'u' 
			|| ch == 'y') return 1;
	return 0;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	gets(buf);
	bool flag = true;
	for(int i = 0; i < n; i++) {
		int tot = 0;
		gets(buf);
		std::istringstream in(buf);
		std::string word;
		int token = 0;
		while(in >> word) {
			for(int i = 0; i != word.size(); i++) {
				token += check(word[i]);
			}
		}
		flag &= (a[i] == token);
	}
	if(flag) puts("YES"); else puts("NO");
	return 0;
}
