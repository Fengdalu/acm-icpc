#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
#define OP begin()
multiset<int>s;
multiset<int>::iterator it;


int main()
{
    int n; scanf("%d", &n);
    s.clear();
    int ans = 0;
    for(int i = 0; i < n; i++) { int x; scanf("%d", &x); s.insert(x); }
    while(s.size())
    {
        while(s.size() >= 2)
        {
            it = s.OP; it++;
            if(*it != *s.OP) break;
            else
            {
                int q = *s.OP;
                s.erase(s.OP); s.erase(s.OP);
                s.insert(q + 1);
            }
        }
        ans++;
        s.erase(s.OP);
    }
    printf("%d\n", ans);
    return 0;
}