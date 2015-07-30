#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool f1[100][100], f2[100][100];
char s[100];
int n, m;

int chk1(bool f1[100][100])
{
    int x = 0, y = 0, X = 0, Y = 0;
    int ans = 0;

    while(X < n)
    {
        x = X; y = Y;
        while(y < m && x < n)
        {
            if(f1[x][y] && (y == 0 || !f1[x - 1][y - 1])) ans++;
            y++; x++;
        }
        X++;
    }
    X = 0; Y = 1;
    x = X; y = Y;
    while(Y < m)
    {
        x = X; y = Y;
        while(y < m && x < n)
        {
            if(f1[x][y] && (x == 0 || !f1[x - 1][y - 1])) ans++;
            y++; x++;
        }
        Y++;
    }
    return ans;
}


int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        memset(f1, 0, sizeof f1);
        memset(f2, 0, sizeof f2);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", s);
            m = strlen(s);
            for(int j = 0; j < m; j++)
            if(s[j] == 'R') f1[i][j] = true;
            else if(s[j] == 'B') f2[i][j] = true;
            else if(s[j] == 'G') { f1[i][j] = true; f2[i][j] = true; }
        }
        for(int i = 0; i < n; i++) for(int j = 0; j < m / 2; j++)
            swap(f2[i][j], f2[i][m - j - 1]);
        /*
        cout << endl;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
        if(j != n - 1)
        {
            if(f1[i][j]) cout << "R"; else cout << ".";
        }
        else
        {
            if(f1[i][j]) cout << "R"; else cout << "."; cout << endl;
        }
        */
        // cout << chk1(f1) << endl;
        //if(chk1(f1) + chk1(f2) != 5) return -1;
        printf("%d\n", chk1(f1) + chk1(f2));
    }
    return 0;
}
