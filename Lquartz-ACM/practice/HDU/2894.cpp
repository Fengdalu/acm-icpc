#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn (1 << 10)
#define Maxm (1 << 11)

int n, m, s;
struct node {
    int v, w, next;
}e[Maxm*2];
int tot, last[Maxn];

void adde(int u, int v, int w) {
    e[tot].v = v; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
}

vector<int> ans;
void dfs(int u) {
    for(int j = last[u]; j != -1; j = e[j].next) {
        if(e[j].w == -1) continue;
        ans.push_back(e[j].w);
        e[j].w = -1;
        dfs(e[j].v);
    }
}

int main() {
	int i, j;
	int u, v;
	while(scanf("%d", &s) != EOF) {
		tot = 0;
		n = 1 << (s - 1);
		m = 1 << s;
		for(i = 0; i < n; i++) {
            last[i] = -1;
		}
		for(i = 0; i < n; i++) {
            u = i;
            for(j = 1; j >= 0; j--) {
                v = ((u << 1) | j) & (n - 1);
                adde(u, v, j);
            }
		}
		ans.clear();
		dfs(n - 1);
		n = ans.size();

		printf("%d ", n);
		for(i = 0; i < n; i++) printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}
