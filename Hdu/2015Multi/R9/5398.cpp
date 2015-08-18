#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define PII pair<int, int>
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define LL long long
#define AA first
#define BB second
typedef pair< int, PII > PP;

set< PP >s, s1;
set< PP >::iterator iter;
int f[100010];

int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a % b);
}

int find(int x)
{
    if(f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}

LL calc(int n)
{
    for(int i = 1; i < n; i++) s.insert(PP(-gcd(n, i), MP(n, i)));
    for(int i = 1; i <= n; i++) f[i] = i;
    LL ans = 0;
    int c = 0;
    for(iter = s.begin(); iter != s.end(); iter++)
    {
        s1.insert(*iter);
        if(find(iter->BB.AA) != find(iter->BB.BB))
        {
            ans += iter->AA;
            f[find(iter->BB.AA)] = find(iter->BB.BB);
            c++;
            if(c == n - 1) break;
        }
    }
    swap(s1, s);
    s1.clear();
    return -ans;
}


int main()
{
    FILE *fp;
    s.clear();
    fp = fopen("output.txt", "w");
    for(int i = 1; i <= 1000000; i++)
    {
        LL ans = calc(i);
        if(i == 100 || i == 1000 || i == 10000 || i == 100000) printf("%d ", i);
        fprintf(fp, "%I64d\n", ans);
    }
    fclose(fp);
    return 0;
}
