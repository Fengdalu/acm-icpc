#include <string.h>
#include <stdio.h>
using namespace std;
char s[100000 + 5];
int main()
{
    while(scanf("%s", s) != EOF)
    {
        int n = strlen(s);
        if(s[0] == 'E') return 0;
        if(s[0] == '-')
        {
            int flag = 1;
            for(int i = 1; i < n; i++)
            {
                if(s[i] != '9') flag = 0;
            }
            if(flag)
            {
                printf("-1");
                puts(s + 1);
                continue;
            }
            for(int i = n - 1; i >= 1; i--)
            {
                if(s[i] < '9')
                {
                    s[i]++;
                    puts(s);
                    break;
                }
            }
            continue;
        }
        int flag = 1;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != '9') flag = 0;
        }
        if(flag)
        {
            printf("-1");
            puts(s);
            continue;
        }
        int canadd = 0;
        int can;
        int out = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            can = 0;
            if(s[i] - '0' != 0) can = 1;
            if(can && canadd >= 2)
            {
                s[i]--;
                int cnt = 2;
                int sum = 0;
                for(int j = i + 1; j < n; j++)
                    sum += s[j] - '0';
                for(int j = i + 1; j < n; j++)
                    s[j] = '0';
                cnt = sum + 2;
                int j = i + 1;
                while(cnt && j < n)
                {
                    if(s[j] == '9') j++;
                    if(s[j] < '9') {s[j]++; cnt--;}
                }
                out = 1;
                int add = 0;
                if(s[0] == '0') add = 1;
                puts(s + add);
                break;
            }
            canadd += '9' - s[i];
        }
        if(out == 0)
        {
            printf("-");
            for(int i = n - 1; i >= 0; i--)
            {
                if(s[i] < '9')
                {
                    s[i]++;
                    break;
                }
            }
            puts(s);
        }
    }
    return 0;
}
