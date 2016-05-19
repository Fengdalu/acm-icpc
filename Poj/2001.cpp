#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#define rep(i, n) for(int i = 0; i != n; i++)
#define FOR(i, j, k) for(int i = j; i != k; i++)

using namespace std;

struct node
{
    int s;
    node *nt[26];
    node (){s = 0; memset(nt, 0, sizeof nt);}
}f[233333], *top;
int cnt;
int ff[233333];
char s[100];
vector<string>q;

int main()
{
    //freopen("test.in", "r", stdin);
    top = new node();
    int cc = 0;
    cnt = 0;
    q.clear();
    while(~scanf("%s", s))
    {
        cc++;
        int len = strlen(s);
        node *k = top;
        rep(i, len)
        {
            if (k->nt[s[i] - 'a'] == NULL)
            {
                k->nt[s[i] - 'a'] = &f[cnt];
                cnt++;
            }
            k = k->nt[s[i] - 'a'];
            k->s++;
        }
        q.push_back(string(s));
    }
    memset(ff, 0, sizeof ff);
    
    while(q.size())
    {
        string s = q[0];
        q.erase(q.begin());
        node *k = top;
        int j;
        int len = s.size();
        for(j = 0; j < len; j++)
        {
            if (k->s == 1) break;
            k = k->nt[s[j] - 'a'];
        }	
        printf("%s ", &(s[0]));
        for(int k = 0; k < j; k++)
            putchar(s[k]);
        putchar('\n');
    }
}