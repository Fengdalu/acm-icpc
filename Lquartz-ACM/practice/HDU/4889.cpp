#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int K, k;
int n, m;
int C;
vector<pair<int,int> > edges[111];

long long spfa_slf() {
    deque<int> q;
    vector<long long> dist(n+1, ~0ULL>>1);
    vector<bool> inQueue(n+1, false);
    dist[1] = 0;
    q.push_back(1);
    inQueue[1] = true;

    int doge = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop_front();
        if(doge++ > C) {
            puts("doge");
            return 233;
        }
        for(vector<pair<int,int> >::iterator it = edges[x].begin();
                it != edges[x].end(); ++it) {
            int y = it->first;
            int w = it->second;
            if(dist[y] > dist[x] + w) {
                dist[y] = dist[x] + w;
                if(!inQueue[y]) {
                    inQueue[y] = true;
                    if(!q.empty() && dist[y] > dist[q.front()])
                        q.push_back(y);
                    else
                        q.push_front(y);
                }
            }
        }
        inQueue[x] = false;
    }
    return dist[n];
}

int main() {
    int i, j;
    while(scanf("%d", &K) != EOF) {
        C = K;
        k = 28;
        n = 2 * k + 1;
        m = 3 * k;
        printf("%d %d\n", n, m);
//        for(i = 0; i < 111; i++) edges[i].clear();
        for(i = 1; k > 0; k--, i += 2) {
            printf("%d %d %d\n", i, i + 1, 0);
//            edges[i].push_back(make_pair(i + 1, 0));
            printf("%d %d %d\n", i, i + 2, -(1 << (k - 1)));
//            edges[i].push_back(make_pair(i + 2, -(1 << (k - 1))));
            printf("%d %d %d\n", i + 1, i +2, -(1 << k));
//            edges[i + 1].push_back(make_pair(i +2, -(1 << k)));
            m += 3;
        }
//        spfa_slf();
    }
    return 0;
}
