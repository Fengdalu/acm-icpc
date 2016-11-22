#include <bits/stdc++.h>

const int N = 2e6+10;
char s[N];
int a[N];
int n;
int main() {
	scanf("%d", &n);
	scanf("%s", s);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	int r = -1;
	int i;
	for(i = 0; i < n; i++) if(s[i] == 'R') { r = i; break; }
	if(r == -1)	 {
		puts("-1");
		return 0;
	}
	bool flag = false;
	int ans = 2e9;
	while(i < n) {
		if(s[i] == 'L') { ans = std::min((a[i] - a[r]) / 2, ans); flag = true; }
		else r = i;
		i++;
	}
	if(flag) printf("%d\n", ans); 
	else puts("-1");
	return 0;
}

