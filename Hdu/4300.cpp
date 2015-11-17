#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int Maxn = 120000;

char S[Maxn], T[Maxn];
int Next[Maxn], B[Maxn];

void preExKmp(char T[], int LT, int next[]) {
    int i, ind = 0, k = 1;
    next[0] = LT;
    while(ind + 1 < LT && T[ind + 1] == T[ind]) ind++;
    next[1] = ind;
    for(i = 2; i < LT; i++) {
        if(i <= k + next[k] - 1 && next[i - k] + i < k + next[k])
            next[i] = next[i - k];
        else {
            ind = max(0, k + next[k] - i);
            while(ind + i < LT && T[ind + i] == T[ind]) ind++;
            next[i] = ind; k = i;
        }
    }
}

void exKmp(char S[], int LS, char T[], int LT, int next[], int B[]) {
    int i, ind = 0, k = 0;
    preExKmp(T, LT, next);
    while(ind < LS && ind < LT && T[ind] == S[ind]) ind++;
    B[0] = ind;
    for(i = 1; i < LS; i++) {
        int p = k + B[k] - 1, L = next[i - k];
        if((i - 1) + L < p)
            B[i] = L;
        else {
            ind = max(0, p - i + 1);
            while(ind + i < LS && ind < LT && S[ind + i] == T[ind]) ind++;
            B[i] = ind;
            k = i;
        }
    }
}

char Map['z' + 10];
char s[100];
int n;

int main()
{
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%s", s);
        scanf("%s", S);

        for(char i = 0; i < 26; i++)
            Map[s[i]] = i + 'a';

        n = strlen(S);
        for(int i = 0; i < n; i++) T[i] = Map[S[i]];
        exKmp(S, n, T, n, Next, B);

        int k = -1;

        for(int i = 1; i < n; i++)
        {
            if(B[i] + i == n && 2 * (i) >= n ) { k = i; break; }
        }
        if(k == -1) k = n;
        for(int i = 0; i < k; i++) printf("%c", S[i]);
        for(int i = 0; i < k; i++) printf("%c", Map[S[i]]);
        puts("");
    }
    return 0;
}
