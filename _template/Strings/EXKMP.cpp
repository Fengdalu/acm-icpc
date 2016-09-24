/* Hdu 4300
 * S 为主串 , T 为子串 ,
 * LS 为 S 长度 , LT 为 T 长度 ,
 * B[i] 表示 S[i] 匹配了 B[i] 长度的 T
 */
#include <bits/stdc++.h>
const int Maxn = 1e5;
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
            ind = std::max(0, k + next[k] - i);
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
            ind = std::max(0, p - i + 1);
            while(ind + i < LS && ind < LT && S[ind + i] == T[ind]) ind++;
            B[i] = ind;
            k = i;
        }
    }
}
