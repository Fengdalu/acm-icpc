#include <iostream>
#include <cstring>
#include <cstring>
#include <algorithm>
using namespace std;

int smallest(char *s, int len)
{
    int i = 0,j = 1,k = 0;
    while(i<len&&j<len)
    {
        k=0;
        while(k<len&&(s[i+k]==s[j+k]))
            k++;
        if(k>=len)
            break;
        if(s[i+k]>s[j+k])
            i=max(i+k+1,j+1);
        else
            j=max(i+1,j+k+1);
    }
    return min(i,j);
}

char a[10010], b[10010];
char buf1[10010 * 3], buf2[10010 * 3];
int n;

int main() {
    while(~scanf("%s%s", a, b)) {
        n = strlen(a);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) buf1[j] = a[j];
            for(int j = 0; j <= i; j++) buf1[j + i + 1] = a[j];
            for(int j = 0; j <= i; j++) buf2[j] = b[j];
            for(int j = 0; j <= i; j++) buf2[j + i + 1] = b[j];
            buf2[i + i + 2] = buf1[i + i + 2] = 0;
            int p1 = smallest(buf1, i + 1);
            int p2 = smallest(buf2, i + 1);
            bool flag = true;
            int len = i + i + 2;
            for(int j = 0; j <= i; j++) if(flag) flag &= buf2[p2 + j] ==  buf1[p1 + j];
            if(flag) printf("1"); else printf("0");
        }
        printf("\n");
    }
    return 0;
}
