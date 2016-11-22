/*
Author: Mimino
Solution: O(E)  E - number of edges in the graph
*/
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
 
const int MAXN = 1000000;
int N, in[MAXN], visited[MAXN];
vector<int> graph[2][MAXN];
 
int main() {
	while (true) {
		scanf("%d", &N);
		if (!N) break;
		for (int i = 0; i < N; ++i) {
			graph[0][i].clear();
			graph[1][i].clear();
			visited[i] = 0;
		}
		for (int i = 0; i < N; ++i) {
			scanf("%d", in+i);
			if (i+in[i] < N) graph[0][i+in[i]].push_back(i);
			if (i-in[i] >= 0) graph[1][i-in[i]].push_back(i);
		}
 
		queue<int> q;
		visited[0] = 1;
		q.push(0);
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			int mid = node + in[node];
			if (mid < N) {
				for (int i = 0; i < graph[1][mid].size(); ++i) {
					int next = graph[1][mid][i];
					if (!visited[next]) {
						visited[next] = 1;
						q.push(next);
					}
				}
			}
			mid = node - in[node];
			if (mid >= 0) {
				for (int i = 0; i < graph[0][mid].size(); ++i) {
					int next = graph[0][mid][i];
					if (!visited[next]) {
						visited[next] = 1;
						q.push(next);
					}
				}
			}
		}
 
		int result = N-1;
		while (!visited[result]) --result;
		printf("%d\n", result);
	}
 
	return 0;
}
