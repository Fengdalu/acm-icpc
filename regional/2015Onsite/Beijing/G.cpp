#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second

PII f[10], g[10];

int main()
{
    int T; scanf("%d", &T);
    for(int CAS = 1; CAS <= T; CAS++)
    {
        for(int i = 0; i < 4; i++) scanf("%d%d", &g[i].AA, &g[i].BB);
        bool flg = false;
        for(int q = 0; q < (1 << 4); q++)
        {
            for(int i = 0; i < 4; i++) f[i] = g[i];
            for(int i = 0; i < 4; i++) if(q & (1 << i)) swap(f[i].AA, f[i].BB);

            for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) for(int k = 0; k < 4; k++)
            if(i != j && j != k && i != k)
            {
                if(f[i].BB == f[j].BB && f[j].BB == f[k].BB) flg = true;
                if(f[i].AA + f[j].AA == f[k].AA && f[i].BB == f[j].BB) flg = true;
                if(f[i].AA == f[j].AA && f[j].AA == f[k].AA) flg = true;
                if(f[i].BB + f[j].BB == f[k].BB && f[i].AA == f[j].AA) flg = true;
            }
            if(flg) break;
        }
        if(flg) puts("Yes"); else puts("No");
    }
}
