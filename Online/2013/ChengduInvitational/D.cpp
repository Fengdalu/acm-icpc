#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
const char *s1 = "abc";
const char *s2 = "aaaababb";
const char *s3 = "aababb";
int main()
{
    int _T; scanf("%d", &_T);
    for(int ii = 1; ii <= _T; ii++)
    {
        scanf("%d%d", &m, &n);
         printf("Case #%d: ", ii);
        if(m == 1)
        {
            for(int i = 0; i < n; i++) printf("a");
            printf("\n");
        }
        else if(m >= 3)
        {
            for(int i = 0; i < n; i++) printf("%c", s1[i % 3]);
            printf("\n");
        }
        else
        {
            if(n == 1) printf("a\n");
            else if(n == 2) printf("ab\n");
            else if(n == 3) printf("aab\n");
            else if(n == 4) printf("aabb\n");
            else if(n == 5) printf("aaaba\n");
            else if(n == 6) printf("aaabab\n");
            else if(n == 7) printf("aaababb\n");
            else if(n == 8) printf("aaababbb\n");
            else
            {
                printf("%s", s2);
                n -= 8;
                while(n >= 6)
                {
                    printf("%s", s3);
                    n -= 6;
                }
                if(n <= 4) { while(n--) printf("a"); }
                else for(int i = 0; i < n; i++) printf("%c", s3[i]);
                printf("\n");
            }
        }
    }
    return 0;
}
