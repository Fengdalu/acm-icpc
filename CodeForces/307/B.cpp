#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 211111;
int f['z' + 1], f1['z' + 1], f2['z' + 1], tmp['z' + 1];
char s[N], a[N], b[N];
string ans;
char buf[1] = "";

void cal(char *a, char *b, string &ans)
{
    ans = string("");
    memset(f, 0, sizeof f);
    memset(f1, 0, sizeof f1);
    memset(f2, 0, sizeof f2);

    int len = strlen(s);
    for(int i = 0; i < len; i++) f[s[i]]++;

    memcpy(tmp, f, sizeof f);

    len = strlen(a);
    for(int i = 0; i < len; i++) f1[a[i]]++;

    len = strlen(b);
    for(int j = 0; j < len; j++) f2[b[j]]++;

    int t1 = N;
    for(char c = 'a'; c <= 'z'; c++)
    if(f1[c] != 0)
        t1 = min(t1, f[c] / f1[c]);

    int m = t1, t2 = 0;
    for(int i = 0; i <= t1; i++)
    {
        int t = N;
        memcpy(f, tmp, sizeof tmp);
        for(char ch = 'a'; ch <= 'z'; ch++) f[ch] -= i * f1[ch];

        for(char ch = 'a'; ch <= 'z'; ch++) if(f2[ch] != 0) t = min(t, f[ch] / f2[ch]);
        if(t + i > m){ m = t + i; t2 = t; }
    }
    memcpy(f, tmp, sizeof tmp);
    for(int i = 0; i < m - t2; i++) ans.append(a);
    for(int j = 0; j < t2; j++) ans.append(b);
    for(char ch = 'a'; ch <= 'z'; ch++) f[ch] -= t2 * f2[ch] + (m - t2) * f1[ch];
    for(char ch = 'a'; ch <= 'z'; ch++)
    while(f[ch])
    {
        buf[0] = ch;
        ans.append(buf);
        f[ch]--;
    }
}

int main()
{

    scanf("%s%s%s", s, a, b);
    int len;
    cal(a, b, ans);
    printf("%s\n", ans.c_str());
    return 0;
}
