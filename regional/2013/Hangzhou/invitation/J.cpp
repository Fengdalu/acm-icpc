#include<set>
#include<cstdio>
int n;
std::set<std::pair<int, int> > S;
int main()
{
    while(scanf("%d",&n),n)
    {
        S.clear();
        S.insert(std::make_pair(1000000000, 1));
        int x,y;
        int cmp;
        int ans;
        std::set<std::pair<int, int> >::iterator it;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&x,&y);
            it = S.lower_bound(std::make_pair(y,0));
            cmp = it->first - y;
            ans = it->second;
            if(it != S.begin() && y - (--it)->first <= cmp)
            {
                ans = it->second;
            }
            printf("%d %d\n",x, ans);
            S.insert(std::make_pair(y,x));
        }
    }
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 