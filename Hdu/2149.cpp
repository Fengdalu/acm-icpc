#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    while(~scanf("%d%d", &m, &n))
    {
        if(n >= m)
        {
            for(int i = m; i <= n; i++)
            {
                if(i != m) printf(" ");
                printf("%d", i);
            }
            printf("\n");
            continue;
        }
        if(m % (n + 1) == 0) printf("none\n");
        else
        {
            printf("%d\n", m % (n + 1));
        }
    }
    return 0;
}
