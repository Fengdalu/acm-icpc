#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[200000];
int main()
{
   scanf("%s", s);
   int len = strlen(s);
   bool flg = false;
   for(int i = 0; i < len - 1; i++)
       if(s[i] == '0' && ! flg)flg = true; 
       else printf("%c", s[i]);
   if(flg) putchar(s[len - 1]);
   return 0;
}
