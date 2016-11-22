/*
 * 待验证
 */
#include <bits/stdc++.h>
typedef std::pair<int, int> pii;
const int N = 1e6+200;
char s[N];
char B[N*2], G[N*2];
char F[2*N];
int Next[N*2];

std::string find(std::string s) {
    int i,j,k,l,N=s.length(); s+=s;
    for(i=0,j=1;j<N;){
        for(k=0;k<N&&s[i+k]==s[j+k];k++);
        if(k>=N) break;
        if(s[i+k]<s[j+k]) j+=k+1;
        else l=i+k,i=j,j=std::max(l,j)+1;
    }
    return s.substr(i,N);
}

std::string find1(std::string s) {
    int i,j,k,l,N=s.length(); s+=s;
    for(i=0,j=1;j<N;){
        for(k=0;k<N&&s[i+k]==s[j+k];k++);
        if(k>=N) break;
        if(s[i+k]>s[j+k]) j+=k+1;
        else l=i+k,i=j,j=std::max(l,j)+1;
    }
    return s.substr(i,N);
}

void getNext(char b[N], int m) {
    int j,k;
    j = 0;
    k = -1;
    Next[0] = -1;
    while(j < m) {
        if(k == -1 || b[j] == b[k])
            Next[++j] = ++k;
        else k = Next[k];
    }
}
// 得到 b 在 a 中的第一次出现位置
// 因为 next 与 STL 冲突所以用Next代替
std::pair<int, int> kmp(char a[N], char b[N], int n, int m) {
    int i = 0, j = 0;
    std::pair<int, int> R(0, 0);
    R.first = -1;
    while(i < n) {
        if(j == -1||a[i] == b[j]) {
            i++;
            j++;
        }
        else j = Next[j];
        if(j == m) {
            if(R.first == -1) R.first = i;
            R.second ++;
        }
    }
    return R;
}

int main() {
    while(~scanf("%s", s)) {
        int len = strlen(s);
        std::string a = find(std::string(s));
        std::string b = find1(std::string(s));
        std::fill(B, B + len * 2 + 1, 0);
        for(int i = 0; i < len; i++) B[i] = a[i];
        for(int i = 0; i < len; i++) G[i] = b[i];

        for(int i = 0; i < len; i++) F[i] = F[i + len] = s[i];

        std::fill(Next, Next + len * 2 + 1, 0);
        getNext(B, len);
        pii R = kmp(F, B, 2 * len, len);
        printf("%d %d", R.first - len + 1, R.second - kmp(s, B, len, len).second);

        std::swap(B, G);
        std::fill(Next, Next + len * 2 + 1, 0);
        getNext(B, len);
        R = kmp(F, B, 2 * len, len);
        printf(" %d %d\n", R.first - len + 1, R.second - kmp(s, B, len, len).second);
    }
    return 0;
}
