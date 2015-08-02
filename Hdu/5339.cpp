#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#include <set>
#include <vector>
#define N 40020

char s[N], str[N];
int n;
int p[N];

void pk()
{
    int i;
    int mx = 0;
    int id;
    for(i=0; i<n; i++)
    {
        if( mx > i )
            p[i] = min( p[2*id-i], mx-i );
        else
            p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++)
            ;
        if( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}

vector<int>a, b;

int main()
{
    freopen("BB.out", "r", stdin);
    //freopen("BB.ii", "w", stdout);
    int T; scanf("%d", &T);
    while(T--){
        memset(s, 0, sizeof s);
        memset(p, 0, sizeof p);
        memset(str, 0, sizeof str);
        scanf("%s", s); n = strlen(s);
        n += n - 1;

        for(int i = 0; i < n; i++)
        if(i & 1) str[i] = '#';
        else str[i] = s[i / 2];

        pk(); a.clear(); b.clear();

        for(int i = 0; i < n; i++){
            if(p[i] == i + 1) a.push_back(i);
            if(i + p[i] == n) b.push_back(i);
        }
        if(!a.size() || !b.size()){ puts("No"); continue; }
        bool flg = false;
        for(int i = 0; i < a.size(); i++) {  for(int j = lower_bound(b.begin(), b.end(), a[i] + p[a[i]]) - b.begin(); j < b.size(); j++) {
            //cout << "SSS:" << a[i] << " " << b[j] << endl;
            //cout << "BGED " <<  a[i] + p[a[i]] << " " << b[j] - p[b[j]] << endl;
            int bg = a[i] + p[a[i]];
            int ed = b[j] - p[b[j]];
            if(ed < bg) continue;
            if(bg == ed && str[bg] == '#') continue;
            int mid = (bg + ed) / 2;
            int l = min(p[(bg + ed) / 2], (ed - bg + 1) / 2 + 1);
            //cout << "L: " << l << endl;
            if(bg + l == mid + 1 && mid + l == ed + 1) { flg = true; break; }
        }
        if(flg) break;
        }
        if(flg) printf("Yes\n");
        else printf("No\n");
        // for(int i = 0; i < n; i++) cout << p[i] << " "; cout << endl;
    }
    return 0;
}
