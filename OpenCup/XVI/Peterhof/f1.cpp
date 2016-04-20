#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

const int maxn = 1000;
const int vx[4] = {-1, 1, -1, 1};
const int vy[4] = {1, -1, -1, 1};
map<pair<int, int>, int>f, g;
typedef map<pair<int, int>, int>::iterator IT;
int P, Q;

void bfs(int x, int y, const map<pair<int, int>, int> *g) {
    queue<pair<int, int> >q;
    q.push(make_pair(x, y));
    while(q.size()) {
        pair<int, int>t = q.front();
        int x = t.first, y = t.second;
        int c = g->find(make_pair(x, y))->second;
        if(c > 1000) break;
        for(int i = 0; i < 4; i++) {
            int a = vx[i] * P + x;
            int b = vy[i] * Q + x;
            if(g->find(make_pair(a, b)) == g->end()) {
                g->insert(make_pair(make_pair(a, b), c + 1));
            }
        }
    }
}

int main() {

}
