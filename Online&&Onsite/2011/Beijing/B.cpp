#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#define N 50010
#define PII pair<int, int>
#define MP(x, y) make_pair(x, y)
#define LL long long

string s;
char buf[1000100];
int t[2 * N], nt[2 * N], op[2 * N];
PII q[2 * N];
PII name[N];
int ind[N];
int cnt2, cnt1, cnt3;
map<PII, int>H;

void add(int a, int b)
{
    op[cnt2] = a;
    t[cnt2] = b;
    nt[cnt2] = ind[a];
    ind[a] = cnt2++;
}

int build(int L, int R)
{
    int x;
    int l, r;
    for(l = L; l <= R && s[l] != '('; l++);
    for(r = R; r >= L && s[r] != ')'; r--);
    if(L <= l && r <= R)
    {
        x = H[MP(L, l - L)];
        int tot = 0;
        int pre = r - 1;
        for(int i = r - 1; i > l; i--)
        {
            if(s[i] == '(') tot++;
            else if(s[i] == ')') tot--;
            else if(s[i] == ',' && tot == 0)
            {
                int to = build(i + 1, pre);
                add(x, to);
                pre = i - 1;
            }
        }
        if(l + 1 <= pre)
        {
            int to = build(l + 1, pre);
            add(x, to);
        }
    }
    else x = H[MP(L, R - L + 1)];
    return x;
}

void dfs(int x)
{
    for(int k = ind[x]; k != -1; k = nt[k])
    {
        q[cnt3++] = PII(x, t[k]);
        dfs(t[k]);
        q[cnt3++] = PII(t[k], x);
    }
}

int main()
{
    //freopen("B.txt", "r", stdin);
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        cnt1 = cnt2 = 0;
        memset(ind, -1, sizeof ind);
        scanf("%s", buf);
        s = string(buf);
        H.clear();
        int pre = 0;
        cnt1 = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] > 'z' || s[i] < 'a')
            {
                if(pre != -1)
                {
                    H[MP(pre, i - pre)] = ++cnt1;
                    name[cnt1] =  MP(pre, i - 1);
                    pre = -1;
                }
            }
            else if(pre == -1) pre = i;
        }
        if(pre != -1 && 'a' <= s[s.length() - 1] && s[s.length() - 1] <= 'z')
        {
            H[MP(pre, s.length() - 1)] = ++cnt1;
            name[cnt1] =  MP(pre, s.length() - 1);
        }
        int rt = build(0, s.length());

        printf("%d\n", cnt1);
        for(int i = 1; i <= cnt1; i++)
        {
            printf("%s\n", s.substr(name[i].first, name[i].second - name[i].first + 1).c_str());
        }
        cnt3 = 0;
        dfs(rt);
        for(int i = 0; i < cnt3; i++)
        {
            printf("%d %d\n", q[i].first, q[i].second);
        }
        puts("");
    }
    return 0;
}