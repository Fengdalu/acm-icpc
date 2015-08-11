#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define N 2000010

bool f1[N];
bool f2[N];
int q[N];

LL c1[N];
LL c2[N];

void init()
{
    int n = 2000000;
    int cnt = 0;
    f1[1] = true; f1[0] = true;
    for(int i = 2; i <= n; i++)
    {
        if(!f1[i]) q[cnt++] = i;
        for(int j = 0; j < cnt && q[j] * i <= n; j++)
        {
            f1[q[j] * i] = true;
            if(i % q[j] == 0) break;
        }
    }

    char s[10];
    for(int i = 1; i <= n; i++)
    {
        memset(s, 0, sizeof s);
        sprintf(s, "%d", i); int len = strlen(s);
        f2[i] = true;
        for(int j = 0; j < len; j++) if(s[j] != s[len - j - 1]) { f2[i] = false; break; }
    }

    c1[0] = 0;
    c2[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!f1[i]) c1[i] = 1;
        if(f2[i]) c2[i] = 1;
        c1[i] += c1[i - 1];
        c2[i] += c2[i - 1];
    }
}


int main()
{
    init();
    LL p, q;
    scanf("%I64d%I64d", &p, &q);
    int ans = -1;
    for(int i = 2000000; i >= 1; i--) if(c1[i] * q <= c2[i] * p) { ans = i; break; }
//    cout << c1[ans] << " " << c2[ans] << endl;
    if(~ans) printf("%d\n", ans);
    else printf("Palindromic tree is better than splay tree\n");
    return 0;
}


