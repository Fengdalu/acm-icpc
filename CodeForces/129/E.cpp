#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define LL long long
const int N = 100010;

int f[N];
int f1[N];
char s1[N], s2[N];
int n;
char ans[100];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s1 >> s2;
    LL up = 0;
    LL down = 0;
    for(int i = 1; i <= n; i++) down += (LL)i * i;
    for(char ch = 'A'; ch <= 'Z'; ch++)
    {
        int tmp = 0;
        memset(f, 0, sizeof f);
        memset(f1, 0, sizeof f1);
        for(int i = n - 1; i >= 0; i--)
            f[i] = f[i + 1] + (s2[i] == ch);
        f1[0] = f[0];
        for(int i = 1; i >= 0; i--)
            f1[i] = f1[i - 1] + f[i];
        for(int i = 0; i < n; i++)
        if(s1[i] == ch)
            tmp += f1[i] * (n - i);
        up += tmp;
    }
    cout << up << endl;
    cout << down << endl;
    sprintf(ans, "%.9f", (double)up / (double)down);
    cout << ans << endl;
    return 0;
}
