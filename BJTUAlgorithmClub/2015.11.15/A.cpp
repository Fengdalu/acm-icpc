#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>G;

int main()
{
    int n, m;
    while(true)
    {
        scanf("%d%d", &n, &m);
        if(!n && !m) break;
        G.clear();
        for(int i = 0; i < n; i++)
        {
            int x; scanf("%d", &x);
            G.push_back(x);
        }
        G.push_back(m);
        sort(G.begin(), G.end());
        for(int i = 0; i < G.size(); i++) if(!i) printf("%d", G[i]); else printf(" %d", G[i]); puts("");
    }
    return 0;
}

