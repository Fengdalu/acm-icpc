#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int n, k;

struct node
{
    char s[100];
    int n;
    void get()
    {
        scanf("%s", s);
        n = strlen(s);
    }
}f[2000];

int cmp(node a, node b)
{
    return a.n < b.n;
}

int main()
{
    int ii = 1;
    while(true)
    {
        
        cin >> n >> k;
        if (n == 0 && k == 0) break;
        if (ii != 1) cout << endl;
        for (int i = 0; i < n; i++)
            f[i].get();
        sort(f, f + n, cmp);
        if (n % k != 0) cout << "Case " << ii++ << ": no" << endl;
        
        int flg = 0;
        for (int i = 0; i < n; i += k)
        {
            int av = 0;
            for (int j = i; j < i + k; j++) av = av + f[j].n;
            for (int j = i; j < i + k; j++) if (abs(av - k * f[j].n > 2 * k)){flg = 1; break;}
            if (flg) break;
        }
        if (flg) cout << "Case " << ii++ << ": no" << endl;
        else cout << "Case " << ii++ << ": yes" << endl;
    }
    return 0;
}