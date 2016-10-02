#include <bits/stdc++.h>

int diff(std::string a, std::string b) {
	int tot = 0;
	for(int i = 0; i < a.size(); i++)
		if(a[i] != b[i]) tot++;
	return tot;
}

int main() {	
	char buf[100];
	int format; scanf("%d", &format);
	scanf("%s", buf);
	std::string target(buf);
	std::string ans;
	int mx = 100;
	if(format == 24) {
		for(int i = 0; i < 24; i++)
			for(int j = 0; j < 60; j++) {
				sprintf(buf, "%02d:%02d", i, j);
				int t = diff(std::string(buf), target);
				if(t < mx) {
					ans = std::string(buf);
					mx = t;
				}
			}
	}
	else {
		for(int i = 1; i <= 12; i++)
			for(int j = 0; j < 60; j++) {
				sprintf(buf, "%02d:%02d", i, j);
				int t = diff(std::string(buf), target);
				if(t < mx) {
					ans = std::string(buf);
					mx = t;
				}
			}

	}
	printf("%s\n", ans.c_str());
	return 0;
}

