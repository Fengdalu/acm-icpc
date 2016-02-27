#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 350000 * 10;
const int Maxm = 30;
int ch[Maxn][Maxm];
int word[Maxn];
int w['z' + 10];
int wcnt = 0;
int cnt = 0;
char a[20], b[20];
int c[Maxn];
int fa[Maxn];

void init() {
	for(char c = 'a'; c != 'z' + 1; c++)
		w[c] = c - 'a';
	memset(ch[0], 0, sizeof ch[0]);
}

int insert(char* s) {
	int p = 0;
	while(*s) {
		int c = w[*s];
		if(!ch[p][c]) {
			ch[p][c] = ++cnt;
			memset(ch[cnt], 0, sizeof ch[cnt]);
		}
		p = ch[p][c];
		s++;
	}
	if(word[p] == 0)  word[p] = ++wcnt;
	return word[p];
}

int find(int x) {
	if(fa[x] == -1) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

int main() {
	init();
	memset(fa, -1, sizeof fa);
	while(~scanf("%s%s", a, b)) {
		int s = insert(a);
		int t = insert(b);
		c[s]++;
		c[t]++;
		if(find(s) != find(t))
			fa[find(s)] = find(t);
	}		
	int rt = find(1);
	int odd = 0;
	for(int i = 1; i <= wcnt; i++) 
	if(find(i) != rt || (c[i] % 2 == 1 && c[i] > 3)) {
		puts("Impossible");
		return 0;
	}
	else if(c[i] % 2 == 1) odd++;

	if(odd == 0 || odd == 2) {
		puts("Possible");
	}
	else 
		puts("Impossible");
	return 0;
}


