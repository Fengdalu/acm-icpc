#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define LL long long
const int N = 200010;

LL f1[N], f2[N];
char s1[N], s2[N];
int n;
char ans[100];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s1 >> s2;

    LL down = 0;
    LL ua = 0, ub = 0;
    for(LL i = 1; i <= n; i++) down += (i * i);
    for(char ch = 'A'; ch != 'Z' + 1; ch++)
    {
        memset(f1, 0, sizeof f1); memset(f2, 0, sizeof f2);
        f2[n] = 0;
        for(int i = n - 1; i >= 0; i--) f2[i] = f2[i + 1] + (n - i) * (s2[i] == ch);
        f1[0] = (s2[0] == ch) * (1);
        for(int i = 1; i < n; i++) f1[i] = f1[i - 1] + (s2[i] == ch) * (i + 1);

        //for(int i = 0; i < n; i++) cout << f1[i] << " "; cout << endl;
        //for(int i = 0; i < n; i++) cout << f2[i] << " "; cout << endl;
        for(int i = 0; i < n; i++)
        if(s1[i] == ch)
        {
            //cout << ch << " " << i << " " << f1[i] << " " << f2[i + 1] << endl;
            LL p = (n - i) * f1[i] + (i + 1) * f2[i + 1];
            ua += p / down;
            ub += p % down;
            if(ub >= down) { ua++; ub -= down; }
        }
    }
    sprintf(ans, "%.9f", (double)ua + (double)(ub) / (double)down);
    cout << ans << endl;
    return 0;
}
