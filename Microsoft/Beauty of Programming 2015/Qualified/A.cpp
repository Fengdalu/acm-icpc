#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int cal(int x)
{
    int a = x / 400;
    int b = x / 100;
    int c = x / 4;
    return a + (c - b);
}

bool is(int x)
{
    if(x % 400 == 0) return true;
    if(x % 4 == 0 && x % 100 != 0) return true;
    return false;
}

char *mm[12] ={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

char ms[120]; int d, y;

int main()
{
    //freopen("test.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int ii = 0; ii < T; ii++)
    {
        scanf("%s %d, %d", ms, &d, &y);
        int m = 0;
        for(;;m++) if(!strcmp(mm[m], ms)) break;
        m++;
        int ans = -cal(y - 1);
        if(is(y))
            if(m >= 3) ans--;
        scanf("%s %d, %d", ms, &d, &y);
        m = 0;
        for(;;m++) if(!strcmp(mm[m], ms)) break;
        m++;
        ans += cal(y);
        if(is(y))
            if(m < 2 || (m == 2 && d < 29)) ans--;
        printf("Case #%d: %d\n", ii + 1, ans);
    }
    return 0;
}
