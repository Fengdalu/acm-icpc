#include<cstdio>
#include<cmath>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
char str[14];
vector<pair<int,int> >ans;
void check(int n,int m)
{
    bool flag=false;
    for(int i=0;i<m;i++)
    {
        bool flg=true;
        for(int j=0;j<n;j++)
        {
            if(str[j*m+i]!='X')
            {
                flg=false;
                break;
            }
        }
        if(flg)
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
        ans.push_back(make_pair(n,m));
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        ans.clear();
        scanf("%s",str);
        check(1,12);
        check(2,6);
        check(3,4);
        check(4,3);
        check(6,2);
        check(12,1);
        printf("%d",ans.size());
        for(int i=0;i<ans.size();i++)
            printf(" %dx%d",ans[i].first,ans[i].second);
        printf("\n");
    }
    return 0;
}
