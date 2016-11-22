#include <iostream>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

multiset<int>s;
multiset<int>::iterator iter;

int main()
{
    int n; scanf("%d", &n);
    int t; scanf("%d", &t);
    for(int i = 1; i < n; i++)
    {
        int x; scanf("%d", &x);
        s.insert(x);
    }
    int ans = 0;

    while(true)
    {
        iter = s.end(); iter--;
        int num = *iter;
        if(num >= t) { ans++; t++; num--; s.erase(iter); s.insert(num); }
        else break;
    }

    printf("%d", ans);
    return 0;
}
