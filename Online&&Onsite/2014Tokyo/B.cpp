#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define LL long long

char s[100];
LL target;
int len;
deque<LL>q1;
deque<char>q2;

void calc()
{
    LL x = q1.back(); q1.pop_back();
    LL y = q1.back(); q1.pop_back();
    char op = q2.back(); q2.pop_back();
    if(op == '*') q1.push_back(x * y); else q1.push_back(x + y);
}

bool check1()
{
    q1.clear();
    q2.clear();
    for(int i = 0; i < len; i++)
    {
        if('0' <= s[i] && s[i] <= '9') q1.push_back(s[i] - '0');
        else
        {
            while(q2.size() && q2.back() == '*' && s[i] == '+') calc();
            q2.push_back(s[i]);
        }
    }
    while(q2.size()) calc();
    return q1.back() == target;
}

bool check2()
{
    LL ans = s[0] - '0';
    for(int i = 1; i < len; i++)
    if('0' <= s[i] && s[i] <= '9')
    {
        if(s[i - 1] == '+') ans = ans + (s[i] - '0');
        else ans = ans * (s[i] - '0');
    }
    return ans == target;
}

 int main()
 {
     while(~scanf("%s", s))
     {
         len = strlen(s);
         scanf("%lld", &target);
         bool f1 = check1(), f2 = check2();
         if(f1 && f2) printf("U\n");
        else if(f1) printf("M\n");
        else if(f2) printf("L\n");
        else printf("I\n");
     }
     return 0;
 }
