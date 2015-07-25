#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 200000

int n;
const char* ans[16] = {"-1", "-1\n", "-1\n", "-1\n", "1 * 2\n5 + 3\n6 + 4\n", "1 * 2\n6 * 3\n7 - 4\n8 / 5\n" ,"1 + 2\n7 + 3\n8 + 4\n9 / 5\n10 * 6\n","1 * 2\n3 / 4\n8 - 9\n5 + 6\n11 / 7\n10 / 12\n","1 + 2\n9 + 3\n10 / 4\n5 * 11\n6 - 7\n8 * 13\n12 + 14\n","1 / 2\n3 - 10\n4 + 5\n12 + 6\n13 / 7\n11 * 14\n15 + 8\n16 - 9\n","1 + 2\n11 + 3\n12 + 4\n13 + 5\n14 / 6\n7 + 8\n16 + 15\n9 / 10\n17 - 18\n","1 + 2\n12 / 3\n4 + 5\n14 + 13\n15 + 6\n16 + 7\n17 + 8\n18 - 9\n19 - 10\n20 - 11\n","1 + 2\n3 - 4\n5 * 14\n6 * 15\n7 * 16\n8 * 17\n9 * 18\n10 * 19\n11 * 20\n12 * 21\n22 + 13\n","1 + 2\n14 + 3\n15 / 4\n5 + 6\n17 - 16\n7 - 8\n19 * 9\n20 * 10\n21 * 11\n13 / 12\n22 + 18\n23 + 24\n","1 + 2\n15 + 3\n16 + 4\n17 / 5\n6 + 7\n19 - 18\n8 - 9\n21 * 10\n22 * 11\n23 * 12\n24 * 13\n25 * 14\n20 + 26\n"};
int main()
{
    //freopen("output.txt", "w", stdout);
    while(~scanf("%d", &n))
    {
        //printf("%d\n", n);
        if(n >= 15)
        {
            printf("1 + 2\n"); int pos = n + 1;
            for(int i = 3; i <= 3; i++) printf("%d + %d\n", i, pos++);
            printf("4 + 5\n"); pos++;
            for(int i = 6; i <= 11; i++) printf("%d + %d\n", i, pos++);
            printf("12 - 13\n"); pos++;
            int i = 14;

            while(i <= n - 2)
            {
                printf("%d * %d\n", i, pos);
                i++; pos++;
            }
            printf("%d / %d\n", n + 2, n - 1);
            i++;
            int F = 2 * n - 2;
            printf("%d / %d\n", n + 9, n);
            printf("%d * %d\n", F - 1, F - 2);
            printf("%d + %d\n", pos, F);
        }
        else
        {
            printf("%s", ans[n]);
        }
    }
    return 0;
}
