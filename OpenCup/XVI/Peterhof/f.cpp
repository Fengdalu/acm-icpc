#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

const int maxn = 10000;
const int vx[4] = {1, 1, -1, -1};
const int vy[4] = {1, -1, 1, -1};
int f[maxn][maxn];
int P, Q;

int main() {
    cin >> P >> Q;
    queue<pair<int, int> >q;
    q.push(make_pair(500, 500));
    memset(f, -1, sizeof f);
    f[500][500] = 0;
    while(q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        int c = f[x][y];
        for(int i = 0; i < 4; i++) {
            int a = x + vx[i] * P;
            int b = y + vy[i] * Q;
            if(0 <= a && a < maxn && 0 <= b && b < maxn && f[a][b] == -1)  {
                f[a][b] = c + 1;
                q.push(make_pair(a, b));
            }
        }
        for(int i = 0; i < 4; i++) {
            int a = x + vx[i] * Q;
            int b = y + vy[i] * P;
            if(0 <= a && a < maxn && 0 <= b && b < maxn && f[a][b] == -1)  {
                f[a][b] = c + 1;
                q.push(make_pair(a, b));
            }
        }
    }
    cout << f[501][500];
    return 0;
}
