#include <iostream>
#include <cstring>
#include <cstdio>
#define N 2000

using namespace std;

struct obj {
  int x, y;
  int c;
} q[N * N];

bool vis[N][N];
char map[N][N];
int C, R;


obj bfs(obj rt) {
  memset(vis, 0, sizeof vis);
  vis[rt.x][rt.y] = true; 
  int l = 0, r = 0;
  q[l] = rt;
  while(l <= r) {
    obj p = q[l++]; 
    int x, y;

    x = p.x + 1; y = p.y;
    if(x < R && y < C && x > -1 && y > -1 && !vis[x][y] && map[x][y] == '.') {
      vis[x][y] = true; ++r;
      q[r].x = x; q[r].y = y;
      q[r].c = p.c + 1;
    }

    x = p.x - 1; y = p.y;
    if(x < R && y < C && x > -1 && y > -1 && !vis[x][y] && map[x][y] == '.') {
      vis[x][y] = true; ++r;
      q[r].x = x; q[r].y = y;
      q[r].c = p.c + 1;
    }

    x = p.x; y = p.y + 1;
    if(x < R && y < C && x > -1 && y > -1 && !vis[x][y] && map[x][y] == '.') {
      vis[x][y] = true; ++r;
      q[r].x = x; q[r].y = y;
      q[r].c = p.c + 1;
    }

    x = p.x; y = p.y - 1;
    if(x < R && y < C && x > -1 && y > -1 && !vis[x][y] && map[x][y] == '.') {
      vis[x][y] = true; ++r;
      q[r].x = x; q[r].y = y;
      q[r].c = p.c + 1;
    }
  }
  return q[r];
}

int T;
int main() {
  scanf("%d", &T);
  for(int ii = 0; ii < T; ii++) {
    scanf("%d%d", &C, &R);
    for(int i = 0; i < R; i++)
      scanf("%s", map[i]); 
    obj rt;
    rt.c = 0;
    bool flg = false;
    for(int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) if(map[i][j] == '.') {
        rt.x = i; rt.y = j; 
        flg = true;
        break;
      }
      if(flg) break;
    }
    rt = bfs(rt);
    rt.c = 0;
    printf("Maximum rope length is %d.\n", bfs(rt).c);
  }
  return 0;
}
