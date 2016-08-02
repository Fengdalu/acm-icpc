#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MP make_pair
#define AA first
#define BB second
#define PII pair<int, int>
const int N = 1000010 * 2;
const int mod = 1000000007;

int pk[N];
int pre[N], suc[N];
char a[N];
void manacher(int n)
{
    int mx = 0;
    int p;
    for(int i = 0; i < n; i++)
    {
        if(i < mx) pk[i] = min(pk[2 * p - i], mx - i);
        else pk[i] = 1;
        while(i + pk[i] < n && i - pk[i] > -1 && a[i + pk[i]] == a[i - pk[i]]) pk[i]++;
        if(i + pk[i] > mx) { p = i; mx = i + pk[i]; }
    }
}

int qpow(int x, int y) {
    int ans = 1;
    while(y) {
        ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

pair<int, PII>P[N * 5];
PII TL[N * 5];

char s[N];
int main() {
    while(~scanf("%s", s))  {
        int n = strlen(s);
        for(int i = 0; i < n; i++) a[i * 2 + 1] = s[i];
        for(int i = 0; i <= n; i++) a[i * 2] = '#';
        cout << a << endl;
        int len =  2 * n + 1;
        manacher(len);
        for(int i = 0; i < len; i++) cout << pk[i] << " "; cout << endl;
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            if(pk[i] == 1 && a[i] == '#') continue;
            TL[cnt++] = MP((i - pk[i] + 1) / 2, (i + pk[i] - 2) / 2);
        }
        int NP = 0;
        for(int i = 0; i < cnt; i++) {
            P[NP++] = MP(TL[i].AA, MP(0, TL[i].AA + 1));
            P[NP++] = MP(TL[i].BB + 1, MP(1, TL[i].AA + 1));
        }

        sort(P, P + NP);
        for(int i = 0; i < NP; i++) {
            cout << P[i].AA << " " << P[i].BB.AA << " " << P[i].BB.BB << endl;
        }
        int cur = 1;
        int J = 0;
        int cover = 0;
        for(int i = 0; i < n; i++) {
            while(J < cnt && P[J].AA <= i) {
                if(P[J].BB.AA == 0) {
                    cover++;
                    cur = (cur * P[J].BB.BB) % mod;
                }
                else {
                    cur = (cur * qpow(P[J].BB.BB, mod - 2)) % mod;
                    cover--;
                }
                J++;
            }
            if(cover) pre[i] = cur;
            else pre[i] = 0;
        }
        NP = 0;
        for(int i = 0; i < cnt; i++) {
            P[NP++] = MP(TL[i].AA - 1, MP(0, TL[i].AA + 1));
            P[NP++] = MP(TL[i].BB, MP(1, TL[i].AA + 1));
        }
        sort(P, P + NP);
        reverse(P, P + NP);
        cur = 1; J = 0;
        cover = 0;
        for(int i = n - 1; i >= 0; i--) {
            while(J < cnt && P[J].AA >= i) {
                if(P[J].BB.AA == 1) {
                    cur = (cur * P[J].BB.BB) % mod;
                    cover ++;
                }
                else {
                    cur = (cur * qpow(P[J].BB.BB, mod - 2)) % mod;
                    cover--;
                }
                J++;
            }
            if(cover) suc[i] = cur;
            else suc[i] = 0;
        }
        for(int i = 0; i < n; i++) cout << pre[i] << " "; cout << endl;
        for(int i = 0; i < n; i++) cout << suc[i] << " "; cout << endl;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans * pre[i] % mod * suc[i]) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}
