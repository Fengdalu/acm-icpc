#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 50010

int c[N];
char s[N];
inline int lowbit(int x)
{
    return x & (-x);
}
int n, m;
void insert(int x, int C)
{
    while(x <= n)
    {
        c[x] += C;
        x += lowbit(x);
    }
}

int query(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

bool check(int n)
{
    if(n<3)
        return false;
    if(s[n-2]=='w'&&s[n-1]=='b'&&s[n]=='w')
        return true;
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        memset(c, 0, sizeof c);
        for(int i = 3; i <= n; i++)
        {
            if(check(i))  insert(i, 1);
        }
        printf("Case %d:\n", CAS);
        for(int i = 0; i < m; i++)
        {
            int op;
            scanf("%d", &op);
            if(!op)
            {
                int L, R;
                scanf("%d%d", &L, &R);
                L++;
                R++;
                if(L==R)
                printf("0\n");
                else
                printf("%d\n", query(R) - query(L + 1));
            }
            else
            {
                int p;
                char buf[3];
                scanf("%d%s", &p, buf);
//                printf("%s\n",buf);
                p++;
                int numf[3];
                int numt[3];
                for(int i=p; i<=n&&i<=p+2; i++)
                {
                    numf[i-p]=check(i);
                }
                s[p]=buf[0];
                for(int i=p; i<=n&&i<=p+2; i++)
                {
                    numt[i-p]=check(i);
                    insert(i,numt[i-p]-numf[i-p]);
                }
            }
        }
    }
    return 0;
}