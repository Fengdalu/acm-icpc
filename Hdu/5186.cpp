#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define AA first
#define BB second
typedef long long LL;
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define MEM(a) memset(a, 0, sizeof a)

char s[1000];
int n, b;
int ans[1000];
int x;


int cov(char s)
{
    if('0' <= s && s <= '9') return s - '0';
    else return s - 'a' + 10;
}

char uncov(int x)
{
    if(x >= 10) return 'a' + (x - 10);
    else return '0' + x;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> b)
    {    
        memset(ans, 0, sizeof ans);
        int ll = 0;
        while(n--)
        {
            cin >> s;
            int len = strlen(s);
            ll = max(ll, len);
            for(int i = 0; i < len; i++)
            {
                x = ((cov(s[i])) + ans[len - i - 1]) % b;                    ans[len - i - 1] = x;
            }
        }
	int i = 0;
	for(; i < ll - 1; i++) if(ans[ll - i - 1] != 0) break;
        for(; i < ll; i++)    
            cout << uncov(ans[ll - i - 1]);
        cout << endl;
    }
    return 0;
}
