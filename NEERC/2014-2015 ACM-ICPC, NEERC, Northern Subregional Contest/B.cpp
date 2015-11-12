#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define AA first
#define BB second
#define PII pair<int, int>

vector<PII>p, d;
vector<LL>s1, s2;
LL b, k;
LL cd, cp;

int main()
{
    freopen("buffcraft.in", "r", stdin);
    freopen("buffcraft.out", "w", stdout);
    //ios::sync_with_stdio(false);
    scanf("%I64d%I64d%I64d%I64d", &b, &k, &cd, &cp);
    for(int i = 0; i < cd; i++){ LL x; cin >> x; d.push_back(PII(x, i + 1)); }
    for(int i = 0; i < cp; i++){ LL x; cin >> x; p.push_back(PII(x, i + 1)); }
    sort(d.begin(), d.end());
    sort(p.begin(), p.end());
    reverse(d.begin(), d.end());
    reverse(p.begin(), p.end());

    s1.push_back(0);
    s2.push_back(0);
    for(int i = 0; i < d.size(); i++) if(i == 0) s1.push_back(d[i].AA); else s1.push_back(d[i].AA + s1[s1.size() - 1]);
    for(int i = 0; i < p.size(); i++) if(i == 0) s2.push_back(p[i].AA); else s2.push_back(p[i].AA + s2[s2.size() - 1]);
    LL ans = 0;
    //for(int i = 0; i < s1.size(); i++) cout << s1[i] << " "; cout << endl;
    //for(int i = 0; i < s2.size(); i++) cout << s2[i] << " "; cout << endl;


    int n = -1;
    k = min(k, cd + cp);
    for(int i = 0; i <= k; i++)
    {
        int j = k - i;
        if(i < s1.size() && j < s2.size())
        {
            if(n == -1) n = i;
            else if( (b + s1[i]) * (100 + s2[j]) > (b + s1[n]) * (100 + s2[k - n]) ) n = i;
        }
    }
    printf("%d %d\n", n, k - n);
    for(int i = 0; i < n; i++) printf("%d ", d[i].BB);
    for(int i = 0; i < k - n; i++) printf("%d ", p[i].BB);
    fclose(stdout);
    return 0;
}
