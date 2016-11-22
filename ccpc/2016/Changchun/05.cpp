#include <bits/stdc++.h>
const int N = 2000000;

int next[N];
int a[N], b[N], c[N];
int n, m, p;
// a 为主串 ， b 为钥串
void getNext(int b[], int m) {
    int j,k;
    j = 0;
    k = -1;
    next[0] = -1;
    while(j < m) {
        if(k == -1 || b[j] == b[k])
            next[++j] = ++k;
        else k = next[k];
    }
}
// 得到 b 在 a 中的第一次出现位置
// 因为 next 与 STL 冲突所以用Next代替
int kmp(int a[], int b[], int n, int m) {
    int i = 0, j = 0;
	int tot = 0;
    while(i < n) {
        if(j == -1 || a[i] == b[j]) {
            i++;
            j++;
        }
        else j = next[j];
		if(j == m) tot++;
    }
	return tot;
}

int main() {
	int _t; scanf("%d", &_t);
	for(int cas = 1; cas <= _t; cas++) {
		scanf("%d%d%d", &n, &m, &p);
		std::fill(a, a + n + 5, 0);
		std::fill(b, b + m + 5, 0);
		std::fill(next, next + m + 5, 0);
		for(int i = 0; i < n; i++) scanf("%d", a + i);
		for(int i = 0; i < m; i++) scanf("%d", b + i);
		getNext(b, m);
		int ans = 0;
		for(int i = 0; i < p; i++) {
			int cnt = 0;
			for(int j = i; j < n; j += p) c[cnt++] = a[j];
			ans += kmp(c, b, cnt, m);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
