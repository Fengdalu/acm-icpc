#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define FOR(i, n) for(int i = 0; i < n; i++)
#define AA first
#define BB second
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define ULL unsigned long long
#define LL long long
#define READ(x) scanf("%d", &x)
typedef pair<int, int> PII;

char s2[40010], s1[40010];
int n;

int mmm(char *s, int len)
{
    int i = 0, j = 1;
    while(true)
    {
        if(i >= len) return j;
        if(j >= len) return i;
        int k = 0;
        while(s[i + k] == s[j + k] && k < n) k++;
        if(s[i + k] < s[j + k]) { i = i + k + 1; if(i == j) i++; }
        else { j = j + k + 1; if(j == i) j++; }
    }
}

int kmp(char *s, char *key)
{

}

int main()
{
    freopen("input.txt", "r", stdin);
    int _T; READ(_T);
	while(_T--)
	{
	    READ(n);
		scanf("%s", s1);
        strcpy(s2, s1);
        reverse(s2, s2 + n);
        for(int i = 0; i < n; i++) s1[i + n] = s1[i];
        for(int i = 0; i < n; i++) s2[i + n] = s2[i];

        int p1 = mmm(s1, n);
        int p2 = mmm(s2, n);
        int flg = 0;
        for(int i = 0; i < n; i++)
        if(s1[i + p1] < s2[i + p2]) { flg = 1; break; }
        else if(s1[i + p1] > s2[i + p2])  { flg = 2; break; }

        if(flg == 1) printf("%d 1\n", (n - p2));
        else if(flg == 2) printf("%d 0\n", p1 + 1);
        else
        {
            p1 = p1 + 1;
            p2 = n - p2;
            if(p1 <= p2) printf("%d 0\n", p1);
            else if(p2 < p1) printf("%d 1\n", p2);
        }
	}
	return 0;
}
