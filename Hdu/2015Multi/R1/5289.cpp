#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define LL long long
#define N 1000010

int a[N];
int n, k;
multiset<int>s;
multiset<int>::iterator iter1, iter2;

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        int l = 0;
        LL ans = 0;
        s.clear();
        for(int i = 0; i < n; i++)
        {
            if(s.size() == 0) { s.insert(a[i]); continue; }
            iter1 = s.begin();
            iter2 = --s.end();
            if(a[i] - *iter1 >= k || *iter2 - a[i] >= k)
            {
                //cout << "SZ: " << s.size() << endl;
                while(s.size())
                {
                    iter1 = s.begin();
                    iter2 = --s.end();
                    //cout <<"BIG SMALL: "<< *iter1 << " " << *iter2 <<endl;

                    if(a[i] - *iter1 >= k || *iter2 - a[i] >= k)
                    {
                        ans += (LL)s.size();
                        s.erase(s.find(a[l]));
                        l++;
                    }
                    else break;
                }
                s.insert(a[i]);
            }
            else s.insert(a[i]);
        }
        ans += (LL)s.size() * (s.size() + 1) / 2;
        printf("%I64d\n", ans);
    }
    return 0;
}