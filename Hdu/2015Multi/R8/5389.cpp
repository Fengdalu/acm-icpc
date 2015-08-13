#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
using namespace std;
#define MOD 258280327
#define LL long long
#define PII pair<int, int>
#define PP pair< PII, int >
#define AA first
#define BB second

int n, A, B;
LL f1[10], f2[10];


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &A, &B);
        A %= 9; B %= 9;
        memset(f2, 0, sizeof f2);
        memset(f1, 0, sizeof f1);
        f1[0] = 1;
        int x;
        LL sum = 0;
        while(n--)
        {
            scanf("%d", &x);
            sum = sum + x;
            for(int i = 0; i <= 9; i++) f2[(x + i) % 9] += f1[i];
            for(int i = 0; i <= 9; i++) f2[i] += f1[i];
            swap(f1, f2);
            for(int i = 0; i <= 9; i++) f1[i] %= MOD;
            memset(f2, 0, sizeof f2);
        }
        if((A + B) % 9 != sum % 9)
        {
            if(sum % 9 == A || sum % 9 == B) printf("1\n");
            else printf("0\n");
        }
        else printf("%I64d\n", f1[A]);
    }
    return 0;
}
