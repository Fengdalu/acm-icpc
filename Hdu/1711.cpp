#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORR(i, n) for(int i = 1; i <= (n); i++)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
/*===========================================================*/


const int N = 2000000;

int Next[N];
int a[N], b[N];

// `a为主串，b为钥串`
void getNext(int b[N], int m)
{
	int j,k;
    j = 0;
    k = -1;
    Next[0] = -1;
	while(j < m)
    {
		if(k == -1 || b[j] == b[k])
        Next[++j] = ++k;
		else k = Next[k];
    }
}

// `得到b在a中的第一次出现位置`
// `因为next冲突所以用Next代替`
int KMP_Index(int a[N], int b[N], int n, int m)
{
	int i = 0, j = 0;
    getNext(b, m);
    while(i < n && j < m)
    {
		if(j == -1||a[i] == b[j])
        {
            i++;
            j++;
        }
        else j = Next[j];
    }
    if(j == m) return i - m + 1;
	else return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    int n,m;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
          scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
          scanf("%d",&b[i]);
        printf("%d\n",KMP_Index(a, b, n, m));
    }
    return 0;
}
