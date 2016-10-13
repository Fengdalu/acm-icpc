#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
int n,m;
char str[5];
char ch;
char pre[2005][2005];
char last[2005][2005];
char tab[2005][2005];
bool intable(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)return true;
    return false;
}
int main()
{
    bool cas=false;
    while(1)
    {
        memset(tab,0,sizeof(tab));
        cas=true;
        scanf("%d%d '%c'",&n,&m,&ch);
        if(n==0&&m==0&&ch==' ')break;
        for(int i=0; i<n; i++)scanf("%s",pre[i]);
        for(int i=0; i<n; i++)scanf("%s",last[i]);
        for(int i=0; i<n; i++)for(int j=0; j<m; j++)
            {
                if(pre[i][j]==ch) tab[i][j]=last[i][j];
                else tab[i][j]=pre[i][j];
            }
        int px,py;
        int lx,ly;
        bool flag1=false;
        bool flag2=false;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!flag1&&pre[i][j]==ch)
                {
                    px=i;
                    py=j;
                    flag1=true;
                }
                if(!flag2&&last[i][j]==ch)
                {
                    lx=i;
                    ly=j;
                    flag2=true;
                }
            }
            if(flag1&&flag2)break;
        }
        if(flag1&&flag2)
        {
            int dx=lx-px;
            int dy=ly-py;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(last[i][j]==ch)
                    {
                        int nx=i+dx;
                        int ny=j+dy;
                        if(intable(nx,ny))
                            tab[nx][ny]=ch;
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
            printf("%s\n",tab[i]);
        printf("\n");
    }
    return 0;
}
