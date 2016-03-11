#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = 4000000;
const int maxl = 100;
const int INF = 1e9;
int to[maxn][10];
int word[maxn];
int cnt;
int a[maxl], b[maxl], c[maxl];
int d[maxl];
char s[maxl];

void insert(int *a, int l, int v) {
	int p = 0;
	l = std::min(l, 40);
	for(int i = 0; i < l; i++) {
		if(!to[p][a[i]]) {
			to[p][a[i]] = ++cnt;
			word[cnt] = INF;
			memset(to[cnt], 0, sizeof to[cnt]);
		}
		p = to[p][a[i]];
		word[p] = std::min(word[p], v);
	}
}

void init() {
	memset(word, 0, sizeof word);
	int l1 = 1, l2 = 1;
	b[0] = 1;
	a[0] = 1;	
	insert(a, 1, 0);

	for(int J = 0; J + 2 < 100000; J++) {
		int len = std::max(l1, l2);
		memset(c, 0, sizeof c);
		for(int i = 0; i < len; i++) c[i] = a[i] + b[i];
		for(int i = 0; i < len - 1; i++) {
			c[i + 1] += (c[i]) / 10;
			c[i] %= 10;
		}
		while(c[len - 1] >= 10) {
			c[len] = c[len - 1] / 10;
			c[len - 1] %= 10;
			len++;
		}
		memset(a, 0, sizeof a);
		for(int i = 0; i < len; i++) d[i] = c[len - i - 1];
		insert(d, len, J + 2);
		if(len > 62) {
			for(int i = 0; i < 60; i++) {
				a[i] = b[len - 60 + i];	
			}
			l1 = 60;
			while(!a[l1 - 1]) l1--;
			for(int i = 0; i < 60; i++) {
				b[i] = c[len - 60 + i];
			}
			l2 = 60;
		}
		else {
			std::swap(a, b);
			l1 = l2;
			std::swap(b, c);
			l2 = len;
		}
	}
}

int main() {
	cnt = 0;
	init();
	int Case; 
	scanf("%d", &Case);
	for(int T = 1; T <= Case; T++) {
		scanf("%s", s);
		int len = strlen(s);
		int p = 0;
		bool flag = false;
		for(int i = 0; i < len; i++) 
		if(to[p][s[i] - '0']) {
			p = to[p][s[i] - '0'];
		}
		else { 
			flag = true;
			break;
		}	
		if(flag) 
			printf("Case #%d: %d\n", T, -1);
		else 
			printf("Case #%d: %d\n", T, word[p]);
	}
}
