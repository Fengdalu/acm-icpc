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
#define MOD 1000000007
typedef pair<int, int> PII;
#define N 200010
char s[N];
ULL hash[N];
int len;
ULL pp[N];

// ππ‘Ï
void init()
{
    pp[0] = 1;
    for(int i = 1; i < N; i++) pp[i] = (pp[i - 1] * 26ULL) % MOD;
}

void mh(int p)
{
    if(!p) { hash[0] = (s[0] - 'a'); p++; }
    for(int i = p; i < len; i++) hash[i] = ((hash[i - 1] * 26ULL) % MOD + (s[i] - 'a')) % MOD;
}

// ºÏ≤È
int cp(int x, int y, int l)
{
    if(x + l > len || y + l > len) return false;
    x--; y--;
    if((hash[x + l] - hash[x] * pp[l] % MOD + MOD) % MOD == (hash[y + l] - hash[y] * pp[l] % MOD + MOD) % MOD) return true;
    return false;
}

char A[N], B[N];
int lena, lenb;

int cal(int x, int y, int r)
{
    int l = 0;
    while(l < r)
    {
        int mid = (l + r) / 2 + 1;
        if(cp(x, y, mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    init();
    FOR(ii, T)
    {
        scanf("%s", A); lena = strlen(A);
        scanf("%s", B); lenb = strlen(B);
        len = 0;
        for(int i = 0; i < lena; i++) s[len++] = A[i];
        for(int i = 0; i < lenb; i++) s[len++] = B[i];
        s[len++] = 'a';
        mh(0);

        bool flg = false;
        for(int i = 0; i <= lena - lenb; i++)
        {
            int x = i, y = lena, ll = lenb;
            int l1 = cal(x, y, ll);
            x += l1; y += l1; ll -= l1;
            if(y == lenb + lena) { printf("Case #%d: %d\n", ii + 1, i); flg = true; break; }
            x++; y++; ll--;

            l1 = cal(x, y, ll);
            x += l1; y += l1; ll -= l1;
            if(y == lenb + lena) { printf("Case #%d: %d\n", ii + 1, i); flg = true; break; }
            x++; y++; ll--;

            l1 = cal(x, y, ll);
            x += l1; y += l1; ll -= l1;
            if(y == lenb + lena) { printf("Case #%d: %d\n", ii + 1, i); flg = true; break; }
        }
        if(!flg) printf("Case #%d: %d\n", ii + 1, -1);
    }
    return 0;
}
