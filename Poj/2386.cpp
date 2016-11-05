#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>

int main() {

  const int V[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}
    ,{-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

  int n, m;
  while(std::cin >> n >> m)  {

    std::vector<std::string> graph(n);
    std::vector< std::vector<bool> > visited(n, std::vector<bool>(m, 0));

    for(int i = 0; i < n; i++) std::cin >> graph[i];

    int answer = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        if(!visited[i][j] && graph[i][j] == 'W') {
          answer++;
          std::queue< std::pair<int, int> > q;
          q.push(std::make_pair(i, j));
          visited[i][j] = true;
          while(q.size()) {
            std::pair<int, int> now = q.front();
            q.pop();
            for(int i = 0; i < 8; i++) {
              int nextx = now.first + V[i][0];
              int nexty = now.second + V[i][1];
              if(0 <= nextx && nextx < n && 0 <= nexty && nexty < m) {
                if(!visited[nextx][nexty] && graph[nextx][nexty] == 'W') {
                  visited[nextx][nexty] = true;
                  q.push(std::make_pair(nextx, nexty));
                }
              }
            }
          }
        }
    printf("%d\n", answer);
  }
  return 0;
}
