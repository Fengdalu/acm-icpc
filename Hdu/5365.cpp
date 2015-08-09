#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
#define PB(x) push_back(x)
#define sqr(x) ((x) * (x))

int x[50], y[50];
int dis(int a, int b)
{
//    cout << a << " " << b << " " << sqr(x[a] - x[b]) + sqr(y[a] - y[b]) << endl;
    return sqr(x[a] - x[b]) + sqr(y[a] - y[b]);
}

int n;

int main()
{
//    freopen("input.txt", "r", stdin);
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
        int cnt = 0;
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) for(int k = j + 1; k < n; k++) for(int p = k + 1; p < n; p++)
        {
            vector<int>f;
            f.PB(i); f.PB(j); f.PB(k); f.PB(p);
//            cout << f[0] << " " << f[1] << " " << f[2] << " " << f[3] <<endl;
            set<int>r;
            for(int i = 0; i < f.size(); i++) for(int j = i + 1; j < f.size(); j++) r.insert(dis(f[i], f[j]));
            if(r.size() == 2) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

