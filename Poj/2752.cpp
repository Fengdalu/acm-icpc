#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i != n; i++)

using namespace std;

int nt[444444];
char s[444444];
vector<int>q;

int main()
{
    while(~scanf("%s", s))
    {
        int j = -1;
        nt[0] = -1;
        int len = strlen(s);
        for(int i = 1; i < len; i++)
        {
            while(j != -1 && s[i] != s[j + 1]) j = nt[j];
            if (s[i] == s[j + 1]) j++;
            nt[i] = j;
        }
        q.clear();
        q.push_back(len);
        j = nt[len - 1];
        while(j != -1) {q.push_back(j + 1); j = nt[j];}
        for(int i = q.size() - 1; i > -1; i--)
            if (i == q.size() - 1)	printf("%d", q[i]);
            else printf(" %d", q[i]);
        putchar('\n');
    }
    return 0;
}