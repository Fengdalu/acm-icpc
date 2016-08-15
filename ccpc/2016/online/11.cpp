#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;

typedef long long ll;
const int N = 100010;
char s[N];
bool f['z'+1];
int main(){
    int _T; scanf("%d", &_T); int cas = 1;
    while(_T--){
        int n; scanf("%s", s); n = strlen(s);
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++) f[s[i]] = true;
        int ans = 0; for(int i = 0; i < 26; i++) if(f[i+'a']) ans++;
        printf("Case #%d: %d\n", cas++ , ans);
    }
    return 0;
}

