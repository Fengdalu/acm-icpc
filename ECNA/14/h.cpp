#include<cstdio>
#include<cmath>
using namespace std;

void output(int tim)
{
    tim=(tim+43200)%43200;
    int h=tim/3600+1;
    tim%=3600;
    int m=tim/60;
    int s=tim%60;
    printf("%d:%02d:%02d\n",h,m,s);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int a,b;
        char str[12];
        scanf("%d%s%d",&a,str,&b);
        int has=(12-b)*30;
        printf("Case %d: ",cas);
        if(str[0]=='a')
        {
            double need;
            if(has<a)need=a-has;
            else need=360+a-has;
            int ans=(int)round(need*120.0/11.0);
            output((b-1)*3600+ans);
        }
        else
        {
            double need;
            if(a<has)need=has-a;
            else need=360+has-a;
            int ans=(int)round(need*120.0/11.0);
            output((b-1)*3600-ans);
        }
    }
    return 0;
}

[close]

