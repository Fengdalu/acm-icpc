#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;
int a[30];
int T;
char s[2000];
int f[30];
bool vis[30];


int find(int x)
{
    if(f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}
int main()
{
    scanf("%d", &T); 
    for(int ii = 0; ii < T; ii++)
    {
        int n;
        scanf("%d", &n);  
        memset(a, 0, sizeof a);
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < 30; i++)
            f[i] = i;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", s);
            int len = strlen(s);
            a[s[0] - 'a']++; a[s[len - 1] - 'a']--;
            f[find(s[0] - 'a')] = find(s[len - 1] - 'a');
            vis[s[0] - 'a'] = vis[s[len - 1] - 'a'] = true;
        }
        int rt = -1;
        bool flg = true;
        for(int i = 0; i < 30; i++)
        if(vis[i])
        {
           if(rt == -1) rt = find(i);
           else if(rt != find(i)) { flg = false; break; }
        }
        
        int x = 0, y = 0; 
        for(int i = 0; i < 26; i++)
        if(a[i])
        {
           if(a[i] == 1) x++;
           else if(a[i] == -1) y++;
           else { flg = false;  break; } 
        }
        if(!flg) {puts("The door cannot be opened."); continue;}
        if(x == 0 && y == 0) puts("Ordering is possible.");
        else if(x == 1 && y == 1) puts("Ordering is possible.");
        else puts("The door cannot be opened.");
    }
    return 0;
}

